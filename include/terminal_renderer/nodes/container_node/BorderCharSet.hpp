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

        static const BorderCharSet LightBorderCharSet;
    };

    inline const BorderCharSet BorderCharSet::LightBorderCharSet{U'┌', U'┐', U'└', U'┘', U'─', U'│'};
}

#endif //TERMINAL_RENDERER_LIBRARY_BORDERCHARSET_HPP