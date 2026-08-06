#include <terminal_renderer/nodes/border_node/BorderNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <terminal_renderer/transport/StdOutTransport.hpp>

namespace TerminalRenderer
{
    TerminalRenderer::TerminalRenderer(const TransportHandle& transport) : transport(transport), blitter(transport)
    {
        init();
    }

    void TerminalRenderer::render()
    {
        transport->pollEvents();
        TargetActuator actuator = getTopLevelActuator();

        updateWidgets();
        root_node->render(actuator);

        blitter.blit(render_target);
    }

    void TerminalRenderer::setRootNode(const RenderNodeHandle& root_node)
    {
        this->root_node = root_node;
        collectWidgets(root_node);
    }

    void TerminalRenderer::init()
    {
        transport->setResizeCallback([this](const Viewport& vp) { initRenderTarget(vp.extent); });
        auto viewport = transport->getViewport();
        initRenderTarget(viewport.extent);
    }

    void TerminalRenderer::initRenderTarget(const IVec2& extent)
    {
        render_target = std::make_shared<RenderTarget>(extent);
    }

    TargetActuator TerminalRenderer::getTopLevelActuator()
    {
        return {render_target, {.origin = {0, 0}, .extent = render_target->getExtent()}};
    }

    void TerminalRenderer::updateWidgets() const
    {
        for (const auto& widget : widgets)
        {
            widget->onUpdate();
        }
    }

    void TerminalRenderer::collectWidgets(const RenderNodeHandle& node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (const auto widget = std::dynamic_pointer_cast<Widget>(node))
        {
            widgets.push_back(widget);
            collectWidgets(widget->getRoot());
            return;
        }

        if (const auto container = std::dynamic_pointer_cast<ContainerNode>(node))
        {
            collectWidgets(container->getChild());
            return;
        }

        if (const auto group = std::dynamic_pointer_cast<GroupNode>(node))
        {
            for (const auto& child : group->getChildren())
            {
                collectWidgets(child);
            }
            return;
        }
    }
} // namespace TerminalRenderer
