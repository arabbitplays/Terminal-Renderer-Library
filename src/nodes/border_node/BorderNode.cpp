#include <terminal_renderer/nodes/border_node/BorderNode.hpp>
#include <utility>

namespace TerminalRenderer
{
    BorderNode::BorderNode(BorderCharSet border_char_set, IVec2 margin, bool draw_border, IVec2 padding, ContainerLayoutOptions layout_options)
        : border_char_set(border_char_set), margin(margin), draw_border(draw_border), padding(padding), layout_options(layout_options)
    {
    }

    void BorderNode::render(TargetActuator& target_actuator)
    {
        IVec2 extent = target_actuator.getExtent();
        IVec2 content_offset = getContentOffset();
        IVec2 inner_extent = extent - 2 * content_offset;
        if (inner_extent.x < 0 || inner_extent.y < 0)
        {
            return;
        }

        if (!draw_border && margin == IVec2::zero && padding == IVec2::zero)
        {
            renderChild(target_actuator);
            return;
        }

        if (draw_border)
        {
            drawBorder(target_actuator);
        }

        const Viewport inner_viewport = {.origin = content_offset, .extent = inner_extent};

        TargetActuator inner_actuator = target_actuator.createInnerTargetActuator(inner_viewport);
        renderChild(inner_actuator);
    }

    LayoutInfo BorderNode::getLayoutInfo()
    {
        LayoutInfo child_layout_info = child != nullptr ? child->getLayoutInfo() : LayoutInfo();
        IVec2 offset = 2 * getContentOffset();
        IVec2 requested = max(child_layout_info.getRequestedSize() + offset, layout_options.min_extent);

        if (layout_options.scaling_mode == STATIC)
        {
            return LayoutInfo::createStatic(requested);
        }
        return LayoutInfo::createFlexible(
            requested,
            max(child_layout_info.getMinimumSize() + offset, layout_options.min_extent)
        );
    }

    void BorderNode::drawBorder(const TargetActuator& target_actuator) const
    {
        IVec2 start = margin;
        IVec2 extent = target_actuator.getExtent() - 2 * margin;

        if (extent.x < 2 || extent.y < 2)
        {
            return;
        }

        Cell cell{.c = 0, .fg_color = std::nullopt, .bg_color = std::nullopt};

        cell.c = border_char_set.top_left;
        target_actuator.setCell(start, cell);
        cell.c = border_char_set.top_right;
        target_actuator.setCell(start + IVec2{extent.x - 1, 0}, cell);
        cell.c = border_char_set.bottom_left;
        target_actuator.setCell(start + IVec2{0, extent.y - 1}, cell);
        cell.c = border_char_set.bottom_right;
        target_actuator.setCell(start + IVec2{extent.x - 1, extent.y - 1}, cell);

        cell.c = border_char_set.horizontal;
        for (int32_t i = 1; i < extent.x - 1; ++i)
        {
            target_actuator.setCell({start.x + i, start.y}, cell);
            target_actuator.setCell({start.x + i, start.y + extent.y - 1}, cell);
        }

        cell.c = border_char_set.vertical;
        for (int32_t i = 1; i < extent.y - 1; ++i)
        {
            target_actuator.setCell({start.x, start.y + i}, cell);
            target_actuator.setCell({start.x + extent.x - 1, start.y + i}, cell);
        }
    }

    void BorderNode::renderChild(TargetActuator& target_actuator) const
    {
        if (child == nullptr)
        {
            return;
        }
        child->render(target_actuator);
    }

    IVec2 BorderNode::getContentOffset() const
    {
        IVec2 content_offset = margin + padding;
        if (draw_border)
        {
            content_offset += IVec2{1, 1};
        }
        return content_offset;
    }
} // namespace TerminalRenderer
