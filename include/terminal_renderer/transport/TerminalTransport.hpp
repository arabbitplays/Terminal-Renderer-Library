#ifndef TERMINAL_RENDERER_LIBRARY_TERMINALTRANSPORT_HPP
#define TERMINAL_RENDERER_LIBRARY_TERMINALTRANSPORT_HPP
#include <memory>

namespace TerminalRenderer
{
    class TerminalTransport
    {
    public:
        virtual ~TerminalTransport() = default;

        virtual void send(const std::string& data) = 0;
    };

    typedef std::shared_ptr<TerminalTransport> TransportHandle;
}
#endif //TERMINAL_RENDERER_LIBRARY_TERMINALTRANSPORT_HPP
