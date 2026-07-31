#ifndef TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <terminal_renderer/nodes/container_node/ContainerNodeConfig.hpp>

namespace TerminalRenderer
{
    class ContainerNode : public RenderNode
    {
    public:
        explicit ContainerNode(const std::shared_ptr<ContainerNodeConfig>& config);

        void render(TargetActuator& targetActuator) override;
        LayoutInfo getLayoutInfo() override;

    private:
        void drawBorder(const TargetActuator& targetActuator) const;
        void renderChild(TargetActuator& targetActuator) const;
        [[nodiscard]] IVec2 getContentOffset() const;

    private:
        std::shared_ptr<ContainerNodeConfig> config;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_CONTAINERNODE_HPP