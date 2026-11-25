#include <iostream>
#include <vector>

void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void doubling(std::vector<int>& v)
{
    std::size_t n = v.size();

    for (std::size_t i = 0; i < n; ++i)
    {
        int x = v[i];
        v.push_back(x);
    }
}

int main()
{
    std::vector<int> v {10, 20, 30};

    doubling(v);
    print(v);
}
