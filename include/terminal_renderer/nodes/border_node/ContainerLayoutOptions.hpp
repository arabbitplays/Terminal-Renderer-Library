#ifndef TERMINAL_RENDERER_LIBRARY_CONTAINERLAYOUTOPTIONS_HPP
#define TERMINAL_RENDERER_LIBRARY_CONTAINERLAYOUTOPTIONS_HPP
#include <terminal_renderer/core/IVec2.hpp>
#include <terminal_renderer/nodes/LayoutInfo.hpp>

namespace TerminalRenderer
{
    struct ContainerLayoutOptions
    {
        ScalingMode scaling_mode = FLEXIBLE;
        IVec2 min_extent;

        static ContainerLayoutOptions createDefault()
        {
            return {.scaling_mode = FLEXIBLE, .min_extent = IVec2::zero};
        }
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_CONTAINERLAYOUTOPTIONS_HPP