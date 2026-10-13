#ifndef TERMINAL_RENDERER_INPUTHANDLER_HPP
#define TERMINAL_RENDERER_INPUTHANDLER_HPP
#include <terminal_renderer/transport/TerminalTransport.hpp>

#include <vector>

namespace TerminalRenderer
{

    class InputHandler
    {
    public:
        explicit InputHandler(const TransportHandle& transport);

        bool getKeyDown(char c);
        void queryKeys();
        void clearKeys();

    private:
        TransportHandle transport;
        std::vector<char> keys_down{};
    };

} // namespace Timer

#endif // TERMINAL_RENDERER_INPUTHANDLER_HPP
