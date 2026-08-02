#ifndef TERMINAL_RENDERER_LIBRARY_COLOR_HPP
#define TERMINAL_RENDERER_LIBRARY_COLOR_HPP
#include <cstdint>
#include <memory>

namespace TerminalRenderer
{
    class Color
    {
    public:
        Color() = default;
        virtual ~Color() = default;

        virtual uint32_t get256ColorIndex() = 0;
    };

    typedef std::shared_ptr<Color> ColorHandle;
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_COLOR_HPP