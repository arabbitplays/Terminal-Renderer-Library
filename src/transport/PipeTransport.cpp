#include <cstring>
#include <fcntl.h>
#include <stdexcept>
#include <sys/ioctl.h>
#include <terminal_renderer/transport/PipeTransport.hpp>
#include <unistd.h>

namespace TerminalRenderer
{
    PipeTransport::PipeTransport(const std::string& pipe_name, const std::string& tty_path) : ttyPath(tty_path)
    {
        pipe = std::make_shared<FifoPipe>(pipe_name);
        pipe->create();

        ttyFd = open(ttyPath.c_str(), O_RDONLY | O_NONBLOCK | O_NOCTTY);
        if (ttyFd == -1)
        {
            throw std::runtime_error("Failed to open target tty " + ttyPath + ": " + std::strerror(errno));
        }

        lastViewport = queryViewport();
    }

    PipeTransport::~PipeTransport()
    {
        if (pipe->isOpen())
        {
            pipe->closePipe();
        }
        if (ttyFd != -1)
        {
            close(ttyFd);
        }
    }

    void PipeTransport::send(const std::string& data)
    {
        if (!pipe->isOpen())
        {
            pipe->openPipe();
        }
        pipe->send(data);
    }

    Viewport PipeTransport::getViewport()
    {
        lastViewport = queryViewport();
        return lastViewport;
    }

    void PipeTransport::setResizeCallback(ResizeCallback callback)
    {
        resizeCallback = std::move(callback);
    }

    void PipeTransport::pollEvents()
    {
        const Viewport current = queryViewport();
        if (current.extent != lastViewport.extent)
        {
            lastViewport = current;
            if (resizeCallback)
            {
                resizeCallback(current);
            }
        }
    }

    Viewport PipeTransport::queryViewport() const
    {
        struct winsize ws;
        if (ioctl(ttyFd, TIOCGWINSZ, &ws) == 0)
        {
            return {{0, 0}, {ws.ws_col, ws.ws_row}};
        }
        return {{0, 0}, {0, 0}};
    }
} // namespace TerminalRenderer
