#include <iostream>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <thread>
#include <terminal_renderer/transport/StdOutTransport.hpp>

namespace TerminalRenderer
{
    TerminalRenderer::TerminalRenderer() : transport(std::make_shared<StdOutTransport>())
    {
        init();
    }

    TerminalRenderer::TerminalRenderer(const TransportHandle& transport) : transport(transport)
    {
        init();
    }

    void TerminalRenderer::render()
    {
        for (int i = 0; ; ++i)
        {
            transport->pollEvents();
            std::string s = "streaming char " + std::to_string(i) + "\n";
            //transport->send(s);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void TerminalRenderer::init()
    {
        transport->setResizeCallback([this](const Viewport& vp)
        {
            initRenderTarget(vp);
        });
        initRenderTarget(transport->getViewport());
    }

    void TerminalRenderer::initRenderTarget(const Viewport& vp)
    {
        viewport = vp;
        std::cout << viewport.extent.x << " " << viewport.extent.y << std::endl;
    }
}
