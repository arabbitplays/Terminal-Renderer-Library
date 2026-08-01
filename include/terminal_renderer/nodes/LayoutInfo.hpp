#ifndef TERMINAL_RENDERER_LIBRARY_LAYOUTINFO_HPP
#define TERMINAL_RENDERER_LIBRARY_LAYOUTINFO_HPP
#include <terminal_renderer/core/IVec2.hpp>

namespace TerminalRenderer
{
    enum ScalingMode
    {
        STATIC,
        FLEXIBLE
    };

    struct LayoutInfo
    {
        IVec2 requestedSize;
        IVec2 minimumSize;
        ScalingMode scaling_mode = FLEXIBLE;
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_LAYOUTINFO_HPP