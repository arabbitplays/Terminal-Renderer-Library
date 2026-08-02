#include <terminal_renderer/builder/SceneExample.hpp>

#include <terminal_renderer/builder/SceneBuilder.hpp>
#include <terminal_renderer/model/color/PaletteColor.hpp>
#include <terminal_renderer/model/color/RgbColor.hpp>
#include <terminal_renderer/model/color/StandardColor.hpp>
#include <terminal_renderer/nodes/container_node/BorderNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>

namespace TerminalRenderer
{
    RenderNodeHandle SceneExample::LayoutTestScene()
    {
        SceneBuilder builder;
        return builder.verticalLayout()
            .addChild(builder.roundedBorder()
                .setChild(builder.horizontalLayout()
                    .addChild(builder.dottedBorder().build())
                    .addChild(builder.doubleBorder().build())
                    .build())
                .build())
            .addChild(builder.horizontalLayout()
                .addChild(builder.heavyBorder()
                    .setChild(builder.verticalLayout()
                        .addChild(builder.lightBorder().build())
                        .addChild(builder.dottedBorder().build())
                        .build())
                    .build())
                .addChild(builder.doubleBorder().build())
                .build())
            .build();
    }

    RenderNodeHandle SceneExample::TextTestScene()
    {
        SceneBuilder builder;
        return builder.verticalLayout()
            .addChild(builder.text("Default colors").build())

            .addChild(builder.text("Standard BLACK",   StandardColor::create(BLACK)).build())
            .addChild(builder.text("Standard RED",     StandardColor::create(RED)).build())
            .addChild(builder.text("Standard GREEN",   StandardColor::create(GREEN)).build())
            .addChild(builder.text("Standard YELLOW",  StandardColor::create(YELLOW)).build())
            .addChild(builder.text("Standard BLUE",    StandardColor::create(BLUE)).build())
            .addChild(builder.text("Standard MAGENTA", StandardColor::create(MAGENTA)).build())
            .addChild(builder.text("Standard CYAN",    StandardColor::create(CYAN)).build())
            .addChild(builder.text("Standard WHITE",   StandardColor::create(WHITE)).build())

            .addChild(builder.text("Bright BLACK",   StandardColor::create(BLACK,   true)).build())
            .addChild(builder.text("Bright RED",     StandardColor::create(RED,     true)).build())
            .addChild(builder.text("Bright GREEN",   StandardColor::create(GREEN,   true)).build())
            .addChild(builder.text("Bright YELLOW",  StandardColor::create(YELLOW,  true)).build())
            .addChild(builder.text("Bright BLUE",    StandardColor::create(BLUE,    true)).build())
            .addChild(builder.text("Bright MAGENTA", StandardColor::create(MAGENTA, true)).build())
            .addChild(builder.text("Bright CYAN",    StandardColor::create(CYAN,    true)).build())
            .addChild(builder.text("Bright WHITE",   StandardColor::create(WHITE,   true)).build())

            .addChild(builder.text("RGB pure white", RgbColor::create(5, 5, 5)).build())
            .addChild(builder.text("RGB pure red",   RgbColor::create(5, 0, 0)).build())
            .addChild(builder.text("RGB pure green", RgbColor::create(0, 5, 0)).build())
            .addChild(builder.text("RGB pure blue",  RgbColor::create(0, 0, 5)).build())
            .addChild(builder.text("RGB pure black", RgbColor::create(0, 0, 0)).build())

            .addChild(builder.text("Palette index 0",   PaletteColor::create(0)).build())
            .addChild(builder.text("Palette index 1",   PaletteColor::create(1)).build())
            .addChild(builder.text("Palette index 2",   PaletteColor::create(2)).build())
            .addChild(builder.text("Palette index 999", PaletteColor::create(999)).build())
            .build();
    }
} // TerminalRenderer
