#ifndef YAKSHA_TERMINALRENDERER_HPP
#define YAKSHA_TERMINALRENDERER_HPP
#include "transport/TerminalTransport.hpp"

#include <memory>
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <terminal_renderer/model/RenderTarget.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <terminal_renderer/rendering/TargetBlitter.hpp>

#include "widgets/Widget.hpp"

namespace TerminalRenderer
{
    class TerminalRenderer
    {
    public:
        explicit TerminalRenderer(const TransportHandle& transport);
        ~TerminalRenderer() = default;

        void render();
        void setRootNode(const RenderNodeHandle& root_node);

    private:
        void init();
        void initRenderTarget(const IVec2& extent);
        TargetActuator getTopLevelActuator();

        void updateWidgets() const;
        void collectWidgets(const RenderNodeHandle& node);

        TransportHandle transport;
        TargetBlitter blitter;

        RenderTargetHandle render_target;

        RenderNodeHandle root_node;
        std::vector<WidgetHandle> widgets;
    };

    using RendererHandle = std::shared_ptr<TerminalRenderer>;
} // namespace TerminalRenderer

#endif // YAKSHA_TERMINALRENDERER_HPP
