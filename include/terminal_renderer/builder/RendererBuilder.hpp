#ifndef TERMINAL_RENDERER_LIBRARY_RENDERERBUILDER_H
#define TERMINAL_RENDERER_LIBRARY_RENDERERBUILDER_H
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <terminal_renderer/TerminalRenderer.hpp>

namespace TerminalRenderer
{
    class RendererBuilder
    {
    public:
        RendererBuilder();
        ~RendererBuilder() = default;

        RendererHandle build();

        RendererBuilder& transport(const TransportHandle& new_transport);
        RendererBuilder& scene(const RenderNodeHandle& new_root_node);

    private:
        TransportHandle transport_handle;
        RenderNodeHandle root_node_handle;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_RENDERERBUILDER_H