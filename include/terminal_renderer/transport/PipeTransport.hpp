#ifndef TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
#define TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
#include <terminal_renderer/transport/FifoPipe.hpp>
#include <terminal_renderer/transport/TerminalTransport.hpp>

namespace TerminalRenderer
{
    class PipeTransport : public TerminalTransport
    {
    public:
        PipeTransport(const std::string& pipe_name, const std::string& tty_path);
        ~PipeTransport() override;

        void send(const std::string& data) override;
        Viewport getViewport() override;

        void setResizeCallback(ResizeCallback callback) override;
        void pollEvents() override;

    private:
        Viewport queryViewport() const;

        FifoPipeHandle pipe;
        std::string tty_path;
        int tty_fd = -1;

        Viewport last_viewport{};
        ResizeCallback resize_callback;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
