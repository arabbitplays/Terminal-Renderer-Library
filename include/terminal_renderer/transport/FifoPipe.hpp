#ifndef YAKSHA_FIFOPIPE_HPP
#define YAKSHA_FIFOPIPE_HPP
#include <memory>
#include <string>

namespace TerminalRenderer
{
    class FifoPipe
    {
    public:
        explicit FifoPipe(std::string  name);
        ~FifoPipe() = default;

        void create() const;
        void openPipe();
        void send(const std::string& data) const;
        void closePipe();

        std::string& getName();
        bool isOpen() const;

    private:
        std::string name;
        bool is_open = false;
        int fd = -1;
    };

    using FifoPipeHandle = std::shared_ptr<FifoPipe>;
} // namespace TerminalRenderer

#endif // YAKSHA_FIFOPIPE_HPP