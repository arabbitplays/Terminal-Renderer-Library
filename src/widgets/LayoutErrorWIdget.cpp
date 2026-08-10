#include <terminal_renderer/builder/SceneBuilder.hpp>
#include <terminal_renderer/nodes/border_node/BorderNode.hpp>
#include <terminal_renderer/nodes/layouts/LayoutNode.hpp>
#include <terminal_renderer/nodes/text_node/TextNode.hpp>
#include <terminal_renderer/widgets/LayoutErrorWidget.hpp>

namespace TerminalRenderer
{
    LayoutErrorWidget::LayoutErrorWidget()
    {
        error_text = SceneBuilder::text({.flow_mode = TextFlowMode::LINE_BREAK}).build();
        root = SceneBuilder::scene()
                   .addChild(SceneBuilder::container().setChild(error_text).build())
                   .build();
    }

    void LayoutErrorWidget::onUpdate()
    {
        if (!updated)
        {
            updated = true;
            error_text->appendTextSegment("Window to small", StandardColor::create(RED));
        }
    }
} // namespace TerminalRenderer
