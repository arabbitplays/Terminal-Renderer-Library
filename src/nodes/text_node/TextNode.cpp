#include <terminal_renderer/nodes/text_node/TextNode.hpp>

namespace TerminalRenderer
{
    TextNode::TextNode(const std::shared_ptr<TextNodeConfig>& config) : RenderNode(), config(config)
    {
    }

    void TextNode::render(TargetActuator& targetActuator)
    {
        IVec2 extent = targetActuator.getExtent();
        int32_t x = 0;
        Cell cell = {0, config->fg_color, config->bg_color};
        while (x < extent.x && x < config->text.size())
        {
            cell.c = config->text.at(x);
            targetActuator.setCell({x, 0}, cell);
            x++;
        }
    }

    LayoutInfo TextNode::getLayoutInfo()
    {
        LayoutInfo layoutInfo;
        layoutInfo.requestedSize = { static_cast<int32_t>(config->text.size()), 1};
        return layoutInfo;
    }
} // TerminalRenderer