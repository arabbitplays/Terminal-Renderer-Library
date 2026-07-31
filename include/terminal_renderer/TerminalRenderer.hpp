#ifndef YAKSHA_TERMINALRENDERER_HPP
#define YAKSHA_TERMINALRENDERER_HPP
#include <memory>
#include <string>
#include <terminal_renderer/actuator/TargetActuator.hpp>
#include <terminal_renderer/model/RenderTarget.hpp>

#include "transport/TerminalTransport.hpp"


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

        RenderTargetHandle render_target;
    };

    typedef std::shared_ptr<TerminalRenderer> RendererHandle;
}


#endif //YAKSHA_TERMINALRENDERER_HPP
