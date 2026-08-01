#include <terminal_renderer/nodes/builder/SceneBuilder.hpp>

#include <terminal_renderer/nodes/container_node/BorderNode.hpp>
#include <terminal_renderer/nodes/layouts/HorizontalLayout.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>

namespace TerminalRenderer
{
    LeafBuilder<TextNode> SceneBuilder::text(std::string text) const
    {
        return LeafBuilder<TextNode>{std::make_shared<TextNode>(std::move(text), 0, 0)};
    }

    static std::shared_ptr<BorderNode> makeBorder(const BorderCharSet& char_set, uint32_t margin, uint32_t padding)
    {
        return std::make_shared<BorderNode>(char_set,
                                            static_cast<int32_t>(margin) * IVec2{2, 1}, true,
                                            static_cast<int32_t>(padding) * IVec2{2, 1});
    }

    ContainerBuilder<BorderNode> SceneBuilder::lightBorder(uint32_t margin, uint32_t padding) const
    {
        return ContainerBuilder<BorderNode>{makeBorder(BorderCharSet::LightBorderCharSet, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::heavyBorder(uint32_t margin, uint32_t padding) const
    {
        return ContainerBuilder<BorderNode>{makeBorder(BorderCharSet::HeavyBorderCharSet, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::doubleBorder(uint32_t margin, uint32_t padding) const
    {
        return ContainerBuilder<BorderNode>{makeBorder(BorderCharSet::DoubleBorderCharSet, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::dottedBorder(uint32_t margin, uint32_t padding) const
    {
        return ContainerBuilder<BorderNode>{makeBorder(BorderCharSet::DottedBorderCharSet, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::roundedBorder(uint32_t margin, uint32_t padding) const
    {
        return ContainerBuilder<BorderNode>{makeBorder(BorderCharSet::RoundedBorderCharSet, margin, padding)};
    }

    GroupBuilder<HorizontalLayout> SceneBuilder::horizontalLayout() const
    {
        return GroupBuilder<HorizontalLayout>{std::make_shared<HorizontalLayout>()};
    }
} // TerminalRenderer
