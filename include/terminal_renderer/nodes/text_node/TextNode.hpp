#ifndef TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#include <cstdint>
#include <optional>
#include <string>
#include <terminal_renderer/nodes/LeafNode.hpp>

namespace TerminalRenderer
{
    class TextNode : public LeafNode
    {
    public:
        TextNode(std::string text, std::optional<ColorHandle> fg_color, std::optional<ColorHandle> bg_color);

        void render(TargetActuator& target_actuator) override;
        LayoutInfo getLayoutInfo() override;

        std::string text;
        std::optional<ColorHandle> fg_color;
        std::optional<ColorHandle> bg_color;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
