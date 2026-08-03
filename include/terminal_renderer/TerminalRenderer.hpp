#ifndef YAKSHA_TERMINALRENDERER_HPP
#define YAKSHA_TERMINALRENDERER_HPP
#include "transport/TerminalTransport.hpp"

#include <memory>
#include <string>
#include <terminal_renderer/model/RenderTarget.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <terminal_renderer/rendering/TargetBlitter.hpp>

namespace TerminalRenderer
{
    class TerminalRenderer
    {
    public:
        TerminalRenderer();
        explicit TerminalRenderer(const TransportHandle& transport);
        ~TerminalRenderer() = default;

        void render();

    private:
        void init();
        void initRenderTarget(const IVec2& extent);
        TargetActuator getTopLevelActuator();

        TransportHandle transport;
        TargetBlitter blitter;

        RenderTargetHandle render_target;
    };

    typedef std::shared_ptr<TerminalRenderer> RendererHandle;
} // namespace TerminalRenderer

#endif // YAKSHA_TERMINALRENDERER_HPP
