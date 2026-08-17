#ifndef TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
#include <cstdint>
#include <optional>
#include <string>
#include <terminal_renderer/nodes/LeafNode.hpp>
#include <terminal_renderer/nodes/text_node/TextFlowMode.hpp>
#include <terminal_renderer/nodes/text_node/TextLayoutOptions.hpp>
#include <terminal_renderer/nodes/text_node/TextSegment.hpp>

namespace TerminalRenderer
{
    class TextNode : public LeafNode
    {
    public:
        TextNode(TextLayoutOptions layout_options);

        void render(TargetActuator& target_actuator) override;
        LayoutInfo getLayoutInfo() override;

        void appendTextSegment(const std::string& text, const std::optional<ColorHandle>& fg_color = std::nullopt,
            const std::optional<ColorHandle>& bg_color = std::nullopt);
        void clearTextSegments();

        TextLayoutOptions layout_options;

    private:
        void renderSegment(IVec2& curr_pos, const TextSegment& text_segment, TargetActuator& target_actuator);
        void renderLine(IVec2& curr_pos, Cell& cell, const std::string& line, TargetActuator& target_actuator) const;
        static void renderWord(IVec2& curr_pos, Cell& cell, std::string word, TargetActuator& target_actuator);

        void clearView(TargetActuator& target_actuator);

        static std::vector<std::string> splitTextAt(const std::string& text, char c);
        IVec2 getStaticExtent();

        std::vector<TextSegment> text_segments;
        bool clear_view = false;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_TEXTNODE_HPP
