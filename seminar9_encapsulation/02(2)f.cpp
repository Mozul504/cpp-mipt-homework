#include "vector2f.hpp"

Vector2f operator+(const Vector2f& a, const Vector2f& b)
{
    return {a.x + b.x, a.y + b.y};
}

Vector2f operator-(const Vector2f& a, const Vector2f& b)
{
    return {a.x - b.x, a.y - b.y};
}

Vector2f operator*(const Vector2f& a, float k)
{
    return {a.x * k, a.y * k};
}

Vector2f operator*(float k, const Vector2f& a)
{
    return a * k;
}

float operator*(const Vector2f& a, const Vector2f& b)
{
    return a.x * b.x + a.y * b.y;
}

Vector2f operator-(const Vector2f& a)
{
    return {-a.x, -a.y};
}

Vector2f operator+(const Vector2f& a)
{
    return a;
}

bool operator==(const Vector2f& a, const Vector2f& b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vector2f& a, const Vector2f& b)
{
    return !(a == b);
}

Vector2f& operator+=(Vector2f& a, const Vector2f& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2f& operator-=(Vector2f& a, const Vector2f& b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2f& operator*=(Vector2f& a, float k)
{
    a.x *= k;
    a.y *= k;
    return a;
}

Vector2f& operator/=(Vector2f& a, float k)
{
    a.x /= k;
    a.y /= k;
    return a;
}

Vector2f operator/(const Vector2f& a, float k)
{
    return {a.x / k, a.y / k};
}

std::ostream& operator<<(std::ostream& out, const Vector2f& v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2f& v)
{
    in >> v.x >> v.y;
    return in;
}
