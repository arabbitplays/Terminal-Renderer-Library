#include <cassert>
#include <terminal_renderer/rendering/TargetActuator.hpp>
#include <utility>

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
        Viewport new_viewport = {getGlobalPos(inner_viewport.origin), inner_viewport.extent};
        return TargetActuator{render_target, new_viewport};
    }

    IVec2 TargetActuator::getGlobalPos(const IVec2 local_pos) const
    {
        assert(
            local_pos.x >= 0 && local_pos.x < viewport.extent.x && local_pos.y >= 0 && local_pos.y < viewport.extent.y);
        return viewport.origin + local_pos;
    }
} // namespace TerminalRenderer
