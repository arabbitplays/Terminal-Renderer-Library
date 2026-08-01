#include <iostream>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <thread>
#include <terminal_renderer/nodes/builder/SceneBuilder.hpp>
#include <terminal_renderer/nodes/container_node/BorderNode.hpp>
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
        SceneBuilder builder;
        auto layout_node = builder.horizontalLayout()
            .addChild(builder.roundedBorder()
                .setChild(builder.horizontalLayout()
                    .addChild(builder.dottedBorder().build())
                    .addChild(builder.doubleBorder().build())
                    .build())
                .build())
            .addChild(builder.heavyBorder().build())
            .build();

        for (int i = 0; ; ++i)
        {
            transport->pollEvents();
            TargetActuator actuator = getTopLevelActuator();

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
