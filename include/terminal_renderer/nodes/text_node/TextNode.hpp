#ifndef TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#include <cstdint>
#include <optional>
#include <string>
#include <terminal_renderer/nodes/LeafNode.hpp>
#include <terminal_renderer/nodes/text_node/TextFlowMode.hpp>

namespace TerminalRenderer
{
    class TextNode : public LeafNode
    {
    public:
        TextNode(std::string text, std::optional<ColorHandle> fg_color, std::optional<ColorHandle> bg_color, TextFlowMode flow_mode);

        void render(TargetActuator& target_actuator) override;
        LayoutInfo getLayoutInfo() override;

    private:
        void renderLine(const std::string& line, int32_t y, const TargetActuator& target_actuator) const;
        static std::vector<std::string> applyLineBreaks(const std::string& line, IVec2 extent);
        static std::vector<std::string> splitToLines(const std::string& text, bool apply_line_breaks, IVec2 extent);

    public:
        std::string text;
        std::optional<ColorHandle> fg_color;
        std::optional<ColorHandle> bg_color;
        TextFlowMode flow_mode;

    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
