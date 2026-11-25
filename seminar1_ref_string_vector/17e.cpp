#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>

std::vector<std::vector<std::size_t>>
calculate_word_lengths(const std::string& filename)
{
    std::vector<std::vector<std::size_t>> result;
    std::ifstream file(filename);

    std::string line;

    while (std::getline(file, line))
    {
        std::vector<std::size_t> line_lengths;
        std::size_t i = 0;

        while (i < line.size())
        {
            while (i < line.size() &&
                   std::isspace(static_cast<unsigned char>(line[i])))
            {
                ++i;
            }

            if (i >= line.size())
                break;

            std::size_t start = i;

            while (i < line.size() &&
                   !std::isspace(static_cast<unsigned char>(line[i])))
            {
                ++i;
            }

            line_lengths.push_back(i - start);
        }

        result.push_back(line_lengths);
    }

    return result;
}

void print(const std::vector<std::vector<std::size_t>>& data)
{
    for (const auto& line : data)
    {
        std::cout << "{ ";
        for (std::size_t x : line)
            std::cout << x << " ";
        std::cout << "}" << std::endl;
    }
}

int main()
{
    const std::string filename = "words_test.txt";

    {
        std::ofstream out(filename);
        out << "one two three\n";
        out << "hello\n";
        out << "axolotl bison cat dog eagle\n";
    }

    auto result = calculate_word_lengths(filename);
    print(result);

    std::remove(filename.c_str());
}
