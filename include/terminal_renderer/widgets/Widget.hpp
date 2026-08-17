#ifndef TERMINAL_RENDERER_LIBRARY_WIDGET_HPP
#define TERMINAL_RENDERER_LIBRARY_WIDGET_HPP
#include <terminal_renderer/nodes/RenderNode.hpp>

namespace TerminalRenderer
{
    class Widget : public RenderNode
    {
    public:
        virtual void onStart() {}
        virtual void onUpdate() {}

        void render(TargetActuator& target_actuator) final
        {
            if (root == nullptr)
            {
                return;
            }
            root->render(target_actuator);
        }

        LayoutInfo getLayoutInfo() final
        {
            if (root == nullptr)
            {
                return {};
            }
            return root->getLayoutInfo();
        }

        RenderNodeHandle getRoot()
        {
            return root;
        }

    protected:
        RenderNodeHandle root;
    };

    using WidgetHandle = std::shared_ptr<Widget>;
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_WIDGET_HPP
