#include <terminal_renderer/model/color/RgbColor.hpp>

namespace TerminalRenderer
{
    RgbColor::RgbColor(const uint32_t r, const uint32_t g, const uint32_t b) : r(r), g(g), b(b)
    {
    }

    ColorHandle RgbColor::create(const uint32_t r, const uint32_t g, const uint32_t b)
    {
        return std::shared_ptr<RgbColor>(new RgbColor(r, g, b));
    }

    uint32_t RgbColor::get256ColorIndex()
    {
        return 16 + 36 * r + 6 * g + b;
    }
} // namespace TerminalRenderer
