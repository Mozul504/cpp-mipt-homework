#pragma once
#include <vector>
#include <string>
#include <iostream>

class Integer
{
private:
    std::vector<int> digits_; // младшие разряды в начале

    void trim();

public:
    Integer();
    Integer(const std::string& str);
    Integer(const Integer& other) = default;
    Integer& operator=(const Integer& other) = default;

    Integer& operator+=(const Integer& other);
    Integer operator+(const Integer& other) const;

    Integer operator*(const Integer& other) const;
    Integer& operator*=(const Integer& other);

    bool isEven() const;
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& out, const Integer& n);
};
