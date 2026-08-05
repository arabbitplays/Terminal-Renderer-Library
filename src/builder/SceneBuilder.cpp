#include <terminal_renderer/builder/SceneBuilder.hpp>
#include <terminal_renderer/nodes/border_node/ContainerLayoutOptions.hpp>
#include <terminal_renderer/nodes/border_node/BorderNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>

namespace TerminalRenderer
{
    LeafBuilder<TextNode> SceneBuilder::text(
        std::string text, std::optional<ColorHandle> fg_color, std::optional<ColorHandle> bg_color, TextFlowMode flow_mode)
    {
        return LeafBuilder<TextNode>{
            std::make_shared<TextNode>(std::move(text), std::move(fg_color), std::move(bg_color), flow_mode)};
    }

    static std::shared_ptr<BorderNode> makeBorder(
        const BorderCharSet& char_set, uint32_t margin, uint32_t padding, ContainerLayoutOptions layout_options,
        bool draw_border = true)
    {
        return std::make_shared<BorderNode>(char_set, static_cast<int32_t>(margin) * IVec2{2, 1}, draw_border,
            static_cast<int32_t>(padding) * IVec2{2, 1}, layout_options);
    }

    ContainerBuilder<BorderNode> SceneBuilder::container(uint32_t margin, uint32_t padding, ContainerLayoutOptions layout_options)
    {
        return ContainerBuilder<BorderNode>{makeBorder(light_border_char_set, margin, padding, layout_options, false)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::lightBorder(uint32_t margin, uint32_t padding, ContainerLayoutOptions layout_options)
    {
        return ContainerBuilder<BorderNode>{makeBorder(light_border_char_set, margin, padding, layout_options)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::heavyBorder(uint32_t margin, uint32_t padding, ContainerLayoutOptions layout_options)
    {
        return ContainerBuilder<BorderNode>{makeBorder(heavy_border_char_set, margin, padding, layout_options)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::doubleBorder(uint32_t margin, uint32_t padding, ContainerLayoutOptions layout_options)
    {
        return ContainerBuilder<BorderNode>{makeBorder(double_border_char_set, margin, padding, layout_options)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::dottedBorder(uint32_t margin, uint32_t padding, ContainerLayoutOptions layout_options)
    {
        return ContainerBuilder<BorderNode>{makeBorder(dotted_border_char_set, margin, padding, layout_options)};
    }

    ContainerBuilder<BorderNode> SceneBuilder::roundedBorder(
        uint32_t margin, uint32_t padding, ContainerLayoutOptions layout_options)
    {
        return ContainerBuilder<BorderNode>{makeBorder(rounded_border_char_set, margin, padding, layout_options)};
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
