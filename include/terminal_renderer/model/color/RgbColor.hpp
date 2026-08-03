#ifndef TERMINAL_RENDERER_LIBRARY_RGBCOLOR_HPP
#define TERMINAL_RENDERER_LIBRARY_RGBCOLOR_HPP
#include <cstdint>
#include <terminal_renderer/model/color/Color.hpp>

namespace TerminalRenderer
{
    class RgbColor : public Color
    {
    public:
        static ColorHandle create(uint32_t r, uint32_t g, uint32_t b);

        uint32_t get256ColorIndex() override;

    private:
        RgbColor(uint32_t r, uint32_t g, uint32_t b);

        uint32_t r;
        uint32_t g;
        uint32_t b;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_RGBCOLOR_HPP