#ifndef TERMINAL_RENDERER_LIBRARY_SCENEEXAMPLE_HPP
#define TERMINAL_RENDERER_LIBRARY_SCENEEXAMPLE_HPP
#include <string>
#include <terminal_renderer/nodes/RenderNode.hpp>

namespace TerminalRenderer
{
    class SceneExample
    {
    public:
        static RenderNodeHandle layoutTestScene();
        static RenderNodeHandle colorTestScene();
        static RenderNodeHandle textTestScene();

    private:
        inline static const std::string lorem_ipsum = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet\n\nLorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.";
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_SCENEEXAMPLE_HPP
