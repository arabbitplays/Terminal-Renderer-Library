#include <terminal_renderer/core/Utf8Util.hpp>

namespace TerminalRenderer
{
    namespace
    {
        constexpr char32_t REPLACEMENT = 0xFFFD;

        bool isContinuation(unsigned char b)
        {
            return (b & 0xC0) == 0x80;
        }
    } // namespace

    char32_t Utf8Util::nextCodepoint(const std::string& text, size_t& pos)
    {
        if (pos >= text.size())
        {
            return REPLACEMENT;
        }

        const auto b0 = static_cast<unsigned char>(text[pos]);
        size_t expected = 0;
        char32_t cp = 0;

        if (b0 < 0x80)
        {
            pos += 1;
            return b0;
        }
        if ((b0 & 0xE0) == 0xC0)
        {
            cp = b0 & 0x1F;
            expected = 2;
        }
        else if ((b0 & 0xF0) == 0xE0)
        {
            cp = b0 & 0x0F;
            expected = 3;
        }
        else if ((b0 & 0xF8) == 0xF0)
        {
            cp = b0 & 0x07;
            expected = 4;
        }
        else
        {
            pos += 1;
            return REPLACEMENT;
        }

        if (pos + expected > text.size())
        {
            pos += 1;
            return REPLACEMENT;
        }

        for (size_t k = 1; k < expected; ++k)
        {
            const auto bk = static_cast<unsigned char>(text[pos + k]);
            if (!isContinuation(bk))
            {
                pos += 1;
                return REPLACEMENT;
            }
            cp = (cp << 6) | (bk & 0x3F);
        }

        pos += expected;
        return cp;
    }

    size_t Utf8Util::codepointCount(const std::string& text)
    {
        size_t pos = 0;
        size_t count = 0;
        while (pos < text.size())
        {
            Utf8Util::nextCodepoint(text, pos);
            ++count;
        }
        return count;
    }
} // namespace TerminalRenderer
