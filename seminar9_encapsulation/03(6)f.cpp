#include "integer.hpp"
#include <iostream>
#include <string>

int main()
{
    Integer a("12345678");
    Integer b("87654321");

    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a * b = " << a * b << "\n";

    Integer f0("0");
    Integer f1("1");

    for (int i = 0; i < 1000; ++i)
    {
        Integer f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }

    std::cout << "F(1000) = " << f0 << "\n";
    std::cout << "F(1000) is even? " << f0.isEven() << "\n";

    Integer fact("1");

    for (int i = 2; i <= 1000; ++i)
        fact *= Integer(std::to_string(i));

    std::cout << "1000! = " << fact << "\n";
}
