#include <terminal_renderer/model/color/ColorPalette.hpp>
#include <terminal_renderer/model/color/PaletteColor.hpp>

namespace TerminalRenderer
{
    PaletteColor::PaletteColor(const uint32_t index) : index(index)
    {
    }

    ColorHandle PaletteColor::create(const uint32_t index)
    {
        return std::shared_ptr<PaletteColor>(new PaletteColor(index));
    }

    uint32_t PaletteColor::get256ColorIndex()
    {
        ColorPalette palette; // TODO where to get this from?
        return palette.getColor(index)->get256ColorIndex();
    }
} // namespace TerminalRenderer
