#ifndef TERMINAL_RENDERER_LIBRARY_NODEFACTORY_HPP
#define TERMINAL_RENDERER_LIBRARY_NODEFACTORY_HPP
#include <cstdint>
#include <memory>
#include <string>

namespace TerminalRenderer
{
    class TextNode;
    class ContainerNode;

    class NodeFactory
    {
    public:
        std::shared_ptr<TextNode> createText(std::string text) const;
        std::shared_ptr<ContainerNode> createLightBorder(uint32_t margin, uint32_t padding) const;
        std::shared_ptr<ContainerNode> createHeavyBorder(uint32_t margin, uint32_t padding) const;
        std::shared_ptr<ContainerNode> createDoubleBorder(uint32_t margin, uint32_t padding) const;
        std::shared_ptr<ContainerNode> createDottedBorder(uint32_t margin, uint32_t padding) const;
        std::shared_ptr<ContainerNode> createRoundedBorder(uint32_t margin, uint32_t padding) const;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_NODEFACTORY_HPP
