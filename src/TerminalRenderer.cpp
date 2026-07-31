#include <iostream>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <thread>
#include <terminal_renderer/actuator/TargetActuator.hpp>
#include <terminal_renderer/transport/StdOutTransport.hpp>

namespace TerminalRenderer
{
    TerminalRenderer::TerminalRenderer() : transport(std::make_shared<StdOutTransport>())
    {
        init();
    }

    TerminalRenderer::TerminalRenderer(const TransportHandle& transport) : transport(transport)
    {
        init();
    }

    void TerminalRenderer::render()
    {
        TargetActuator actuator = getTopLevelActuator();
        for (int i = 0; ; ++i)
        {
            transport->pollEvents();
            std::string s = "streaming char " + std::to_string(i) + "\n";
            actuator.writeText(IVec2::Zero, s, {});
            //transport->send(s);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void TerminalRenderer::init()
    {
        transport->setResizeCallback([this](const Viewport& vp)
        {
            initRenderTarget(vp.extent);
        });
        auto viewport = transport->getViewport();
        initRenderTarget(viewport.extent);
    }

    void TerminalRenderer::initRenderTarget(const IVec2& extent)
    {
        if (render_target == nullptr)
        {
            render_target = std::make_shared<RenderTarget>(extent);
        } else
        {
            render_target->resize(extent);
        }
    }

    TargetActuator TerminalRenderer::getTopLevelActuator()
    {
        return {render_target, { {0, 0}, render_target->getExtent()}};
    }
}
