#ifndef TERMINAL_RENDERER_LIBRARY_TEXTSEGMENT_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTSEGMENT_HPP
#include <string>
#include <terminal_renderer/model/color/Color.hpp>

namespace TerminalRenderer
{
    struct TextSegment
    {
        std::string text;
        std::optional<ColorHandle> fg_color;
        std::optional<ColorHandle> bg_color;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_TEXTSEGMENT_HPP