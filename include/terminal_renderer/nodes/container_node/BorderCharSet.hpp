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

    inline constexpr BorderCharSet light_border_char_set{.top_left=U'┌', .top_right=U'┐', .bottom_left=U'└', .bottom_right=U'┘', .horizontal=U'─', .vertical=U'│'};
    inline constexpr BorderCharSet heavy_border_char_set{.top_left=U'┏', .top_right=U'┓', .bottom_left=U'┗', .bottom_right=U'┛', .horizontal=U'━', .vertical=U'┃'};
    inline constexpr BorderCharSet double_border_char_set{.top_left=U'╔', .top_right=U'╗', .bottom_left=U'╚', .bottom_right=U'╝', .horizontal=U'═', .vertical=U'║'};
    inline constexpr BorderCharSet dotted_border_char_set{.top_left=U'┌', .top_right=U'┐', .bottom_left=U'└', .bottom_right=U'┘', .horizontal=U'┈', .vertical=U'┊'};
    inline constexpr BorderCharSet rounded_border_char_set{.top_left=U'╭', .top_right=U'╮', .bottom_left=U'╰', .bottom_right=U'╯', .horizontal=U'─', .vertical=U'│'};
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_BORDERCHARSET_HPP
