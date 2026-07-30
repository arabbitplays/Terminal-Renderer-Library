#include <terminal_renderer/pipes/TerminalRenderer.hpp>

#include <thread>

TerminalRenderer::TerminalRenderer(std::string pipe_name)
{
    pipe = std::make_shared<FifoPipe>(pipe_name);
    pipe->create();
}

TerminalRenderer::~TerminalRenderer()
{
    if (pipe != nullptr && pipe->isOpen())
    {
        pipe->closePipe();
    }
}

void TerminalRenderer::render()
{
    pipe->openPipe();

    for (int i = 0; ; ++i)
    {
        std::string s = "streaming char " + std::to_string(i) + "\n";
        pipe->send(s);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}
