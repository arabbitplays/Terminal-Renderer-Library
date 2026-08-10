#ifndef YAKSHA_TERMINALRENDERER_HPP
#define YAKSHA_TERMINALRENDERER_HPP
#include <memory>
#include <terminal_renderer/model/RenderTarget.hpp>
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <terminal_renderer/rendering/TargetBlitter.hpp>
#include <terminal_renderer/transport/TerminalTransport.hpp>
#include <terminal_renderer/widgets/Widget.hpp>

#include "widgets/LayoutErrorWidget.hpp"

namespace TerminalRenderer
{
    class TerminalRenderer
    {
    public:
        explicit TerminalRenderer(const TransportHandle& transport);
        ~TerminalRenderer() = default;

        void start();
        void render();
        void setRootNode(const RenderNodeHandle& root_node);

    private:
        void init();
        void initRenderTarget(const IVec2& extent);
        TargetActuator getTopLevelActuator();

        void startWidgets() const;
        void updateWidgets() const;
        void collectWidgets(const RenderNodeHandle& node);

        TransportHandle transport;
        TargetBlitter blitter;

        RenderTargetHandle render_target;

        RenderNodeHandle root_node;
        std::vector<WidgetHandle> widgets;

        std::shared_ptr<LayoutErrorWidget> layout_error_widget;
    };

    using RendererHandle = std::shared_ptr<TerminalRenderer>;
} // namespace TerminalRenderer

#endif // YAKSHA_TERMINALRENDERER_HPP
