#ifndef TERMINAL_RENDERER_LIBRARY_TARGETACTUATOR_HPP
#define TERMINAL_RENDERER_LIBRARY_TARGETACTUATOR_HPP
#include <terminal_renderer/model/RenderTarget.hpp>
#include <terminal_renderer/model/Viewport.hpp>

namespace TerminalRenderer
{
    class TargetActuator
    {
    public:
        TargetActuator(RenderTargetHandle render_target, Viewport viewport);

        void setCell(IVec2 pos, const Cell& cell) const;
        [[nodiscard]] Cell getCell(IVec2 pos) const;

        void writeText(IVec2 pos, const std::string& text, Cell cell) const;

        [[nodiscard]] IVec2 getExtent() const;

        TargetActuator createInnerTargetActuator(Viewport inner_viewport) const;
    private:
        [[nodiscard]] IVec2 getGlobalPos(IVec2 local_pos) const;

        RenderTargetHandle render_target;
        Viewport viewport;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_TARGETACTUATOR_HPP