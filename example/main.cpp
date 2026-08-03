
#include <memory>
#include <terminal_renderer/TerminalRenderer.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    auto renderer = std::make_shared<TerminalRenderer::TerminalRenderer>();
    renderer->render();
}
