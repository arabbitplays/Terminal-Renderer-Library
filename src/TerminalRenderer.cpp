#include <iostream>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <thread>
#include <terminal_renderer/nodes/NodeFactory.hpp>
#include <terminal_renderer/nodes/container_node/ContainerNode.hpp>
#include <terminal_renderer/nodes/layouts/HorizontalLayout.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <terminal_renderer/transport/StdOutTransport.hpp>

namespace TerminalRenderer
{
    TerminalRenderer::TerminalRenderer() : TerminalRenderer(std::make_shared<StdOutTransport>())
    {
    }

    TerminalRenderer::TerminalRenderer(const TransportHandle& transport) : transport(transport), blitter(transport)
    {
        init();
    }

    void TerminalRenderer::render()
    {
        NodeFactory factory;
        auto layout_node = factory.createHorizontalLayout();
        auto container_node = factory.createRoundedBorder();
        auto container_node2 = factory.createHeavyBorder();
        layout_node->addChild(container_node);
        layout_node->addChild(container_node2);

        auto inner_layout_node = factory.createHorizontalLayout();
        auto inner_container_node = factory.createDottedBorder();
        auto inner_container_node2 = factory.createDoubleBorder();
        inner_layout_node->addChild(inner_container_node);
        inner_layout_node->addChild(inner_container_node2);
        container_node->setChild(inner_layout_node);

        for (int i = 0; ; ++i)
        {
            transport->pollEvents();
            TargetActuator actuator = getTopLevelActuator();
            //text_node->text = "streaming char " + std::to_string(i) + "\n";

            layout_node->render(actuator);

            blitter.blit(render_target);
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
        render_target = std::make_shared<RenderTarget>(extent);
    }

    TargetActuator TerminalRenderer::getTopLevelActuator()
    {
        return {render_target, {{0, 0}, render_target->getExtent()}};
    }
}
