#ifndef TERMINAL_RENDERER_LIBRARY_NODEFACTORY_HPP
#define TERMINAL_RENDERER_LIBRARY_NODEFACTORY_HPP
#include <cstdint>
#include <memory>
#include <string>

namespace TerminalRenderer
{
    class TextNode;
    class ContainerNode;
    class HorizontalLayout;

    class NodeFactory
    {
    public:
        std::shared_ptr<TextNode> createText(std::string text) const;
        std::shared_ptr<ContainerNode> createLightBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        std::shared_ptr<ContainerNode> createHeavyBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        std::shared_ptr<ContainerNode> createDoubleBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        std::shared_ptr<ContainerNode> createDottedBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        std::shared_ptr<ContainerNode> createRoundedBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        std::shared_ptr<HorizontalLayout> createHorizontalLayout() const;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_NODEFACTORY_HPP
