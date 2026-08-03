#ifndef TERMINAL_RENDERER_LIBRARY_STDOUTTRANSPORT_H
#define TERMINAL_RENDERER_LIBRARY_STDOUTTRANSPORT_H
#include <atomic>
#include <terminal_renderer/transport/TerminalTransport.hpp>

namespace TerminalRenderer
{
    class StdOutTransport : public TerminalTransport
    {
    public:
        StdOutTransport();
        ~StdOutTransport() override;

        StdOutTransport(const StdOutTransport&) = delete;
        StdOutTransport& operator=(const StdOutTransport&) = delete;

        void send(const std::string& data) override;
        Viewport getViewport() override;

        void setResizeCallback(ResizeCallback callback) override;
        void pollEvents() override;

    private:
        static void onWinch(int /*unused*/);
        static std::atomic<bool> resized;

        ResizeCallback resize_callback;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_STDOUTTRANSPORT_H
