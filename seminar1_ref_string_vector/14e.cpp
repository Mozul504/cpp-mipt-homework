#include <iostream>
#include <string>
#include <vector>

std::vector<std::size_t> substringIndexes(const std::string& str,
                                          const std::string& sub)
{
    std::vector<std::size_t> result;

    if (sub.empty())
        return result;

    std::size_t pos = str.find(sub);

    while (pos != std::string::npos)
    {
        result.push_back(pos);
        pos = str.find(sub, pos + 1);
    }

    return result;
}

void print(const std::vector<std::size_t>& v)
{
    for (std::size_t x : v)
        std::cout << x << " ";
    std::cout << std::endl;
}

int main()
{
    print(substringIndexes("cat and dog and cat", "cat")); 
    print(substringIndexes("look, cats were here", "cat")); 
    print(substringIndexes("catcatcatcatcatcat", "cat"));   
    print(substringIndexes("dog mouse elephant", "cat"));   
}
