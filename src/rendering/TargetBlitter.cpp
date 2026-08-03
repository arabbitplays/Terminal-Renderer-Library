#include <format>
#include <terminal_renderer/rendering/AnsiCodeUtil.hpp>
#include <terminal_renderer/rendering/TargetBlitter.hpp>
#include <utility>

namespace TerminalRenderer
{
    TargetBlitter::TargetBlitter(TransportHandle transport)
        : transport(std::move(transport)), last_target(std::make_shared<RenderTarget>(IVec2::zero))
    {
        setCursorVisibility(false);
    }

    TargetBlitter::~TargetBlitter()
    {
        setCursorVisibility(true);
    }

    void TargetBlitter::blit(const RenderTargetHandle& target)
    {
        if (last_target->getExtent() != target->getExtent())
        {
            last_target = std::make_shared<RenderTarget>(target->getExtent());
            clear();
        }

        IVec2 extent = target->getExtent();

        std::string framebuffer;
        for (int32_t y = 0; y < extent.y; ++y)
        {
            for (int32_t x = 0; x < extent.x; ++x)
            {
                IVec2 pos{x, y};
                Cell cell = target->getCell(pos);
                if (cell != last_target->getCell(pos))
                {
                    framebuffer += getCursorMoveString(pos);
                    framebuffer += getCellString(cell);

                    last_target->setCell(pos, cell);
                }
            }
        }
        transport->send(framebuffer);
    }

    std::string TargetBlitter::getCellString(const Cell& cell)
    {
        std::string result;
        if (cell.fg_color.has_value())
        {
            result += AnsiCodeUtil::toAnsiForegroundColorCode(cell.fg_color.value()->get256ColorIndex());
        }

        if (cell.bg_color.has_value())
        {
            result += AnsiCodeUtil::toAnsiBackgroundColorCode(cell.bg_color.value()->get256ColorIndex());
        }

        result += toUtf8(cell.c);

        if (cell.fg_color.has_value() || cell.bg_color.has_value())
        {
            result += AnsiCodeUtil::reset_code;
        }

        return result;
    }

    void TargetBlitter::clear() const
    {
        transport->send("\x1b[2J");
    }

    std::string TargetBlitter::getCursorMoveString(IVec2 pos)
    {
        return std::format("\x1b[{};{}H", pos.y + 1, pos.x + 1);
    }

    void TargetBlitter::setCursorVisibility(bool visible)
    {
        if (visible)
        {
            transport->send("\x1b[?25h");
        }
        else
        {
            transport->send("\x1b[?25l");
        }
    }

    std::string TargetBlitter::toUtf8(char32_t cp)
    {
        if (cp == 0)
        {
            return " ";
        }

        std::string out;
        uint32_t c = cp;
        if (c <= 0x7F)
        {
            out += static_cast<char>(c);
        }
        else if (c <= 0x7FF)
        {
            out += static_cast<char>(0xC0 | (c >> 6));
            out += static_cast<char>(0x80 | (c & 0x3F));
        }
        else if (c <= 0xFFFF)
        {
            out += static_cast<char>(0xE0 | (c >> 12));
            out += static_cast<char>(0x80 | ((c >> 6) & 0x3F));
            out += static_cast<char>(0x80 | (c & 0x3F));
        }
        else
        {
            // up to 0x10FFFF
            out += static_cast<char>(0xF0 | (c >> 18));
            out += static_cast<char>(0x80 | ((c >> 12) & 0x3F));
            out += static_cast<char>(0x80 | ((c >> 6) & 0x3F));
            out += static_cast<char>(0x80 | (c & 0x3F));
        }
        return out;
    }
} // namespace TerminalRenderer
