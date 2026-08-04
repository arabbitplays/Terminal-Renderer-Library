#ifndef TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
#include <terminal_renderer/nodes/RenderNode.hpp>

namespace TerminalRenderer
{
    class ContainerNode : public RenderNode
    {
    public:
        void setChild(RenderNodeHandle new_child)
        {
            child = std::move(new_child);
        }

        [[nodiscard]] const RenderNodeHandle& getChild() const
        {
            return child;
        }

    protected:
        RenderNodeHandle child;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
