#ifndef TERMINAL_RENDERER_LIBRARY_TARGETBLITTER_HPP
#define TERMINAL_RENDERER_LIBRARY_TARGETBLITTER_HPP
#include <terminal_renderer/model/RenderTarget.hpp>
#include <terminal_renderer/transport/TerminalTransport.hpp>

namespace TerminalRenderer
{
    class TargetBlitter
    {
    public:
        explicit TargetBlitter(TransportHandle  transport);
        ~TargetBlitter();

        void blit(const RenderTargetHandle& target);
        static std::string getCellString(const Cell& cell);

    private:
        void clear() const;
        [[nodiscard]] static std::string getCursorMoveString(IVec2 pos) ;
        void setCursorVisibility(bool visible);
        static std::string toUtf8(char32_t cp);

        TransportHandle transport;
        RenderTargetHandle last_target;
    };
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_TARGETBLITTER_HPP
