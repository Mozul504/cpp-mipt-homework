#pragma once
#include "point.hpp"

class Circle
{
private:
    Point center_;
    float radius_;

public:
    Circle();
    Circle(const Point& center, float radius);
    Circle(const Circle& other);

    const Point& getCenter() const;
    void setCenter(const Point& center);

    float getRadius() const;
    void setRadius(float radius);

    float area() const;
    float distance(const Point& p) const;
    bool isColliding(const Circle& c) const;
    void move(const Point& p);
};
