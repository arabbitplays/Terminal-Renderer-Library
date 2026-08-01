#include <cassert>
#include <terminal_renderer/nodes/layouts/HorizontalLayout.hpp>
#include <terminal_renderer/nodes/layouts/LayoutUtil.hpp>

namespace TerminalRenderer
{
    LayoutInfo HorizontalLayout::getLayoutInfo()
    {
        return LayoutInfo{};
    }

    void HorizontalLayout::render(TargetActuator& targetActuator)
    {
        IVec2 extent = targetActuator.getExtent();
        std::vector<int32_t> distribution = getDistribution(extent);
        assert(children.size() == distribution.size());
        int32_t curr_x = 0;
        for (uint32_t i = 0; i < distribution.size(); i++)
        {
            int32_t width = distribution.at(i);
            if (width <= 0 || curr_x >= extent.x)
            {
                curr_x += width;
                continue;
            }
            TargetActuator childActuator = targetActuator.createInnerTargetActuator(Viewport{{curr_x, 0}, {width, extent.y} });
            children.at(i)->render(childActuator);
            curr_x += width;
        }
    }

    std::vector<int32_t> HorizontalLayout::getDistribution(IVec2 extent)
    {
        std::vector<DistributionRequest> requests{};
        for (const auto& child : children)
        {
            LayoutInfo layoutInfo = child->getLayoutInfo();
            requests.emplace_back(layoutInfo.scaling_mode, layoutInfo.requestedSize.x);
        }
        return LayoutUtil::distribute(extent.x, requests);

    }
} // TerminalRenderer