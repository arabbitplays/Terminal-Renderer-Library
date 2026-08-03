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
        IVec2 requested_size;
        IVec2 minimum_size;
        ScalingMode scaling_mode = FLEXIBLE;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_LAYOUTINFO_HPP