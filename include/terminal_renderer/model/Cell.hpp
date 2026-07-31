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
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_CELL_HPP