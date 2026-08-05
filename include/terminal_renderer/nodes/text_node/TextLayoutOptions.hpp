#ifndef TERMINAL_RENDERER_LIBRARY_TEXTLAYOUTOPTIONS_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTLAYOUTOPTIONS_HPP
#include <terminal_renderer/nodes/text_node/TextFlowMode.hpp>

namespace TerminalRenderer
{
    struct TextLayoutOptions
    {
        TextFlowMode flow_mode;
        static TextLayoutOptions createDefault()
        {
            return {.flow_mode = TextFlowMode::CUTOFF};
        }
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_TEXTLAYOUTOPTIONS_HPP