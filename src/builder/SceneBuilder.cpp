#include <terminal_renderer/builder/SceneBuilder.hpp>
#include <terminal_renderer/nodes/container_node/BorderNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>

namespace TerminalRenderer
{
    LeafBuilder<TextNode> SceneBuilder::text(
        std::string text, std::optional<ColorHandle> fg_color, std::optional<ColorHandle> bg_color)
    {
        return LeafBuilder<TextNode>{
            std::make_shared<TextNode>(std::move(text), std::move(fg_color), std::move(bg_color))};
    }

    static std::shared_ptr<BorderNode> makeBorder(const BorderCharSet& char_set, uint32_t margin, uint32_t padding)
    {
        return std::make_shared<BorderNode>(
            char_set, static_cast<int32_t>(margin) * IVec2{2, 1}, true, static_cast<int32_t>(padding) * IVec2{2, 1});
    }

    ContainerBuilder<BorderNode> SceneBuilder::lightBorder(uint32_t margin, uint32_t padding)
    {
        return ContainerBuilder<BorderNode>{makeBorder(light_border_char_set, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::heavyBorder(uint32_t margin, uint32_t padding)
    {
        return ContainerBuilder<BorderNode>{makeBorder(heavy_border_char_set, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::doubleBorder(uint32_t margin, uint32_t padding)
    {
        return ContainerBuilder<BorderNode>{makeBorder(double_border_char_set, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::dottedBorder(uint32_t margin, uint32_t padding)
    {
        return ContainerBuilder<BorderNode>{makeBorder(dotted_border_char_set, margin, padding)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::roundedBorder(uint32_t margin, uint32_t padding)
    {
        return ContainerBuilder<BorderNode>{makeBorder(rounded_border_char_set, margin, padding)};
    }

    GroupBuilder<LayoutNode> SceneBuilder::horizontalLayout()
    {
        return GroupBuilder<LayoutNode>{std::make_shared<LayoutNode>(Axis::Horizontal)};
    }

    GroupBuilder<LayoutNode> SceneBuilder::verticalLayout()
    {
        return GroupBuilder<LayoutNode>{std::make_shared<LayoutNode>(Axis::Vertical)};
    }
} // namespace TerminalRenderer
