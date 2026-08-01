#ifndef TERMINAL_RENDERER_LIBRARY_HORIZONTALLAYOUT_HPP
#define TERMINAL_RENDERER_LIBRARY_HORIZONTALLAYOUT_HPP
#include <terminal_renderer/nodes/RenderNode.hpp>

namespace TerminalRenderer
{
    class HorizontalLayout : public RenderNode
    {
    public:
        HorizontalLayout() : RenderNode() {}

        void render(TargetActuator& targetActuator) override;
        std::vector<int32_t> getDistribution(IVec2 extent);
        LayoutInfo getLayoutInfo() override;

        void addChild(RenderNodeHandle child);
    private:
        std::vector<RenderNodeHandle> children;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_HORIZONTALLAYOUT_HPP