#ifndef MANIPULATORS_HPP
#define MANIPULATORS_HPP

#include <iostream>

namespace streams {

// Comma

std::ostream& comma(std::ostream& os);

// Colon

std::ostream& colon(std::ostream& os);

// Index

class index
{
    int x;
    int w;

    friend std::ostream& operator<<(std::ostream& os, const index& idx);

public:

    index(int x, int w);
};

std::ostream& operator<<(std::ostream& os, const index& idx);

// Ignore

class ignore
{
    int x;

    friend std::istream& operator>>(std::istream& is, const ignore& ign);

public:
    ignore(int x);
};

std::istream& operator>>(std::istream& is, const ignore& ign);


// Clearline

std::istream& clearline(std::istream& is);

}

#endif