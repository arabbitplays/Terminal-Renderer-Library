#ifndef TERMINAL_RENDERER_LIBRARY_SCENEEXAMPLE_HPP
#define TERMINAL_RENDERER_LIBRARY_SCENEEXAMPLE_HPP
#include <terminal_renderer/nodes/RenderNode.hpp>

namespace TerminalRenderer
{
    class SceneExample
    {
    public:
        static RenderNodeHandle layoutTestScene();
        static RenderNodeHandle textTestScene();
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_SCENEEXAMPLE_HPP
