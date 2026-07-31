#ifndef YAKSHA_TERMINALRENDERER_HPP
#define YAKSHA_TERMINALRENDERER_HPP
#include <memory>
#include <string>

#include "transport/TerminalTransport.hpp"


namespace TerminalRenderer
{
    class TerminalRenderer
    {
    public:
        TerminalRenderer();
        explicit TerminalRenderer(const TransportHandle& transport);
        ~TerminalRenderer() = default;

        void render();
    private:
        TransportHandle transport;
    };

    typedef std::shared_ptr<TerminalRenderer> RendererHandle;
}


#endif //YAKSHA_TERMINALRENDERER_HPP
