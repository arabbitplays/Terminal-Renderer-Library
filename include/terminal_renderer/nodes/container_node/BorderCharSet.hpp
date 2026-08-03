#ifndef TERMINAL_RENDERER_LIBRARY_BORDERCHARSET_HPP
#define TERMINAL_RENDERER_LIBRARY_BORDERCHARSET_HPP

namespace TerminalRenderer
{
    struct BorderCharSet
    {
        char32_t top_left;
        char32_t top_right;
        char32_t bottom_left;
        char32_t bottom_right;
        char32_t horizontal;
        char32_t vertical;
    };

    inline constexpr BorderCharSet LIGHT_BORDER_CHAR_SET{U'┌', U'┐', U'└', U'┘', U'─', U'│'};
    inline constexpr BorderCharSet HEAVY_BORDER_CHAR_SET{U'┏', U'┓', U'┗', U'┛', U'━', U'┃'};
    inline constexpr BorderCharSet DOUBLE_BORDER_CHAR_SET{U'╔', U'╗', U'╚', U'╝', U'═', U'║'};
    inline constexpr BorderCharSet DOTTED_BORDER_CHAR_SET{U'┌', U'┐', U'└', U'┘', U'┈', U'┊'};
    inline constexpr BorderCharSet ROUNDED_BORDER_CHAR_SET{U'╭', U'╮', U'╰', U'╯', U'─', U'│'};
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_BORDERCHARSET_HPP
