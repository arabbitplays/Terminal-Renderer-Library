#ifndef TERMINAL_RENDERER_LIBRARY_BORDERNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_BORDERNODE_HPP
#include <terminal_renderer/core/IVec2.hpp>
#include <terminal_renderer/nodes/border_node/BorderCharSet.hpp>
#include <terminal_renderer/nodes/border_node/ContainerLayoutOptions.hpp>
#include <terminal_renderer/nodes/ContainerNode.hpp>

namespace TerminalRenderer
{
    class BorderNode : public ContainerNode
    {
    public:
        BorderNode(BorderCharSet border_char_set, IVec2 margin, bool draw_border, IVec2 padding,
            ContainerLayoutOptions layout_options);

        void render(TargetActuator& target_actuator) override;
        LayoutInfo getLayoutInfo() override;

        BorderCharSet border_char_set;
        IVec2 margin;
        bool draw_border;
        IVec2 padding;
        ContainerLayoutOptions layout_options;

    private:
        void drawBorder(const TargetActuator& target_actuator) const;
        void renderChild(TargetActuator& target_actuator) const;
        [[nodiscard]] IVec2 getContentOffset() const;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_BORDERNODE_HPP
