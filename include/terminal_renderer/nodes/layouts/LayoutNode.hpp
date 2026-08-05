#ifndef TERMINAL_RENDERER_LIBRARY_LAYOUTNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_LAYOUTNODE_HPP
#include <terminal_renderer/nodes/GroupNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutUtil.hpp>

namespace TerminalRenderer
{
    class LayoutNode : public GroupNode
    {
    public:
        explicit LayoutNode(Axis axis) : axis(axis)
        {
        }

        void render(TargetActuator& target_actuator) override;
        LayoutInfo getLayoutInfo() override;

        Axis axis;

    private:
        std::vector<uint32_t> getDistribution(IVec2 extent) const;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_LAYOUTNODE_HPP
