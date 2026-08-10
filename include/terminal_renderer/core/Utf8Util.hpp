#ifndef TERMINAL_RENDERER_LIBRARY_UTF8UTIL_HPP
#define TERMINAL_RENDERER_LIBRARY_UTF8UTIL_HPP
#include <cstddef>
#include <string>

namespace TerminalRenderer
{
    class Utf8Util
    {
    public:
        // Decodes the codepoint starting at byte offset `pos` in `text` and advances
        // `pos` past it. Invalid or truncated sequences yield U+FFFD and consume one byte.
        static char32_t nextCodepoint(const std::string& text, size_t& pos);

        // Number of Unicode codepoints in `text`.
        static size_t codepointCount(const std::string& text);
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_UTF8UTIL_HPP
