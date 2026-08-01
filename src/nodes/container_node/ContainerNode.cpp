#include <terminal_renderer/nodes/container_node/ContainerNode.hpp>

#include <utility>

namespace TerminalRenderer
{
    ContainerNode::ContainerNode(BorderCharSet border_char_set,
                                 IVec2 margin,
                                 bool draw_border,
                                 IVec2 padding)
        : border_char_set(std::move(border_char_set)),
          margin(margin),
          draw_border(draw_border),
          padding(padding)
    {
    }

    void ContainerNode::render(TargetActuator& targetActuator)
    {
        IVec2 extent = targetActuator.getExtent();
        IVec2 content_offset = getContentOffset();
        IVec2 inner_extent = extent - 2 * content_offset;
        if (inner_extent.x < 0 || inner_extent.y < 0)
        {
            return;
        }

        if (!draw_border && margin == IVec2::Zero && padding == IVec2::Zero)
        {
            renderChild(targetActuator);
            return;
        }

        if (draw_border)
        {
            drawBorder(targetActuator);
        }

        const Viewport inner_viewport = { content_offset, inner_extent };

        TargetActuator innerActuator = targetActuator.createInnerTargetActuator(inner_viewport);
        renderChild(innerActuator);
    }

    LayoutInfo ContainerNode::getLayoutInfo()
    {
        LayoutInfo childLayoutInfo = child != nullptr ? child->getLayoutInfo() : LayoutInfo();
        LayoutInfo layout_info;
        layout_info.requestedSize = childLayoutInfo.requestedSize + 2 * getContentOffset();
        layout_info.minimumSize = 2 * getContentOffset();
        layout_info.scaling_mode = FLEXIBLE;
        return layout_info;
    }

    void ContainerNode::setChild(RenderNodeHandle child)
    {
        this->child = std::move(child);
    }

    void ContainerNode::drawBorder(const TargetActuator& targetActuator) const
    {
        IVec2 start = margin;
        IVec2 extent = targetActuator.getExtent() - 2 * margin;

        if (extent.x < 2 || extent.y < 2)
        {
            return;
        }

        Cell cell{0, 0 , 0};

        cell.c = border_char_set.top_left;
        targetActuator.setCell(start, cell);
        cell.c = border_char_set.top_right;
        targetActuator.setCell(start + IVec2{extent.x - 1, 0}, cell);
        cell.c = border_char_set.bottom_left;
        targetActuator.setCell(start + IVec2{0, extent.y - 1}, cell);
        cell.c = border_char_set.bottom_right;
        targetActuator.setCell(start + IVec2{extent.x - 1, extent.y - 1}, cell);

        cell.c = border_char_set.horizontal;
        for (int32_t i = 1; i < extent.x - 1; ++i)
        {
            targetActuator.setCell({start.x + i, start.y}, cell);
            targetActuator.setCell({start.x + i, start.y + extent.y - 1}, cell);
        }

        cell.c = border_char_set.vertical;
        for (int32_t i = 1; i < extent.y - 1; ++i)
        {
            targetActuator.setCell({start.x,                start.y + i}, cell);
            targetActuator.setCell({start.x + extent.x - 1, start.y + i}, cell);
        }
    }

    void ContainerNode::renderChild(TargetActuator& targetActuator) const
    {
        if (child == nullptr)
        {
            return;
        }
        child->render(targetActuator);
    }

    IVec2 ContainerNode::getContentOffset() const
    {
        IVec2 content_offset = margin + padding;
        if (draw_border)
        {
            content_offset += IVec2{1, 1};
        }
        return content_offset;
    }
} // TerminalRenderer
