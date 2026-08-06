#include <terminal_renderer/widgets/LayoutErrorWidget.hpp>

#include <terminal_renderer/builder/SceneBuilder.hpp>
#include <terminal_renderer/nodes/border_node/BorderNode.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>

namespace TerminalRenderer
{
    LayoutErrorWidget::LayoutErrorWidget()
    {
        error_text = SceneBuilder::text({.flow_mode = TextFlowMode::STATIC}).build();
        root = SceneBuilder::verticalLayout()
               .addChild(SceneBuilder::roundedBorder(0, 1, {.scaling_mode = STATIC}).setChild(error_text).build())
               .build();
    }

    void LayoutErrorWidget::onUpdate()
    {
        if (!updated)
        {
            updated = true;
            error_text->appendTextSegment("Test error", StandardColor::create(BLACK), StandardColor::create(RED));
        }
    }
} // TerminalRenderer
