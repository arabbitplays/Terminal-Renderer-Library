#include <cassert>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <utility>
#include <terminal_renderer/nodes/layouts/LayoutException.hpp>

namespace TerminalRenderer
{
    TargetActuator::TargetActuator(RenderTargetHandle render_target, const Viewport viewport)
        : render_target(std::move(render_target)), viewport(viewport)
    {
    }

    void TargetActuator::setCell(const IVec2 pos, const Cell& cell) const
    {
        render_target->setCell(getGlobalPos(pos), cell);
    }

    Cell TargetActuator::getCell(const IVec2 pos) const
    {
        return render_target->getCell(getGlobalPos(pos));
    }

    void TargetActuator::writeText(IVec2 pos, const std::string& text, Cell cell) const
    {
        for (const auto& c : text)
        {
            cell.c = c;
            setCell(pos, cell);
            pos.x++;
        }
    }

    IVec2 TargetActuator::getExtent() const
    {
        return viewport.extent;
    }

    TargetActuator TargetActuator::createInnerTargetActuator(Viewport inner_viewport) const
    {
        IVec2 max_inner_extent = viewport.extent - inner_viewport.origin;
        if (inner_viewport.extent.x > max_inner_extent.x || inner_viewport.extent.y > max_inner_extent.y)
        {
            throw LayoutException(std::format("Cannot create inner view {} from parent view {}", inner_viewport.toString(), viewport.toString()));
        }

        if (inner_viewport.extent.x <= 0 || inner_viewport.extent.y <= 0)
        {
            throw LayoutException("Inner viewport can not have 0 extent");
        }
        Viewport new_viewport = {.origin = getGlobalPos(inner_viewport.origin), .extent = inner_viewport.extent};
        return TargetActuator{render_target, new_viewport};
    }

    IVec2 TargetActuator::getGlobalPos(const IVec2 local_pos) const
    {
        assert(
            local_pos.x >= 0 && local_pos.x < viewport.extent.x && local_pos.y >= 0 && local_pos.y < viewport.extent.y);
        return viewport.origin + local_pos;
    }
} // namespace TerminalRenderer
