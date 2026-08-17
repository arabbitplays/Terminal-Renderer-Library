#include <algorithm>
#include <cmath>
#include <terminal_renderer/model/color/RgbColor.hpp>

namespace TerminalRenderer
{
    ColorHandle RgbColor::create(const Vec3& rgb)
    {
        return std::shared_ptr<RgbColor>(new RgbColor(convertToIndex(rgb.x), convertToIndex(rgb.y), convertToIndex(rgb.z)));
    }

    RgbColor::RgbColor(const uint32_t r, const uint32_t g, const uint32_t b) : r(r), g(g), b(b)
    {
    }

    uint32_t RgbColor::convertToIndex(float c)
    {
        c = std::clamp(c, 0.0f, 1.0f);
        return std::lround(c * 5.0f);
    }

    uint32_t RgbColor::get256ColorIndex()
    {
        return 16 + (36 * r) + (6 * g) + b;
    }
} // namespace TerminalRenderer
