#ifndef TERMINAL_RENDERER_LIBRARY_STDOUTTRANSPORT_H
#define TERMINAL_RENDERER_LIBRARY_STDOUTTRANSPORT_H
#include <terminal_renderer/transport/TerminalTransport.hpp>

namespace TerminalRenderer
{
    class StdOutTransport : public TerminalTransport
    {
    public:
        void send(const std::string& data) override;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_STDOUTTRANSPORT_H