#ifndef TERMINAL_RENDERER_LIBRARY_SCENEBUILDER_HPP
#define TERMINAL_RENDERER_LIBRARY_SCENEBUILDER_HPP
#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <terminal_renderer/nodes/ContainerNode.hpp>
#include <terminal_renderer/nodes/GroupNode.hpp>
#include <terminal_renderer/nodes/LeafNode.hpp>

namespace TerminalRenderer
{
    class TextNode;
    class BorderNode;
    class LayoutNode;

    template <typename T>
    class LeafBuilder
    {
    public:
        explicit LeafBuilder(std::shared_ptr<T> node) : node(std::move(node)) {}
        std::shared_ptr<T> build() { return std::move(node); }

    private:
        std::shared_ptr<T> node;
    };

    template <typename T>
    class ContainerBuilder
    {
    public:
        explicit ContainerBuilder(std::shared_ptr<T> node) : node(std::move(node)) {}

        ContainerBuilder& setChild(RenderNodeHandle child)
        {
            node->setChild(std::move(child));
            return *this;
        }

        std::shared_ptr<T> build() { return std::move(node); }

    private:
        std::shared_ptr<T> node;
    };

    template <typename T>
    class GroupBuilder
    {
    public:
        explicit GroupBuilder(std::shared_ptr<T> node) : node(std::move(node)) {}

        GroupBuilder& addChild(RenderNodeHandle child)
        {
            node->addChild(std::move(child));
            return *this;
        }

        GroupBuilder& removeChild(const RenderNodeHandle& child)
        {
            node->removeChild(child);
            return *this;
        }

        std::shared_ptr<T> build() { return std::move(node); }

    private:
        std::shared_ptr<T> node;
    };

    class SceneBuilder
    {
    public:
        LeafBuilder<TextNode> text(std::string text = "") const;

        ContainerBuilder<BorderNode> lightBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        ContainerBuilder<BorderNode> heavyBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        ContainerBuilder<BorderNode> doubleBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        ContainerBuilder<BorderNode> dottedBorder(uint32_t margin = 0, uint32_t padding = 0) const;
        ContainerBuilder<BorderNode> roundedBorder(uint32_t margin = 0, uint32_t padding = 0) const;

        GroupBuilder<LayoutNode> horizontalLayout() const;
        GroupBuilder<LayoutNode> verticalLayout() const;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_SCENEBUILDER_HPP
