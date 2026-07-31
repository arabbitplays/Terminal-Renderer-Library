#include <iostream>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <thread>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <terminal_renderer/transport/StdOutTransport.hpp>

namespace TerminalRenderer
{
    TerminalRenderer::TerminalRenderer() : TerminalRenderer(std::make_shared<StdOutTransport>()) { }

    TerminalRenderer::TerminalRenderer(const TransportHandle& transport) : transport(transport), blitter(transport)
    {
        init();
    }

    void TerminalRenderer::render()
    {
        TargetActuator actuator = getTopLevelActuator();
        auto text_config = std::make_shared<TextNodeConfig>();
        auto node = std::make_shared<TextNode>(text_config);
        for (int i = 0; ; ++i)
        {
            transport->pollEvents();
            std::string s = "streaming char " + std::to_string(i) + "\n";
            text_config->text = s;

            node->render(actuator);

            blitter.blit(render_target);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
