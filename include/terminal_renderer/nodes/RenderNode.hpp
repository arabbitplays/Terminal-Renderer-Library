#ifndef TERMINAL_RENDERER_LIBRARY_NODE_HPP
#define TERMINAL_RENDERER_LIBRARY_NODE_HPP
#include <terminal_renderer/nodes/LayoutInfo.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>

namespace TerminalRenderer
{
    class RenderNode
    {
    public:
        RenderNode() = default;
        virtual ~RenderNode() = default;

        virtual void render(TargetActuator& target_actuator) = 0;
        virtual LayoutInfo getLayoutInfo() = 0;
    };

    using RenderNodeHandle = std::shared_ptr<RenderNode>;
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_NODE_HPP