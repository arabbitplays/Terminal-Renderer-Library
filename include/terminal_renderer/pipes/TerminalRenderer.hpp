#ifndef YAKSHA_TERMINALRENDERER_HPP
#define YAKSHA_TERMINALRENDERER_HPP
#include <string>

#include <terminal_renderer/pipes/FifoPipe.hpp>


class TerminalRenderer
{
public:
    TerminalRenderer(std::string pipe_name);
    ~TerminalRenderer();
    void render();

private:
    FifoPipeHandle pipe;
};

typedef std::shared_ptr<TerminalRenderer> TerminalRendererHandle;


#endif //YAKSHA_TERMINALRENDERER_HPP
