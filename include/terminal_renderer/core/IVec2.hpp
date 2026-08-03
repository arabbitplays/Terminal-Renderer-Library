#ifndef TERMINAL_RENDERER_LIBRARY_IVEC2_H
#define TERMINAL_RENDERER_LIBRARY_IVEC2_H

#include <cstdint>
#include <functional>

namespace TerminalRenderer
{
    struct IVec2
    {
        int32_t x;
        int32_t y;

        constexpr IVec2() : x(0), y(0)
        {
        }
        constexpr explicit IVec2(int32_t value) : x(value), y(value)
        {
        }
        constexpr IVec2(int32_t x, int32_t y) : x(x), y(y)
        {
        }

        constexpr IVec2 operator+(const IVec2& other) const
        {
            return {x + other.x, y + other.y};
        }

        constexpr IVec2 operator-(const IVec2& other) const
        {
            return {x - other.x, y - other.y};
        }

        constexpr IVec2& operator+=(const IVec2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        constexpr IVec2 operator*(int32_t scalar) const
        {
            return {x * scalar, y * scalar};
        }

        constexpr IVec2& operator*=(int32_t scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        constexpr bool operator==(const IVec2& other) const
        {
            return x == other.x && y == other.y;
        }

        constexpr bool operator!=(const IVec2& other) const
        {
            return !(*this == other);
        }

        static const IVec2 zero;
    };

    inline const IVec2 IVec2::zero{};

    constexpr IVec2 operator*(int32_t scalar, const IVec2& vec)
    {
        return vec * scalar;
    }
} // namespace TerminalRenderer

namespace std
{
    template <> struct hash<TerminalRenderer::IVec2>
    {
        size_t operator()(const TerminalRenderer::IVec2& vec) const noexcept
        {
            const size_t hx = std::hash<int32_t>{}(vec.x);
            const size_t hy = std::hash<int32_t>{}(vec.y);
            return hx ^ (hy + 0x9e3779b97f4a7c15ULL + (hx << 6) + (hx >> 2));
        }
    };
} // namespace std

#endif // TERMINAL_RENDERER_LIBRARY_IVEC2_H
