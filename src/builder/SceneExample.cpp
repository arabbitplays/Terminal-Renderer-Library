#include <terminal_renderer/builder/SceneBuilder.hpp>
#include <terminal_renderer/builder/SceneExample.hpp>
#include <terminal_renderer/model/color/PaletteColor.hpp>
#include <terminal_renderer/model/color/RgbColor.hpp>
#include <terminal_renderer/model/color/StandardColor.hpp>
#include <terminal_renderer/nodes/border_node/BorderNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>

namespace TerminalRenderer
{
    RenderNodeHandle SceneExample::layoutTestScene()
    {
        return SceneBuilder::verticalLayout()
               .addChild(SceneBuilder::text("Static text").build())
               .addChild(SceneBuilder::roundedBorder()
                         .setChild(SceneBuilder::horizontalLayout()
                                   .addChild(SceneBuilder::dottedBorder().build())
                                   .addChild(SceneBuilder::doubleBorder().build())
                                   .build())
                         .build())
               .addChild(SceneBuilder::horizontalLayout()
                         .addChild(SceneBuilder::doubleBorder(1, 1, ContainerLayoutOptions{.scaling_mode = STATIC})
                                   .setChild(SceneBuilder::text("Text in static container").build()).build()).build())
               .addChild(SceneBuilder::horizontalLayout()
                         .addChild(SceneBuilder::heavyBorder()
                                   .setChild(SceneBuilder::verticalLayout()
                                             .addChild(SceneBuilder::lightBorder().build())
                                             .addChild(SceneBuilder::dottedBorder().build())
                                             .build())
                                   .build())
                         .addChild(SceneBuilder::doubleBorder().build())
                         .build())
               .build();
    }

    RenderNodeHandle SceneExample::textTestScene()
    {
        return SceneBuilder::verticalLayout()
               .addChild(SceneBuilder::dottedBorder(0, 0, ContainerLayoutOptions{.scaling_mode = STATIC, .min_extent = {40, 10}})
                   .setChild(SceneBuilder::text(lorem_ipsum, std::nullopt, std::nullopt, TextFlowMode::CUTOFF).build()).build())
               .addChild(SceneBuilder::dottedBorder(0, 0, ContainerLayoutOptions{.scaling_mode = STATIC, .min_extent = {40, 10}})
                   .setChild(SceneBuilder::text(lorem_ipsum, std::nullopt, std::nullopt, TextFlowMode::LINE_BREAK).build()).build())
               .build();
    }

    RenderNodeHandle SceneExample::colorTestScene()
    {
        return SceneBuilder::verticalLayout()
               .addChild(SceneBuilder::text("Default colors").build())

               .addChild(SceneBuilder::text("Standard BLACK", StandardColor::create(BLACK)).build())
               .addChild(SceneBuilder::text("Standard RED", StandardColor::create(RED)).build())
               .addChild(SceneBuilder::text("Standard GREEN", StandardColor::create(GREEN)).build())
               .addChild(SceneBuilder::text("Standard YELLOW", StandardColor::create(YELLOW)).build())
               .addChild(SceneBuilder::text("Standard BLUE", StandardColor::create(BLUE)).build())
               .addChild(SceneBuilder::text("Standard MAGENTA", StandardColor::create(MAGENTA)).build())
               .addChild(SceneBuilder::text("Standard CYAN", StandardColor::create(CYAN)).build())
               .addChild(SceneBuilder::text("Standard WHITE", StandardColor::create(WHITE)).build())

               .addChild(SceneBuilder::text("Bright BLACK", StandardColor::create(BLACK, true)).build())
               .addChild(SceneBuilder::text("Bright RED", StandardColor::create(RED, true)).build())
               .addChild(SceneBuilder::text("Bright GREEN", StandardColor::create(GREEN, true)).build())
               .addChild(SceneBuilder::text("Bright YELLOW", StandardColor::create(YELLOW, true)).build())
               .addChild(SceneBuilder::text("Bright BLUE", StandardColor::create(BLUE, true)).build())
               .addChild(SceneBuilder::text("Bright MAGENTA", StandardColor::create(MAGENTA, true)).build())
               .addChild(SceneBuilder::text("Bright CYAN", StandardColor::create(CYAN, true)).build())
               .addChild(SceneBuilder::text("Bright WHITE", StandardColor::create(WHITE, true)).build())

               .addChild(SceneBuilder::text("RGB pure white", RgbColor::create(5, 5, 5)).build())
               .addChild(SceneBuilder::text("RGB pure red", RgbColor::create(5, 0, 0)).build())
               .addChild(SceneBuilder::text("RGB pure green", RgbColor::create(0, 5, 0)).build())
               .addChild(SceneBuilder::text("RGB pure blue", RgbColor::create(0, 0, 5)).build())
               .addChild(SceneBuilder::text("RGB pure black", RgbColor::create(0, 0, 0)).build())

               .addChild(SceneBuilder::text("Palette index 0", PaletteColor::create(0)).build())
               .addChild(SceneBuilder::text("Palette index 1", PaletteColor::create(1)).build())
               .addChild(SceneBuilder::text("Palette index 2", PaletteColor::create(2)).build())
               .addChild(SceneBuilder::text("Palette index 999", PaletteColor::create(999)).build())
               .build();
    }
} // namespace TerminalRenderer
