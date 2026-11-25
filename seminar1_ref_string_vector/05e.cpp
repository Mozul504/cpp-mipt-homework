#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& b)
{
    return b.price > 1000;
}

int main()
{
    Book b1 = {"Harry Potter", 500, 1200};
    Book b2 = {"The Matrix", 300, 800};

    std::cout << isExpensive(b1) << std::endl; 
    std::cout << isExpensive(b2) << std::endl; 
}
