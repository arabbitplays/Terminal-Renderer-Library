#include <terminal_renderer/transport/InputHandler.hpp>

namespace TerminalRenderer
{
    InputHandler::InputHandler(const TransportHandle& transport) : transport(transport)
    {

    }

    bool InputHandler::getKeyDown(char c)
    {
        queryKeys();
        for (const auto& key : keys_down)
        {
            if (key == c)
                return true;
        }
        return false;
    }

    void InputHandler::queryKeys()
    {
        int key = transport->readKey();
        while (key > 0)
        {
            keys_down.push_back(key);
            key = transport->readKey();
        }
    }

    void InputHandler::clearKeys()
    {
        keys_down.clear();
    }
} // namespace Timer