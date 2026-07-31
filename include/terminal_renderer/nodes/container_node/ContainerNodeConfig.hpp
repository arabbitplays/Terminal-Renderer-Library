#ifndef TERMINAL_RENDERER_LIBRARY_CONTAINERNODECONFIG_HPP
#define TERMINAL_RENDERER_LIBRARY_CONTAINERNODECONFIG_HPP
#include <utility>
#include <terminal_renderer/core/IVec2.hpp>
#include <terminal_renderer/nodes/NodeConfig.hpp>
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <terminal_renderer/nodes/container_node/BorderCharSet.hpp>

namespace TerminalRenderer
{
    struct ContainerNodeConfig : public NodeConfig
    {
        ContainerNodeConfig(RenderNodeHandle child,
                            const BorderCharSet& border_char_set,
                            const IVec2& margin,
                            const bool draw_border,
                            const IVec2& padding)
            : child(std::move(child)),
              border_char_set(border_char_set),
              margin(margin),
              draw_border(draw_border),
              padding(padding) {}

        RenderNodeHandle child;
        BorderCharSet border_char_set;

        IVec2 margin;
        bool draw_border;
        IVec2 padding;
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_CONTAINERNODECONFIG_HPP
