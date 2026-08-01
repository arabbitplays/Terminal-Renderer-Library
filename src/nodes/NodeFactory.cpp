#include <terminal_renderer/nodes/NodeFactory.hpp>

#include "terminal_renderer/nodes/container_node/ContainerNode.hpp"
#include "terminal_renderer/nodes/layouts/HorizontalLayout.hpp"
#include "terminal_renderer/nodes/text_node/TextNode.hpp"

namespace TerminalRenderer
{
    std::shared_ptr<TextNode> NodeFactory::createText(std::string text) const
    {
        return std::make_shared<TextNode>(std::move(text), 0, 0);
    }

    static std::shared_ptr<ContainerNode> makeBorder(const BorderCharSet& char_set, uint32_t margin, uint32_t padding)
    {
        return std::make_shared<ContainerNode>(char_set,
                                               static_cast<int32_t>(margin) * IVec2{2, 1}, true,
                                               static_cast<int32_t>(padding) * IVec2{2, 1});
    }

    std::shared_ptr<ContainerNode> NodeFactory::createLightBorder(uint32_t margin, uint32_t padding) const
    {
        return makeBorder(BorderCharSet::LightBorderCharSet, margin, padding);
    }

    std::shared_ptr<ContainerNode> NodeFactory::createHeavyBorder(uint32_t margin, uint32_t padding) const
    {
        return makeBorder(BorderCharSet::HeavyBorderCharSet, margin, padding);
    }

    std::shared_ptr<ContainerNode> NodeFactory::createDoubleBorder(uint32_t margin, uint32_t padding) const
    {
        return makeBorder(BorderCharSet::DoubleBorderCharSet, margin, padding);
    }

    std::shared_ptr<ContainerNode> NodeFactory::createDottedBorder(uint32_t margin, uint32_t padding) const
    {
        return makeBorder(BorderCharSet::DottedBorderCharSet, margin, padding);
    }

    std::shared_ptr<ContainerNode> NodeFactory::createRoundedBorder(uint32_t margin, uint32_t padding) const
    {
        return makeBorder(BorderCharSet::RoundedBorderCharSet, margin, padding);
    }

    std::shared_ptr<HorizontalLayout> NodeFactory::createHorizontalLayout() const
    {
        return std::make_shared<HorizontalLayout>();
    }
} // TerminalRenderer
