#ifndef TERMINAL_RENDERER_LIBRARY_LAYOUTUTIL_HPP
#define TERMINAL_RENDERER_LIBRARY_LAYOUTUTIL_HPP
#include <cstdint>
#include <terminal_renderer/core/IVec2.hpp>
#include <terminal_renderer/model/Viewport.hpp>
#include <terminal_renderer/nodes/LayoutInfo.hpp>
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
            return Viewport{makeVec(main_offset, 0, axis), makeVec(main_size, cross_size, axis)};
        }

        static std::vector<int32_t> distribute(uint32_t total_size, std::vector<DistributionRequest> requests)
        {
            std::vector<int32_t> results(requests.size(), 0);
            if (requests.empty())
            {
                return results;
            }

            uint32_t total_requested_size = 0;
            for (const auto& request : requests)
            {
                total_requested_size += request.requested_size;
            }

            if (total_requested_size <= total_size)
            {
                uint32_t remaining_size = total_size - total_requested_size;
                uint32_t extra_size = remaining_size / requests.size();
                remaining_size -= extra_size * requests.size();

                for (uint32_t i = 0; i < requests.size(); i++)
                {
                    results.at(i) = extra_size + requests.at(i).requested_size;

                    // distribute remaining size 1 by 1 over the requests
                    if (i < remaining_size)
                    {
                        results.at(i)++;
                    }
                }
            }
            else
            {
                uint32_t overflowing_size = total_requested_size - total_size;
                uint32_t size_to_remove = overflowing_size / requests.size();
                overflowing_size -= size_to_remove * requests.size();

                for (uint32_t i = 0; i < requests.size(); i++)
                {
                    results.at(i) = -size_to_remove + requests.at(i).requested_size;

                    if (i < overflowing_size)
                    {
                        results.at(i)--;
                    }
                }
            }
            return results;
        }
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_LAYOUTUTIL_HPP
