#include <memory>
#include <terminal_renderer/model/color/ColorPalette.hpp>
#include <terminal_renderer/model/color/StandardColor.hpp>

namespace TerminalRenderer
{
    ColorHandle ColorPalette::getColor(const uint32_t index)
    {
        if (index < palette.size())
        {
            return palette[index];
        }
        return StandardColor::create(WHITE);
    }

    void ColorPalette::addColor(const ColorHandle& color)
    {
        palette.push_back(color);
    }
}