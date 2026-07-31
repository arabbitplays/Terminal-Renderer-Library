#ifndef TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#include <cstdint>
#include <string>
#include <terminal_renderer/nodes/RenderNode.hpp>

namespace TerminalRenderer
{
    class TextNode : public RenderNode
    {
    public:
        TextNode(std::string text, uint32_t fg_color, uint32_t bg_color);

        void render(TargetActuator& targetActuator) override;
        LayoutInfo getLayoutInfo() override;

        std::string text;
        uint32_t fg_color;
        uint32_t bg_color;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
