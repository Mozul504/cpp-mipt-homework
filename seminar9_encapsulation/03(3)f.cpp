#pragma once
#include <cstddef>
#include <string>
#include <iostream>

class Number
{
private:
    unsigned char* digits_; // младшие разряды в начале
    std::size_t size_;
    std::size_t capacity_;

    void ensureCapacity(std::size_t newCapacity);
    void trim();

public:
    Number();
    Number(const std::string& str);
    Number(const Number& other);
    ~Number();

    Number& operator=(const Number& other);

    Number& operator+=(const Number& other);
    Number operator+(const Number& other) const;

    Number operator*(const Number& other) const;
    Number& operator*=(const Number& other);

    bool isEven() const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& out, const Number& n);
};
