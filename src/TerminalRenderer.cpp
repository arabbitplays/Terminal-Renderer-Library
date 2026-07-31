#include <terminal_renderer/TerminalRenderer.hpp>
#include <thread>
#include <terminal_renderer/transport/StdOutTransport.hpp>

namespace TerminalRenderer
{
    TerminalRenderer::TerminalRenderer() : transport(std::make_shared<StdOutTransport>())
    {
    }

    TerminalRenderer::TerminalRenderer(const TransportHandle& transport) : transport(transport)
    {
    }

    void TerminalRenderer::render()
    {
        for (int i = 0; ; ++i)
        {
            std::string s = "streaming char " + std::to_string(i) + "\n";
            transport->send(s);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}
