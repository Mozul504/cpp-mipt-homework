#include "integer.hpp"
#include <algorithm>

Integer::Integer()
    : digits_{0}
{
}

Integer::Integer(const std::string& str)
{
    std::size_t start = 0;

    while (start < str.size() && str[start] == '0')
        ++start;

    if (start == str.size())
    {
        digits_.push_back(0);
        return;
    }

    digits_.reserve(str.size() - start);

    for (std::size_t i = str.size(); i > start; --i)
        digits_.push_back(str[i - 1] - '0');

    trim();
}

void Integer::trim()
{
    while (digits_.size() > 1 && digits_.back() == 0)
        digits_.pop_back();
}

Integer& Integer::operator+=(const Integer& other)
{
    std::size_t oldSize = digits_.size();
    std::size_t otherSize = other.digits_.size();
    std::size_t maxSize = std::max(oldSize, otherSize);

    digits_.resize(maxSize + 1, 0);

    int carry = 0;

    for (std::size_t i = 0; i < maxSize || carry; ++i)
    {
        int sum = carry;

        if (i < oldSize)
            sum += digits_[i];

        if (i < otherSize)
            sum += other.digits_[i];

        digits_[i] = sum % 10;
        carry = sum / 10;
    }

    trim();
    return *this;
}

Integer Integer::operator+(const Integer& other) const
{
    Integer result(*this);
    result += other;
    return result;
}

Integer Integer::operator*(const Integer& other) const
{
    std::vector<unsigned int> tmp(digits_.size() + other.digits_.size(), 0);

    for (std::size_t i = 0; i < digits_.size(); ++i)
    {
        for (std::size_t j = 0; j < other.digits_.size(); ++j)
        {
            tmp[i + j] += static_cast<unsigned int>(digits_[i]) *
                          static_cast<unsigned int>(other.digits_[j]);
        }
    }

    unsigned int carry = 0;

    for (std::size_t i = 0; i < tmp.size(); ++i)
    {
        unsigned int cur = tmp[i] + carry;
        tmp[i] = cur % 10;
        carry = cur / 10;
    }

    while (carry > 0)
    {
        tmp.push_back(carry % 10);
        carry /= 10;
    }

    while (tmp.size() > 1 && tmp.back() == 0)
        tmp.pop_back();

    Integer result;
    result.digits_.clear();
    result.digits_.reserve(tmp.size());

    for (unsigned int x : tmp)
        result.digits_.push_back(static_cast<int>(x));

    return result;
}

Integer& Integer::operator*=(const Integer& other)
{
    *this = *this * other;
    return *this;
}

bool Integer::isEven() const
{
    return digits_[0] % 2 == 0;
}

std::string Integer::toString() const
{
    std::string result;
    result.reserve(digits_.size());

    for (std::size_t i = digits_.size(); i-- > 0;)
        result.push_back(static_cast<char>('0' + digits_[i]));

    return result;
}

std::ostream& operator<<(std::ostream& out, const Integer& n)
{
    return out << n.toString();
}
