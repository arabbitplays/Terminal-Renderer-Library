#include <cstdint>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>
#include <utility>
#include <terminal_renderer/nodes/text_node/TextFlowMode.hpp>

namespace TerminalRenderer
{
    TextNode::TextNode(std::string text, std::optional<ColorHandle> fg_color, std::optional<ColorHandle> bg_color,
                       TextFlowMode flow_mode)
        : text(std::move(text)), fg_color(std::move(fg_color)), bg_color(std::move(bg_color)), flow_mode(flow_mode)
    {
    }

    void TextNode::render(TargetActuator& target_actuator)
    {
        std::vector<std::string> lines = splitToLines(text, flow_mode == TextFlowMode::LINE_BREAK,
                                                      target_actuator.getExtent());
        for (size_t y = 0; y < lines.size(); y++)
        {
            renderLine(lines.at(y), static_cast<int32_t>(y), target_actuator);
        }
    }

    LayoutInfo TextNode::getLayoutInfo()
    {
        ScalingMode scaling_mode = flow_mode == TextFlowMode::STATIC ? STATIC : FLEXIBLE;
        return LayoutInfo{{static_cast<int32_t>(text.size()), 1}, {}, scaling_mode};
    }

    void TextNode::renderLine(const std::string& line, int32_t y, const TargetActuator& target_actuator) const
    {
        IVec2 extent = target_actuator.getExtent();
        int32_t x = 0;
        Cell cell = {.c = 0, .fg_color = fg_color, .bg_color = bg_color};
        while (x < extent.x && static_cast<uint32_t>(x) < line.size())
        {
            cell.c = line.at(x);
            target_actuator.setCell({x, y}, cell);
            x++;
        }
    }

    std::vector<std::string> TextNode::splitToLines(const std::string& text, bool apply_line_breaks, const IVec2 extent)
    {
        std::vector<std::string> lines;
        size_t start = 0;
        for (size_t i = 0; i <= text.size(); ++i)
        {
            if (i == text.size() || text.at(i) == '\n')
            {
                std::string line = text.substr(start, i - start);
                if (apply_line_breaks && !line.empty())
                {
                    std::vector<std::string> broken_lines = applyLineBreaks(line, extent);
                    lines.insert(lines.end(), broken_lines.begin(), broken_lines.end());
                }
                else
                {
                    lines.push_back(line);
                }
                start = i + 1;
            }
        }
        return lines;
    }

    std::vector<std::string> TextNode::applyLineBreaks(const std::string& line, const IVec2 extent)
    {
        std::vector<std::string> result{};
        auto rest_size = static_cast<int32_t>(line.size());
        uint32_t start = 0;
        while (rest_size > extent.x)
        {
            // search backwards for a space to break at
            size_t break_pos = line.rfind(' ', start + extent.x - 1);
            uint32_t chunk_size = (break_pos != std::string::npos && break_pos >= start)
                                      ? static_cast<uint32_t>(break_pos - start)
                                      : static_cast<uint32_t>(extent.x);
            uint32_t consumed = (break_pos != std::string::npos && break_pos >= start)
                                    ? chunk_size + 1 // skip the space
                                    : chunk_size;
            result.push_back(line.substr(start, chunk_size));
            start += consumed;
            rest_size -= static_cast<int32_t>(consumed);
        }
        if (rest_size > 0)
        {
            result.push_back(line.substr(start));
        }
        return result;
    }
} // namespace TerminalRenderer
