#pragma once
#include <iostream>

struct Vector2f
{
    float x = 0.0f;
    float y = 0.0f;
};

Vector2f operator+(const Vector2f& a, const Vector2f& b);
Vector2f operator-(const Vector2f& a, const Vector2f& b);

Vector2f operator*(const Vector2f& a, float k);
Vector2f operator*(float k, const Vector2f& a);

float operator*(const Vector2f& a, const Vector2f& b);

Vector2f operator-(const Vector2f& a);
Vector2f operator+(const Vector2f& a);

bool operator==(const Vector2f& a, const Vector2f& b);
bool operator!=(const Vector2f& a, const Vector2f& b);

Vector2f& operator+=(Vector2f& a, const Vector2f& b);
Vector2f& operator-=(Vector2f& a, const Vector2f& b);
Vector2f& operator*=(Vector2f& a, float k);
Vector2f& operator/=(Vector2f& a, float k);

Vector2f operator/(const Vector2f& a, float k);

std::ostream& operator<<(std::ostream& out, const Vector2f& v);
std::istream& operator>>(std::istream& in, Vector2f& v);
