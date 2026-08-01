#ifndef TERMINAL_RENDERER_LIBRARY_CELL_HPP
#define TERMINAL_RENDERER_LIBRARY_CELL_HPP
#include <cstdint>

namespace TerminalRenderer
{
    struct Cell
    {
        char32_t c;
        uint32_t fg_color_idx;
        uint32_t bg_color_idx;

        bool operator==(const Cell& other) const
        {
            return c == other.c
                && fg_color_idx == other.fg_color_idx
                && bg_color_idx == other.bg_color_idx;
        }

        bool operator!=(const Cell& other) const
        {
            return !(*this == other);
        }
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_CELL_HPP
