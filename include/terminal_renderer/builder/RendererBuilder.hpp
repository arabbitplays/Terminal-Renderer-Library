#ifndef TERMINAL_RENDERER_LIBRARY_RENDERERBUILDER_H
#define TERMINAL_RENDERER_LIBRARY_RENDERERBUILDER_H
#include "terminal_renderer/TerminalRenderer.hpp"
#include "terminal_renderer/nodes/RenderNode.hpp"

namespace TerminalRenderer
{
    class RendererBuilder
    {
    public:
        RendererBuilder();
        ~RendererBuilder() = default;

        RendererHandle build();

        RendererBuilder& transport(const TransportHandle& transport);
        RendererBuilder& scene(const RenderNodeHandle& root_node);

    private:
        TransportHandle _transport;
        RenderNodeHandle _root_node;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_RENDERERBUILDER_H