#ifndef TERMINAL_RENDERER_LIBRARY_ANSICOREUTIL_HPP
#define TERMINAL_RENDERER_LIBRARY_ANSICOREUTIL_HPP
#include <cstdint>
#include <string>
#include <string_view>

namespace TerminalRenderer
{
    class AnsiCodeUtil
    {
    public:
        static constexpr std::string_view RESET_CODE = "\x1b[0m";

        static std::string toAnsiForegroundColorCode(uint32_t color_index);
        static std::string toAnsiBackgroundColorCode(uint32_t color_index);
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_ANSICOREUTIL_HPP
