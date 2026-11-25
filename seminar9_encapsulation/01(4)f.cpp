#include "circle.hpp"
#include <iostream>

int main()
{
    Circle c1;
    Circle c2({3.0f, 0.0f}, 2.0f);

    std::cout << "area = " << c1.area() << "\n";
    std::cout << "distance = " << c1.distance({5.0f, 0.0f}) << "\n";
    std::cout << "colliding = " << c1.isColliding(c2) << "\n";

    c1.move({1.0f, 1.0f});
    std::cout << "center = (" << c1.getCenter().x << ", "
              << c1.getCenter().y << ")\n";

    c1.setRadius(-5.0f);
    std::cout << "radius after set -5 = " << c1.getRadius() << "\n";
}
