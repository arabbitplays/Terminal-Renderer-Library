#ifndef TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
#define TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
#include "FifoPipe.hpp"
#include "TerminalTransport.hpp"

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
        std::string ttyPath;
        int ttyFd = -1;

        Viewport lastViewport{};
        ResizeCallback resizeCallback;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
