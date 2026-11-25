#include <iostream>

namespace mipt
{
    namespace fefm
    {
        struct Point
        {
            int x, y;
        };
    }
    
    namespace frtk
    {
        void print(fefm::Point p)
        {
            std::cout << p.x << " " << p.y << std::endl;
        }
    }
}

int main()
{
    mipt::fefm::Point p1 = {10, 20};
    mipt::frtk::print(p1);

    using namespace mipt::fefm;
    using namespace mipt::frtk;
    Point p2 = {10, 20};
    print(p2);

    using mipt::fefm::Point;
    using mipt::frtk::print;
    Point p3 = {10, 20};
    print(p3);
}
