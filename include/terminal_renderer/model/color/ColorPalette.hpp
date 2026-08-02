#ifndef TERMINAL_RENDERER_LIBRARY_COLORPALETTE_HPP
#define TERMINAL_RENDERER_LIBRARY_COLORPALETTE_HPP
#include <vector>
#include <terminal_renderer/model/color/Color.hpp>

namespace TerminalRenderer
{
    class ColorPalette
    {
    public:
        ColorPalette() = default;

        ColorHandle getColor(uint32_t index);
        void addColor(const ColorHandle& color);

    private:
        std::vector<ColorHandle> palette;
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_COLORPALETTE_HPP