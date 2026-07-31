#ifndef TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
#define TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP
#include "FifoPipe.hpp"
#include "TerminalTransport.hpp"

namespace TerminalRenderer
{
    class PipeTransport : public TerminalTransport
    {
    public:
        explicit PipeTransport(const std::string& pipe_name);
        ~PipeTransport() override;

        void send(const std::string& data) override;

    private:
        FifoPipeHandle pipe;
    };
} // TerminalRenderer

#endif //TERMINAL_RENDERER_LIBRARY_PIPETRANSPORT_HPP