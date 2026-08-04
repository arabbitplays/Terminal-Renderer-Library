#ifndef TERMINAL_RENDERER_LIBRARY_LAYOUTEXCEPTION_HPP
#define TERMINAL_RENDERER_LIBRARY_LAYOUTEXCEPTION_HPP
#include <stdexcept>
#include <string>

namespace TerminalRenderer
{
    class LayoutException : public std::runtime_error
    {
    public:
        explicit LayoutException(const std::string& message) : std::runtime_error(message)
        {
        }

        explicit LayoutException(const char* message) : std::runtime_error(message)
        {
        }
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_LAYOUTEXCEPTION_HPP
