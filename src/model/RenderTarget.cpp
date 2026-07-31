#include <cassert>
#include <terminal_renderer/model/RenderTarget.hpp>

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

    void RenderTarget::resize(IVec2 newExtent)
    {
        if (newExtent.y < extent.y)
        {
            cells.resize(newExtent.y);
        }

        if (newExtent.x != extent.x)
        {
            for (auto& row : cells)
            {
                row.resize(newExtent.x, createEmptyCell());
            }
        }

        if (newExtent.y > extent.y)
        {
            cells.reserve(newExtent.y);
            for (int32_t y = extent.y; y < newExtent.y; ++y)
            {
                cells.emplace_back(newExtent.x, createEmptyCell());
            }
        }

        extent = newExtent;
    }

    Cell RenderTarget::setCell(IVec2 pos, Cell cell)
    {
        assert(pos.x >= 0 && pos.x < extent.x && pos.y >= 0 && pos.y < extent.y);
        return cells[pos.y][pos.x] = cell;
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
} // TerminalRenderer
