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

    class LayoutInfo
    {
    public:
        LayoutInfo() = default;
        LayoutInfo(IVec2 requested_size, IVec2 minimum_size, ScalingMode scaling_mode = FLEXIBLE)
            : requested_size(requested_size), minimum_size(minimum_size), scaling_mode(scaling_mode)
        {
        }

        IVec2 getRequestedSize() const { return requested_size; }

        // A STATIC layout cannot shrink below its requested size.
        IVec2 getMinimumSize() const { return scaling_mode == STATIC ? requested_size : minimum_size; }

        ScalingMode getScalingMode() const { return scaling_mode; }

    private:
        IVec2 requested_size{};
        IVec2 minimum_size{};
        ScalingMode scaling_mode = FLEXIBLE;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_LAYOUTINFO_HPP
