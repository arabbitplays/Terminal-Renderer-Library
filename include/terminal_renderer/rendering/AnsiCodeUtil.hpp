#ifndef TERMINAL_RENDERER_LIBRARY_ANSICOREUTIL_HPP
#define TERMINAL_RENDERER_LIBRARY_ANSICOREUTIL_HPP
#include <cstdint>
#include <string>

namespace TerminalRenderer
{
    class AnsiCodeUtil
    {
    public:
        static const std::string RESET_CODE;

        static std::string toAnsiForegroundColorCode(uint32_t color_index);
        static std::string toAnsiBackgroundColorCode(uint32_t color_index);
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_ANSICOREUTIL_HPP
