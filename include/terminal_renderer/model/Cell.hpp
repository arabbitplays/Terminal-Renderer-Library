#ifndef TERMINAL_RENDERER_LIBRARY_CELL_HPP
#define TERMINAL_RENDERER_LIBRARY_CELL_HPP
#include <optional>
#include <terminal_renderer/model/color/Color.hpp>

namespace TerminalRenderer
{
    struct Cell
    {
        char32_t c;
        std::optional<ColorHandle> fg_color;
        std::optional<ColorHandle> bg_color;

        bool operator==(const Cell& other) const
        {
            return c == other.c && sameColor(fg_color, other.fg_color) && sameColor(bg_color, other.bg_color);
        }

        bool operator!=(const Cell& other) const
        {
            return !(*this == other);
        }

    private:
        static bool sameColor(const std::optional<ColorHandle>& a, const std::optional<ColorHandle>& b)
        {
            if (a.has_value() != b.has_value())
            {
                return false;
            }
            if (!a.has_value())
            {
                return true;
            }
            return (*a)->get256ColorIndex() == (*b)->get256ColorIndex();
        }
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_CELL_HPP
