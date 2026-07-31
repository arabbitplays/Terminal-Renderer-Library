#include "../../include/terminal_renderer/transport/PipeTransport.hpp"

namespace TerminalRenderer
{
    PipeTransport::PipeTransport(const std::string& pipe_name)
    {
        pipe = std::make_shared<FifoPipe>(pipe_name);
        pipe->create();
    }

    PipeTransport::~PipeTransport()
    {
        if (pipe->isOpen())
        {
            pipe->closePipe();
        }
    }

    void PipeTransport::send(const std::string& data)
    {
        if (!pipe->isOpen())
        {
            pipe->openPipe();
        }
        pipe->send(data);
    }
} // TerminalRenderer
