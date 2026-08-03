#ifndef TERMINAL_RENDERER_LIBRARY_PALETTECOLOR_HPP
#define TERMINAL_RENDERER_LIBRARY_PALETTECOLOR_HPP
#include <terminal_renderer/model/color/Color.hpp>

namespace TerminalRenderer
{
    class PaletteColor : public Color
    {
    public:
        static ColorHandle create(uint32_t index);

        uint32_t get256ColorIndex() override;

    private:
        PaletteColor(uint32_t index);

        uint32_t index;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_PALETTECOLOR_HPP
