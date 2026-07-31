#include <terminal_renderer/nodes/text_node/TextNode.hpp>

#include <utility>

namespace TerminalRenderer
{
    TextNode::TextNode(std::string text, uint32_t fg_color, uint32_t bg_color)
        : text(std::move(text)), fg_color(fg_color), bg_color(bg_color)
    {
    }

    void TextNode::render(TargetActuator& targetActuator)
    {
        IVec2 extent = targetActuator.getExtent();
        int32_t x = 0;
        Cell cell = {0, fg_color, bg_color};
        while (x < extent.x && x < text.size())
        {
            cell.c = text.at(x);
            targetActuator.setCell({x, 0}, cell);
            x++;
        }
    }

    LayoutInfo TextNode::getLayoutInfo()
    {
        LayoutInfo layoutInfo;
        layoutInfo.requestedSize = { static_cast<int32_t>(text.size()), 1};
        return layoutInfo;
    }
} // TerminalRenderer
