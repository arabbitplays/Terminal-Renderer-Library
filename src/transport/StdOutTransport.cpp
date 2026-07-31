#include <terminal_renderer/transport/StdOutTransport.hpp>

#include <csignal>
#include <iostream>
#include <sys/ioctl.h>
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
        std::cout << data;
    }

    Viewport StdOutTransport::getViewport()
    {
        struct winsize ws;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0)
        {
            return {
                {0, 0},
                {ws.ws_col, ws.ws_row}
            };
        }
        return {{0, 0}, {0, 0}};
    }

    void StdOutTransport::setResizeCallback(ResizeCallback callback)
    {
        resizeCallback = std::move(callback);
    }

    void StdOutTransport::pollEvents()
    {
        if (resized.exchange(false, std::memory_order_relaxed) && resizeCallback)
        {
            resizeCallback(getViewport());
        }
    }

    void StdOutTransport::onWinch(int)
    {
        resized.store(true, std::memory_order_relaxed);
    }
} // TerminalRenderer
