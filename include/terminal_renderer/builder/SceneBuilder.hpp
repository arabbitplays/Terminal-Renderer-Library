#ifndef TERMINAL_RENDERER_LIBRARY_SCENEBUILDER_HPP
#define TERMINAL_RENDERER_LIBRARY_SCENEBUILDER_HPP
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <terminal_renderer/model/color/StandardColor.hpp>
#include <terminal_renderer/nodes/ContainerNode.hpp>
#include <terminal_renderer/nodes/GroupNode.hpp>
#include <terminal_renderer/nodes/LeafNode.hpp>
#include <utility>

namespace TerminalRenderer
{
    class TextNode;
    class BorderNode;
    class LayoutNode;

    template <typename T> class LeafBuilder
    {
    public:
        explicit LeafBuilder(std::shared_ptr<T> node) : node(std::move(node))
        {
        }
        std::shared_ptr<T> build()
        {
            return std::move(node);
        }

    private:
        std::shared_ptr<T> node;
    };

    template <typename T> class ContainerBuilder
    {
    public:
        explicit ContainerBuilder(std::shared_ptr<T> node) : node(std::move(node))
        {
        }

        ContainerBuilder& setChild(RenderNodeHandle child)
        {
            node->setChild(std::move(child));
            return *this;
        }

        std::shared_ptr<T> build()
        {
            return std::move(node);
        }

    private:
        std::shared_ptr<T> node;
    };

    template <typename T> class GroupBuilder
    {
    public:
        explicit GroupBuilder(std::shared_ptr<T> node) : node(std::move(node))
        {
        }

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

        std::shared_ptr<T> build()
        {
            return std::move(node);
        }

    private:
        std::shared_ptr<T> node;
    };

    class SceneBuilder
    {
    public:
        static LeafBuilder<TextNode> text(std::string text = "", std::optional<ColorHandle> fg_color = std::nullopt,
            std::optional<ColorHandle> bg_color = std::nullopt) ;

        static ContainerBuilder<BorderNode> lightBorder(uint32_t margin = 0, uint32_t padding = 0) ;
        static ContainerBuilder<BorderNode> heavyBorder(uint32_t margin = 0, uint32_t padding = 0) ;
        static ContainerBuilder<BorderNode> doubleBorder(uint32_t margin = 0, uint32_t padding = 0) ;
        static ContainerBuilder<BorderNode> dottedBorder(uint32_t margin = 0, uint32_t padding = 0) ;
        static ContainerBuilder<BorderNode> roundedBorder(uint32_t margin = 0, uint32_t padding = 0) ;

        static GroupBuilder<LayoutNode> horizontalLayout() ;
        static GroupBuilder<LayoutNode> verticalLayout() ;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_SCENEBUILDER_HPP
