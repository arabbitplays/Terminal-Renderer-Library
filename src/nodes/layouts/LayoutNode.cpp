#include <cassert>
#include <terminal_renderer/nodes/layouts/LayoutException.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>

namespace TerminalRenderer
{
    LayoutInfo LayoutNode::getLayoutInfo()
    {
        if (children.empty())
        {
            return LayoutInfo::createFlexible(IVec2::zero, IVec2::zero);
        }

        int32_t requested_main = 0;
        int32_t requested_cross = 0;
        int32_t minimum_main = 0;
        int32_t minimum_cross = LayoutUtil::crossAxis(children.at(0)->getLayoutInfo().getMinimumSize(), axis);
        ScalingMode scaling_mode = STATIC;
        for (const auto& child : children)
        {
            LayoutInfo child_layout_info = child->getLayoutInfo();
            IVec2 child_requested = child_layout_info.getRequestedSize();
            IVec2 child_minimum = child_layout_info.getMinimumSize();
            requested_main += LayoutUtil::mainAxis(child_requested, axis);
            requested_cross = std::max(requested_cross, LayoutUtil::crossAxis(child_requested, axis));
            minimum_main += LayoutUtil::mainAxis(child_minimum, axis);
            minimum_cross = std::max(minimum_cross, LayoutUtil::crossAxis(child_minimum, axis));
            if (child_layout_info.getScalingMode() == FLEXIBLE)
            {
                scaling_mode = FLEXIBLE;
            }
        }
        IVec2 requested = LayoutUtil::makeVec(requested_main, requested_cross, axis);
        if (scaling_mode == STATIC)
        {
            return LayoutInfo::createStatic(requested);
        }
        return LayoutInfo::createFlexible(
            requested,
            LayoutUtil::makeVec(minimum_main, minimum_cross, axis)
        );
    }

    void LayoutNode::render(TargetActuator& target_actuator)
    {
        IVec2 extent = target_actuator.getExtent();
        int32_t main_size = LayoutUtil::mainAxis(extent, axis);
        int32_t cross_size = LayoutUtil::crossAxis(extent, axis);

        std::vector<uint32_t> distribution = getDistribution(extent);
        assert(children.size() == distribution.size());

        int32_t curr = 0;
        for (uint32_t i = 0; i < distribution.size(); i++)
        {
            auto slot_main_size = static_cast<int32_t>(distribution.at(i));
            if (slot_main_size <= 0 || curr >= main_size)
            {
                curr += slot_main_size;
                continue;
            }
            LayoutInfo child_layout_info = children.at(i)->getLayoutInfo();
            int32_t slot_cross_size = child_layout_info.getScalingMode() == FLEXIBLE
                                          ? cross_size
                                          : LayoutUtil::crossAxis(child_layout_info.getRequestedSize(), axis);
            if (slot_cross_size > cross_size)
            {
                throw LayoutException("Available cross size is too small");
            }
            TargetActuator child_actuator =
                target_actuator.createInnerTargetActuator(
                    LayoutUtil::makeSlot(curr, slot_main_size, slot_cross_size, axis));
            children.at(i)->render(child_actuator);
            curr += slot_main_size;
        }
    }

    std::vector<uint32_t> LayoutNode::getDistribution(IVec2 extent) const
    {
        std::vector<DistributionRequest> requests{};
        for (const auto& child : children)
        {
            LayoutInfo layout_info = child->getLayoutInfo();
            requests.emplace_back(layout_info.getScalingMode(),
                                  LayoutUtil::mainAxis(layout_info.getRequestedSize(), axis),
                                  LayoutUtil::mainAxis(layout_info.getMinimumSize(), axis));
        }
        return LayoutUtil::distribute(LayoutUtil::mainAxis(extent, axis), requests);
    }
} // namespace TerminalRenderer
