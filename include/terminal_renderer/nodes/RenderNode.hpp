#ifndef TERMINAL_RENDERER_LIBRARY_NODE_HPP
#define TERMINAL_RENDERER_LIBRARY_NODE_HPP
#include <terminal_renderer/nodes/LayoutInfo.hpp>
#include <terminal_renderer/rendering/TargetActuator.hpp>

namespace TerminalRenderer
{
    class RenderNode
    {
    public:
        RenderNode() {};
        virtual ~RenderNode() = default;

        virtual void render(TargetActuator& targetActuator) = 0;
        virtual LayoutInfo getLayoutInfo() = 0;
    };

    typedef std::shared_ptr<RenderNode> RenderNodeHandle;
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_NODE_HPP