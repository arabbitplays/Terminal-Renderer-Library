#include <cstdint>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>
#include <utility>
#include <terminal_renderer/nodes/text_node/TextFlowMode.hpp>

namespace TerminalRenderer
{
    TextNode::TextNode(const TextLayoutOptions layout_options) : layout_options(layout_options)
    {
    }

    void TextNode::render(TargetActuator& target_actuator)
    {
        IVec2 pos = IVec2::zero;
        for (const auto& segment : text_segments)
        {
            renderSegment(pos, segment, target_actuator);
        }
    }

    void TextNode::renderSegment(IVec2& curr_pos, const TextSegment& text_segment, TargetActuator& target_actuator)
    {
        Cell cell = {.c = 0, .fg_color = text_segment.fg_color, .bg_color = text_segment.bg_color};
        const IVec2 extent = target_actuator.getExtent();
        std::vector<std::string> lines = splitTextAt(text_segment.text, '\n');
        for (uint32_t i = 0; i < lines.size(); i++)
        {
            if (curr_pos.y >= extent.y)
            {
                return;
            }

            renderLine(curr_pos, cell, lines.at(i), target_actuator);

            if (i != lines.size() - 1)
            {
                curr_pos.y++;
                curr_pos.x = 0;
            }
        }
    }

    void TextNode::renderLine(IVec2& curr_pos, Cell& cell, const std::string& line, TargetActuator& target_actuator)
    {
        IVec2 extent = target_actuator.getExtent();
        std::vector<std::string> words = splitTextAt(line, ' ');
        for (uint32_t i = 0; i < words.size(); i++)
        {
            const std::string& word = words.at(i);
            if (layout_options.flow_mode == TextFlowMode::LINE_BREAK && curr_pos.x + word.length() > static_cast<
                uint32_t>(extent.x))
            {
                curr_pos.y++;
                curr_pos.x = 0;
            }

            if (curr_pos.y >= extent.y)
            {
                return;
            }

            renderWord(curr_pos, cell, word, target_actuator);

            if (curr_pos.x < extent.x && i != words.size() - 1)
            {
                cell.c = ' ';
                target_actuator.setCell(curr_pos, cell);
                curr_pos.x++;
            }
        }
    }

    void TextNode::renderWord(IVec2& curr_pos, Cell& cell, std::string word, TargetActuator& target_actuator)
    {
        IVec2 extent = target_actuator.getExtent();
        uint32_t curr_char_idx = 0;
        while (curr_char_idx < word.length() && curr_pos.x < extent.x)
        {
            cell.c = word.at(curr_char_idx);
            target_actuator.setCell(curr_pos, cell);
            curr_pos.x++;
            curr_char_idx++;
        }
    }

    LayoutInfo TextNode::getLayoutInfo()
    {
        return LayoutInfo{IVec2::zero, IVec2::zero, FLEXIBLE};
    }

    void TextNode::appendTextSegment(const std::string& text, const std::optional<ColorHandle>& fg_color,
                                     const std::optional<ColorHandle>& bg_color)
    {
        text_segments.emplace_back(text, fg_color, bg_color);
    }

    void TextNode::clearTextSegments()
    {
        text_segments.clear();
    }

    std::vector<std::string> TextNode::splitTextAt(const std::string& text, char c)
    {
        std::vector<std::string> result;
        size_t start = 0;
        for (size_t i = 0; i <= text.size(); ++i)
        {
            if (i == text.size() || text.at(i) == c)
            {
                result.push_back(text.substr(start, i - start));
                start = i + 1;
            }
        }
        return result;
    }
} // namespace TerminalRenderer
