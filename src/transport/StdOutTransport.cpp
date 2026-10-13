#include <csignal>
#include <iostream>
#include <poll.h>
#include <sys/ioctl.h>
#include <terminal_renderer/transport/StdOutTransport.hpp>
#include <unistd.h>

namespace TerminalRenderer
{
    std::atomic<bool> StdOutTransport::resized{false};

    StdOutTransport::StdOutTransport()
    {
        std::signal(SIGWINCH, &StdOutTransport::onWinch);

        // set terminal attributes for rendering
        tcgetattr(STDIN_FILENO, &original_terminal_attributes);
        termios raw = original_terminal_attributes;
        raw.c_lflag &= ~(ICANON | ECHO); // no line buffering, no echo
        raw.c_cc[VMIN] = 1;              // block until at least 1 byte
        raw.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }

    StdOutTransport::~StdOutTransport()
    {
        std::signal(SIGWINCH, SIG_DFL);

        // restore terminal attributes
        tcsetattr(STDIN_FILENO, TCSANOW, &original_terminal_attributes);
    }

    void StdOutTransport::send(const std::string& data)
    {
        std::cout << data << std::flush;
    }

    Viewport StdOutTransport::getViewport()
    {
        struct winsize ws;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0)
        {
            return {.origin = {0, 0}, .extent = {ws.ws_col, ws.ws_row}};
        }
        return {.origin = {0, 0}, .extent = {0, 0}};
    }

    void StdOutTransport::setResizeCallback(ResizeCallback callback)
    {
        resize_callback = std::move(callback);
    }

    void StdOutTransport::pollEvents()
    {
        if (resized.exchange(false, std::memory_order_relaxed) && resize_callback)
        {
            resize_callback(getViewport());
        }
    }

    void StdOutTransport::onWinch(int /*unused*/)
    {
        resized.store(true, std::memory_order_relaxed);
    }

    int StdOutTransport::readKey()
    {
        pollfd pfd{STDIN_FILENO, POLLIN, 0};

        int timeoutMs = 1;

        int ready = poll(&pfd, 1, timeoutMs); // 0 = return immediately
        if (ready <= 0 || !(pfd.revents & POLLIN))
            return -1; // nothing pressed (or error/EINTR)

        unsigned char c;
        if (read(STDIN_FILENO, &c, 1) == 1)
            return c;
        return -1; // EOF or read error
    }
} // namespace TerminalRenderer
