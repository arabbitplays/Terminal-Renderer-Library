#ifndef TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <terminal_renderer/nodes/text_node/TextNodeConfig.hpp>

namespace TerminalRenderer
{
    class TextNode : public RenderNode
    {
    public:
        explicit TextNode(const std::shared_ptr<TextNodeConfig>& config);

        void render(TargetActuator& targetActuator) override;
        LayoutInfo getLayoutInfo() override;

    private:
        std::shared_ptr<TextNodeConfig> config;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP