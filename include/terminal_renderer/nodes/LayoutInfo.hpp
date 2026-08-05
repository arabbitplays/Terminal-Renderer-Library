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

        static LayoutInfo createStatic(IVec2 requested_size)
        {
            return LayoutInfo{requested_size, requested_size, STATIC};
        }

        static LayoutInfo createFlexible(IVec2 requested_size, IVec2 minimum_size)
        {
            return LayoutInfo{requested_size, minimum_size, FLEXIBLE};
        }

        IVec2 getRequestedSize() const
        {
            return requested_size;
        }

        // A STATIC layout cannot shrink below its requested size.
        IVec2 getMinimumSize() const
        {
            return scaling_mode == STATIC ? requested_size : minimum_size;
        }

        ScalingMode getScalingMode() const
        {
            return scaling_mode;
        }

    private:
        LayoutInfo(IVec2 requested_size, IVec2 minimum_size, ScalingMode scaling_mode)
            : requested_size(requested_size), minimum_size(minimum_size), scaling_mode(scaling_mode)
        {
        }

        IVec2 requested_size;
        IVec2 minimum_size;
        ScalingMode scaling_mode = FLEXIBLE;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_LAYOUTINFO_HPP
