#include <terminal_renderer/rendering/AnsiCodeUtil.hpp>

namespace TerminalRenderer
{
    std::string AnsiCodeUtil::toAnsiForegroundColorCode(const uint32_t color_index)
    {
        return "\x1b[38;5;" + std::to_string(color_index) + "m";
    }

    std::string AnsiCodeUtil::toAnsiBackgroundColorCode(const uint32_t color_index)
    {
        return "\x1b[48;5;" + std::to_string(color_index) + "m";
    }
} // namespace TerminalRenderer
