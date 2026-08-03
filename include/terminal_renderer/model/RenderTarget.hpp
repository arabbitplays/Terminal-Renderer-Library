#ifndef TERMINAL_RENDERER_LIBRARY_RENDERTARGET_HPP
#define TERMINAL_RENDERER_LIBRARY_RENDERTARGET_HPP
#include <memory>
#include <terminal_renderer/core/IVec2.hpp>
#include <terminal_renderer/model/Cell.hpp>
#include <vector>

namespace TerminalRenderer
{
    class RenderTarget
    {
    public:
        RenderTarget(IVec2 extent);

        void resize(IVec2 new_extent);
        Cell setCell(IVec2 pos, Cell cell);
        Cell getCell(IVec2 pos);
        [[nodiscard]] IVec2 getExtent() const;

    private:
        void initCells();
        static inline Cell createEmptyCell();

        using Cells = std::vector<std::vector<Cell>>;

        Cells cells;
        IVec2 extent;
    };

    using RenderTargetHandle = std::shared_ptr<RenderTarget>;
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_RENDERTARGET_HPP
