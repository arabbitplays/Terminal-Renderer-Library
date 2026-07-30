#include <terminal_renderer/pipes/FifoPipe.hpp>

#include <assert.h>
#include <csignal>
#include <cstring>
#include <fcntl.h>
#include <stdexcept>
#include <unistd.h>
#include <sys/stat.h>

FifoPipe::FifoPipe(const std::string& name) : name(name)
{
}

void FifoPipe::create() const
{
    if (mkfifo(name.c_str(), 0600) == -1 && errno != EEXIST)
    {
        throw std::runtime_error("Failed to create fifo pipe " + name + ": " + std::strerror(errno));
    }
}

void FifoPipe::openPipe()
{
    assert(!is_open);
    fd = open(name.c_str(), O_WRONLY);
    if (fd == -1)
    {
        throw std::runtime_error("Failed to open fifo pipe: " + name + ": " + std::strerror(errno));
    }

    signal(SIGPIPE, SIG_IGN); // don't die if the window is closed
    is_open = true;
}

void FifoPipe::send(const std::string& data) const
{
    assert(is_open);
    if (write(fd, data.data(), data.size()) == -1)
    {
        throw std::runtime_error("Failed to write to fifo pipe: " + name + ": " + std::strerror(errno));
    }
}

void FifoPipe::closePipe()
{
    assert(is_open);
    close(fd);
    is_open = false;
}

std::string& FifoPipe::getName()
{
    return name;
}

bool FifoPipe::isOpen() const
{
    return is_open;
}
