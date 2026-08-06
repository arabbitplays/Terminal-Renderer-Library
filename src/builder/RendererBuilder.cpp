#include <terminal_renderer/builder/RendererBuilder.hpp>

#include <terminal_renderer/transport/StdOutTransport.hpp>
#include <terminal_renderer/TerminalRenderer.hpp>

namespace TerminalRenderer
{
    RendererBuilder::RendererBuilder() : _transport(std::make_shared<StdOutTransport>())
    {

    }

    RendererHandle RendererBuilder::build()
    {
        auto renderer = std::make_shared<TerminalRenderer>(_transport);
        renderer->setRootNode(_root_node);
        return renderer;
    }

    RendererBuilder& RendererBuilder::transport(const TransportHandle& transport)
    {
        _transport = transport;
        return *this;
    }

    RendererBuilder& RendererBuilder::scene(const RenderNodeHandle& root_node)
    {
        _root_node = root_node;
        return *this;
    }
} // TerminalRenderer