#include "manipulators.hpp"
#include <stdexcept>

std::ostream& streams::comma(std::ostream& os)
{
    os << ", ";
    return os;
}

std::ostream& streams::colon(std::ostream& os)
{
    os << ": ";
    return os;
}

// Index
std::ostream& streams::operator<<(std::ostream& os, const streams::index& idx)
{
    os << "[";

    auto number = std::to_string(idx.x);
    int offset = idx.w - number.length();

    for (int i = 0; i < offset; i++)
        os << " ";
    
    os << number;

    os << "]";
    return os;
}

streams::index::index(int x, int w)
{
    if (w < 0)
        throw std::invalid_argument("index(): \"w\" can't be negative!");

    this->x = x;
    this->w = w;
}

// Ignore
std::istream& streams::operator>>(std::istream& is, const streams::ignore& ign)
{
    char c;
    int counter = 0;

    while (counter < ign.x)
    {
        counter++;
        c = is.get();

        if (c == EOF or c == '\n')
            break;
    }

    return is;
}

std::istream& streams::clearline(std::istream& is)
{
    std::string str;
    getline(is, str);

    return is;
}

streams::ignore::ignore(int x)
{
    if (x < 0)
        throw std::invalid_argument("ignore(): number of characters can't be negative!");
    this->x = x;
}