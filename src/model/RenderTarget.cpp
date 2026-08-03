#include <cassert>
#include <terminal_renderer/model/RenderTarget.hpp>
#include <utility>

namespace TerminalRenderer
{
    RenderTarget::RenderTarget(IVec2 extent) : extent(extent)
    {
        initCells();
    }

    void RenderTarget::initCells()
    {
        cells.assign(extent.y, std::vector<Cell>(extent.x, createEmptyCell()));
    }

    void RenderTarget::resize(IVec2 new_extent)
    {
        if (new_extent.y < extent.y)
        {
            cells.resize(new_extent.y);
        }

        if (new_extent.x != extent.x)
        {
            for (auto& row : cells)
            {
                row.resize(new_extent.x, createEmptyCell());
            }
        }

        if (new_extent.y > extent.y)
        {
            cells.reserve(new_extent.y);
            for (int32_t y = extent.y; y < new_extent.y; ++y)
            {
                cells.emplace_back(new_extent.x, createEmptyCell());
            }
        }

        extent = new_extent;
    }

    Cell RenderTarget::setCell(IVec2 pos, Cell cell)
    {
        assert(pos.x >= 0 && pos.x < extent.x && pos.y >= 0 && pos.y < extent.y);
        return cells[pos.y][pos.x] = std::move(cell);
    }

    Cell RenderTarget::getCell(const IVec2 pos)
    {
        assert(pos.x >= 0 && pos.x < extent.x && pos.y >= 0 && pos.y < extent.y);
        return cells[pos.y][pos.x];
    }

    IVec2 RenderTarget::getExtent() const
    {
        return extent;
    }

    Cell RenderTarget::createEmptyCell()
    {
        return {};
    }
} // namespace TerminalRenderer
