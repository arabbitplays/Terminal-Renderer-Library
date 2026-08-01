#include <cassert>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>

namespace TerminalRenderer
{
    LayoutInfo LayoutNode::getLayoutInfo()
    {
        return LayoutInfo{};
    }

    void LayoutNode::render(TargetActuator& targetActuator)
    {
        IVec2 extent = targetActuator.getExtent();
        int32_t main_size = LayoutUtil::mainAxis(extent, axis);
        int32_t cross_size = LayoutUtil::crossAxis(extent, axis);

        std::vector<int32_t> distribution = getDistribution(extent);
        assert(children.size() == distribution.size());

        int32_t curr = 0;
        for (uint32_t i = 0; i < distribution.size(); i++)
        {
            int32_t slot = distribution.at(i);
            if (slot <= 0 || curr >= main_size)
            {
                curr += slot;
                continue;
            }
            TargetActuator childActuator = targetActuator.createInnerTargetActuator(
                LayoutUtil::makeSlot(curr, slot, cross_size, axis));
            children.at(i)->render(childActuator);
            curr += slot;
        }
    }

    std::vector<int32_t> LayoutNode::getDistribution(IVec2 extent) const
    {
        std::vector<DistributionRequest> requests{};
        for (const auto& child : children)
        {
            LayoutInfo layoutInfo = child->getLayoutInfo();
            requests.emplace_back(layoutInfo.scaling_mode,
                                  LayoutUtil::mainAxis(layoutInfo.requestedSize, axis));
        }
        return LayoutUtil::distribute(LayoutUtil::mainAxis(extent, axis), requests);
    }
} // TerminalRenderer
