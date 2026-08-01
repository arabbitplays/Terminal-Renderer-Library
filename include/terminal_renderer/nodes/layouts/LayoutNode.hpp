#ifndef TERMINAL_RENDERER_LIBRARY_LAYOUTNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_LAYOUTNODE_HPP
#include <terminal_renderer/nodes/GroupNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutUtil.hpp>

namespace TerminalRenderer
{
    class LayoutNode : public GroupNode
    {
    public:
        explicit LayoutNode(Axis axis) : axis(axis) {}

        void render(TargetActuator& targetActuator) override;
        LayoutInfo getLayoutInfo() override;

        Axis axis;

    private:
        std::vector<int32_t> getDistribution(IVec2 extent) const;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_LAYOUTNODE_HPP
