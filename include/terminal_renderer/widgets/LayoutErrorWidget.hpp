#ifndef TERMINAL_RENDERER_LIBRARY_LAYOUTERRORWIDGET_HPP
#define TERMINAL_RENDERER_LIBRARY_LAYOUTERRORWIDGET_HPP
#include "Widget.hpp"
#include "terminal_renderer/nodes/text_node/TextNode.hpp"

namespace TerminalRenderer
{
    class LayoutErrorWidget : public Widget
    {
    public:
        LayoutErrorWidget();
        ~LayoutErrorWidget() override = default;
        void onUpdate() override;

    private:
        std::shared_ptr<TextNode> error_text;
        bool updated = false;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_LAYOUTERRORWIDGET_HPP