#ifndef TERMINAL_RENDERER_LIBRARY_VEC3_H
#define TERMINAL_RENDERER_LIBRARY_VEC3_H

#include <algorithm>
#include <functional>

namespace TerminalRenderer
{
    struct Vec3
    {
        float x;
        float y;
        float z;

        constexpr Vec3() : x(0.0f), y(0.0f), z(0.0f)
        {
        }
        constexpr explicit Vec3(float value) : x(value), y(value), z(value)
        {
        }
        constexpr Vec3(float x, float y, float z) : x(x), y(y), z(z)
        {
        }

        constexpr Vec3 operator+(const Vec3& other) const
        {
            return {x + other.x, y + other.y, z + other.z};
        }

        constexpr Vec3 operator-(const Vec3& other) const
        {
            return {x - other.x, y - other.y, z - other.z};
        }

        constexpr Vec3& operator+=(const Vec3& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        constexpr Vec3& operator-=(const Vec3& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        constexpr Vec3 operator*(float scalar) const
        {
            return {x * scalar, y * scalar, z * scalar};
        }

        constexpr Vec3& operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
        }

        constexpr Vec3 operator/(float scalar) const
        {
            return {x / scalar, y / scalar, z / scalar};
        }

        constexpr Vec3& operator/=(float scalar)
        {
            x /= scalar;
            y /= scalar;
            z /= scalar;
            return *this;
        }

        constexpr bool operator==(const Vec3& other) const
        {
            return x == other.x && y == other.y && z == other.z;
        }

        constexpr bool operator!=(const Vec3& other) const
        {
            return !(*this == other);
        }

        static const Vec3 zero;
    };

    inline const Vec3 Vec3::zero{};

    constexpr Vec3 operator*(float scalar, const Vec3& vec)
    {
        return vec * scalar;
    }

    constexpr Vec3 max(const Vec3& a, const Vec3& b)
    {
        return {std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z)};
    }

    constexpr Vec3 min(const Vec3& a, const Vec3& b)
    {
        return {std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z)};
    }
} // namespace TerminalRenderer

namespace std
{
    template <> struct hash<TerminalRenderer::Vec3>
    {
        size_t operator()(const TerminalRenderer::Vec3& vec) const noexcept
        {
            const size_t hx = std::hash<float>{}(vec.x);
            const size_t hy = std::hash<float>{}(vec.y);
            const size_t hz = std::hash<float>{}(vec.z);
            size_t h = hx ^ (hy + 0x9e3779b97f4a7c15ULL + (hx << 6) + (hx >> 2));
            h ^= hz + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
            return h;
        }
    };
} // namespace std

#endif // TERMINAL_RENDERER_LIBRARY_VEC3_H
