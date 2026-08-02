#ifndef TERMINAL_RENDERER_LIBRARY_STANDARDCOLOR_HPP
#define TERMINAL_RENDERER_LIBRARY_STANDARDCOLOR_HPP
#include <terminal_renderer/model/color/Color.hpp>

namespace TerminalRenderer
{
    enum StandardColorType
    {
        BLACK = 0,
        RED = 1,
        GREEN = 2,
        YELLOW = 3,
        BLUE = 4,
        MAGENTA = 5,
        CYAN = 6,
        WHITE = 7,
    };

    class StandardColor : public Color
    {
    public:
        static ColorHandle create(StandardColorType type, bool bright = false);

        uint32_t get256ColorIndex() override;

    private:
        StandardColor(StandardColorType type, bool bright = false);

        StandardColorType type;
        bool bright;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_STANDARDCOLOR_HPP
