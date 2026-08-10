#include <terminal_renderer/builder/RendererBuilder.hpp>
#include <terminal_renderer/TerminalRenderer.hpp>
#include <terminal_renderer/transport/StdOutTransport.hpp>

namespace TerminalRenderer
{
    RendererBuilder::RendererBuilder() : transport_handle(std::make_shared<StdOutTransport>())
    {
    }

    RendererHandle RendererBuilder::build()
    {
        auto renderer = std::make_shared<TerminalRenderer>(transport_handle);
        renderer->setRootNode(root_node_handle);
        return renderer;
    }

    RendererBuilder& RendererBuilder::transport(const TransportHandle& new_transport)
    {
        transport_handle = new_transport;
        return *this;
    }

    RendererBuilder& RendererBuilder::scene(const RenderNodeHandle& new_root_node)
    {
        root_node_handle = new_root_node;
        return *this;
    }
} // namespace TerminalRenderer