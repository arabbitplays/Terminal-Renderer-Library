#include <csignal>
#include <iostream>
#include <sys/ioctl.h>
#include <terminal_renderer/transport/StdOutTransport.hpp>
#include <unistd.h>

namespace TerminalRenderer
{
    std::atomic<bool> StdOutTransport::resized{false};

    StdOutTransport::StdOutTransport()
    {
        std::signal(SIGWINCH, &StdOutTransport::onWinch);
    }

    StdOutTransport::~StdOutTransport()
    {
        std::signal(SIGWINCH, SIG_DFL);
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
} // namespace TerminalRenderer
