#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;

    for (char c : str)
    {
        unsigned char uc = static_cast<unsigned char>(c);

        if (std::isalpha(uc))
            ++numLetters;
        else if (std::isdigit(uc))
            ++numDigits;
    }
}

int main()
{
    std::string s = "Hello123World";
    int letters = 0;
    int digits = 0;

    countLetters(s, letters, digits);

    std::cout << letters << " " << digits << std::endl; 
}
