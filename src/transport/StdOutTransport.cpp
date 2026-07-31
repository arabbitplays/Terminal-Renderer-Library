#include "../../include/terminal_renderer/transport/StdOutTransport.hpp"

#include <iostream>

namespace TerminalRenderer
{
    void StdOutTransport::send(const std::string& data)
    {
        std::cout << data;
    }
} // TerminalRenderer