#include <cstring>
#include <fcntl.h>
#include <stdexcept>
#include <sys/ioctl.h>
#include <terminal_renderer/transport/PipeTransport.hpp>
#include <unistd.h>

namespace TerminalRenderer
{
    PipeTransport::PipeTransport(const std::string& pipe_name, const std::string& tty_path) : tty_path(tty_path)
    {
        pipe = std::make_shared<FifoPipe>(pipe_name);
        pipe->create();

        tty_fd = open(tty_path.c_str(), O_RDONLY | O_NONBLOCK | O_NOCTTY);
        if (tty_fd == -1)
        {
            throw std::runtime_error("Failed to open target tty " + tty_path + ": " + std::strerror(errno));
        }

        last_viewport = queryViewport();
    }

    PipeTransport::~PipeTransport()
    {
        if (pipe->isOpen())
        {
            pipe->closePipe();
        }
        if (tty_fd != -1)
        {
            close(tty_fd);
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
        last_viewport = queryViewport();
        return last_viewport;
    }

    void PipeTransport::setResizeCallback(ResizeCallback callback)
    {
        resize_callback = std::move(callback);
    }

    void PipeTransport::pollEvents()
    {
        const Viewport current = queryViewport();
        if (current.extent != last_viewport.extent)
        {
            last_viewport = current;
            if (resize_callback)
            {
                resize_callback(current);
            }
        }
    }

    Viewport PipeTransport::queryViewport() const
    {
        struct winsize ws;
        if (ioctl(tty_fd, TIOCGWINSZ, &ws) == 0)
        {
            return {.origin = {0, 0}, .extent = {ws.ws_col, ws.ws_row}};
        }
        return {.origin = {0, 0}, .extent = {0, 0}};
    }
} // namespace TerminalRenderer
