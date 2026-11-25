#include "circle.hpp"
#include <cmath>
#include <algorithm>

Circle::Circle()
    : center_{0.0f, 0.0f}, radius_(1.0f)
{
}

Circle::Circle(const Point& center, float radius)
    : center_(center), radius_(radius)
{
    if (radius_ < 0.0f)
        radius_ = 0.0f;
}

Circle::Circle(const Circle& other)
    : center_(other.center_), radius_(other.radius_)
{
}

const Point& Circle::getCenter() const
{
    return center_;
}

void Circle::setCenter(const Point& center)
{
    center_ = center;
}

float Circle::getRadius() const
{
    return radius_;
}

void Circle::setRadius(float radius)
{
    if (radius < 0.0f)
        radius = 0.0f;
    radius_ = radius;
}

float Circle::area() const
{
    const float pi = 3.14159265358979323846f;
    return pi * radius_ * radius_;
}

float Circle::distance(const Point& p) const
{
    float dx = p.x - center_.x;
    float dy = p.y - center_.y;
    float d = std::sqrt(dx * dx + dy * dy);
    return std::fabs(d - radius_);
}

bool Circle::isColliding(const Circle& c) const
{
    float dx = center_.x - c.center_.x;
    float dy = center_.y - c.center_.y;
    float d = std::sqrt(dx * dx + dy * dy);
    return d <= radius_ + c.radius_;
}

void Circle::move(const Point& p)
{
    center_.x += p.x;
    center_.y += p.y;
}
