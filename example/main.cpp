
#include <memory>
#include <include/terminal_renderer/TerminalRenderer.hpp>

int main(int argc, char* argv[])
{
    auto renderer = std::make_shared<TerminalRenderer::TerminalRenderer>();
    renderer->render();
}
