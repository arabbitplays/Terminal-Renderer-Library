#include <terminal_renderer/model/color/StandardColor.hpp>

namespace TerminalRenderer
{
    StandardColor::StandardColor(const StandardColorType type, const bool bright) : type(type), bright(bright)
    {
    }

    ColorHandle StandardColor::create(const StandardColorType type, const bool bright)
    {
        return std::shared_ptr<StandardColor>(new StandardColor(type, bright));
    }

    uint32_t StandardColor::get256ColorIndex()
    {
        uint32_t bright_offset = bright ? 8 : 0;
        return static_cast<uint32_t>(type) + bright_offset;
    }
} // TerminalRenderer
