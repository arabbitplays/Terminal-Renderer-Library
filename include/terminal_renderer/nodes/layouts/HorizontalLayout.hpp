#ifndef TERMINAL_RENDERER_LIBRARY_HORIZONTALLAYOUT_HPP
#define TERMINAL_RENDERER_LIBRARY_HORIZONTALLAYOUT_HPP
#include <terminal_renderer/nodes/GroupNode.hpp>

namespace TerminalRenderer
{
    class HorizontalLayout : public GroupNode
    {
    public:
        void render(TargetActuator& targetActuator) override;
        std::vector<int32_t> getDistribution(IVec2 extent);
        LayoutInfo getLayoutInfo() override;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_HORIZONTALLAYOUT_HPP
