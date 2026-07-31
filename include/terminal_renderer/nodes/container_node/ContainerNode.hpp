#ifndef TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
#include <terminal_renderer/core/IVec2.hpp>
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <terminal_renderer/nodes/container_node/BorderCharSet.hpp>

namespace TerminalRenderer
{
    class ContainerNode : public RenderNode
    {
    public:
        ContainerNode(BorderCharSet border_char_set,
                      IVec2 margin,
                      bool draw_border,
                      IVec2 padding);

        void render(TargetActuator& targetActuator) override;
        LayoutInfo getLayoutInfo() override;

        void setChild(RenderNodeHandle child);

        BorderCharSet border_char_set;
        IVec2 margin;
        bool draw_border;
        IVec2 padding;

    private:
        void drawBorder(const TargetActuator& targetActuator) const;
        void renderChild(TargetActuator& targetActuator) const;
        [[nodiscard]] IVec2 getContentOffset() const;

        RenderNodeHandle child;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
