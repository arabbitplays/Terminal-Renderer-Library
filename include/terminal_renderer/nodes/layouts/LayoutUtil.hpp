#ifndef TERMINAL_RENDERER_LIBRARY_LAYOUTUTIL_HPP
#define TERMINAL_RENDERER_LIBRARY_LAYOUTUTIL_HPP
#include <cstdint>
#include <terminal_renderer/core/IVec2.hpp>
#include <terminal_renderer/model/Viewport.hpp>
#include <terminal_renderer/nodes/LayoutInfo.hpp>
#include <terminal_renderer/nodes/layouts/LayoutException.hpp>
#include <vector>

namespace TerminalRenderer
{
    enum class Axis
    {
        Horizontal,
        Vertical
    };

    struct DistributionRequest
    {
        ScalingMode scaling_mode;
        uint32_t requested_size;
        uint32_t min_size;
    };

    class LayoutUtil
    {
    public:
        static int32_t mainAxis(IVec2 v, Axis axis)
        {
            return axis == Axis::Horizontal ? v.x : v.y;
        }

        static int32_t crossAxis(IVec2 v, Axis axis)
        {
            return axis == Axis::Horizontal ? v.y : v.x;
        }

        static IVec2 makeVec(int32_t main, int32_t cross, Axis axis)
        {
            return axis == Axis::Horizontal ? IVec2{main, cross} : IVec2{cross, main};
        }

        static Viewport makeSlot(int32_t main_offset, int32_t main_size, int32_t cross_size, Axis axis)
        {
            return Viewport{.origin = makeVec(main_offset, 0, axis), .extent = makeVec(main_size, cross_size, axis)};
        }

        static std::vector<uint32_t> distribute(
            const uint32_t total_size, const std::vector<DistributionRequest>& requests)
        {
            std::vector<uint32_t> results(requests.size(), 0);
            if (requests.empty())
            {
                return results;
            }

            auto remaining_size = static_cast<int32_t>(total_size);
            bool has_flexible_child = false;
            for (uint32_t i = 0; i < requests.size(); i++)
            {
                const auto min_size = requests.at(i).min_size;
                has_flexible_child |= requests.at(i).scaling_mode == FLEXIBLE;
                remaining_size -= static_cast<int32_t>(min_size);
                results.at(i) = min_size;
            }

            if (remaining_size < 0)
            {
                throw LayoutException("Main slot size is too small");
            }

            if (!has_flexible_child)
            {
                return results;
            }

            uint32_t next_result_idx = 0;
            while (remaining_size > 0)
            {
                while (requests.at(next_result_idx).scaling_mode != FLEXIBLE)
                {
                    next_result_idx = (next_result_idx + 1) % requests.size();
                }
                results.at(next_result_idx) += 1; // TODO make this dependent on requested size
                remaining_size--;
                next_result_idx = (next_result_idx + 1) % requests.size();
            }
            return results;
        }

        static uint32_t getTotalRequestedSize(const std::vector<DistributionRequest>& requests)
        {
            uint32_t total_requested_size = 0;
            for (const auto& request : requests)
            {
                total_requested_size += request.requested_size;
            }
            return total_requested_size;
        }
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_LAYOUTUTIL_HPP
