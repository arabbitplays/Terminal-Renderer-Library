#include <cstdint>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>
#include <utility>

namespace TerminalRenderer
{
    TextNode::TextNode(std::string text, std::optional<ColorHandle> fg_color, std::optional<ColorHandle> bg_color)
        : text(std::move(text)), fg_color(std::move(fg_color)), bg_color(std::move(bg_color))
    {
    }

    void TextNode::render(TargetActuator& target_actuator)
    {
        IVec2 extent = target_actuator.getExtent();
        int32_t x = 0;
        Cell cell = {.c = 0, .fg_color = fg_color, .bg_color = bg_color};
        while (x < extent.x && static_cast<uint32_t>(x) < text.size())
        {
            cell.c = text.at(x);
            target_actuator.setCell({x, 0}, cell);
            x++;
        }
    }

    LayoutInfo TextNode::getLayoutInfo()
    {
        LayoutInfo layout_info;
        layout_info.requested_size = {static_cast<int32_t>(text.size()), 1};
        layout_info.minimum_size = {};
        layout_info.scaling_mode = FLEXIBLE;
        return layout_info;
    }
} // namespace TerminalRenderer
