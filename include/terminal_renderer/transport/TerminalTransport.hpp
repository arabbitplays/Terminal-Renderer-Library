#ifndef TERMINAL_RENDERER_LIBRARY_TERMINALTRANSPORT_HPP
#define TERMINAL_RENDERER_LIBRARY_TERMINALTRANSPORT_HPP
#include <functional>
#include <memory>
#include <terminal_renderer/model/Viewport.hpp>

namespace TerminalRenderer
{
    using ResizeCallback = std::function<void(const Viewport&)>;

    class TerminalTransport
    {
    public:
        virtual ~TerminalTransport() = default;

        virtual void send(const std::string& data) = 0;
        virtual Viewport getViewport() = 0;

        virtual void setResizeCallback(ResizeCallback callback) = 0;
        virtual void pollEvents() = 0;
    };

    typedef std::shared_ptr<TerminalTransport> TransportHandle;
} // namespace TerminalRenderer
#endif // TERMINAL_RENDERER_LIBRARY_TERMINALTRANSPORT_HPP
