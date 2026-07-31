#ifndef TERMINAL_RENDERER_LIBRARY_TEXTNODECONFIG_HPP
#define TERMINAL_RENDERER_LIBRARY_TEXTNODECONFIG_HPP
#include <cstdint>
#include <string>
#include <utility>
#include <terminal_renderer/nodes/NodeConfig.hpp>

namespace TerminalRenderer
{
    struct TextNodeConfig : public NodeConfig
    {
        TextNodeConfig(std::string text, uint32_t fg_color, uint32_t bg_color)
            : text(std::move(text)), fg_color(fg_color), bg_color(bg_color) {}

        std::string text;
        uint32_t fg_color;
        uint32_t bg_color;
    };
}

#endif //TERMINAL_RENDERER_LIBRARY_TEXTNODECONFIG_HPP
