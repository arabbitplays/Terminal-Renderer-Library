#include <memory>
#include <terminal_renderer/builder/RendererBuilder.hpp>
#include <terminal_renderer/builder/SceneExample.hpp>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <terminal_renderer/widgets/LayoutErrorWidget.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    auto scene = TerminalRenderer::SceneExample::textTestScene();
    auto renderer = TerminalRenderer::RendererBuilder().scene(scene).build();
    while (true)
    {
        renderer->render();
    }
}
