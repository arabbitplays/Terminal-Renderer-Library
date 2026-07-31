#ifndef TERMINAL_RENDERER_LIBRARY_VIEWPORT_HPP
#define TERMINAL_RENDERER_LIBRARY_VIEWPORT_HPP
#include <terminal_renderer/core/IVec2.h>

namespace TerminalRenderer
{
    struct Viewport
    {
        IVec2 origin;
        IVec2 extent;
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_VIEWPORT_HPP