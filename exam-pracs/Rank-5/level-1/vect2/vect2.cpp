#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int newx, int newy) : x(newx), y(newy) {}

vect2::vect2(const vect2& other) : x(other.x), y(other.y) {}

vect2::~vect2() {}

int vect2::getx() const
{
    return x;
}

int vect2::gety() const
{
    return y;
}

void vect2::setx(int newx)
{
    x = newx;
}

void vect2::sety(int newy)
{
    y = newy;
}

vect2& vect2::operator=(const vect2& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

vect2 vect2::operator+(const vect2& r) const
{
    return vect2(x + r.x, y + r.y);
}

vect2 vect2::operator-(const vect2& r) const
{
    return vect2(x - r.x, y - r.y);
}

vect2 vect2::operator*(int mult) const
{
    return vect2(x * mult, y * mult);
}

vect2& vect2::operator+=(const vect2& r)
{
    x += r.x;
    y += r.y;
    return *this;
}

vect2& vect2::operator-=(const vect2& r)
{
    x -= r.x;
    y -= r.y;
    return *this;
}

vect2& vect2::operator*= (int mult)
{
    x *= mult;
    y *= mult;
    return *this;
}

vect2& vect2::operator++()
{
    ++x;
    ++y;
    return *this;
}

vect2& vect2::operator--()
{
    --x;
    --y;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 temp(*this);
    ++(*this);
    return temp;
}

vect2 vect2::operator--(int)
{
    vect2 temp(*this);
    --(*this);
    return temp;
}

vect2 vect2::operator-() const
{
    return vect2(-x, -y);
}

bool vect2::operator==(const vect2& r) const
{
    return (x == r.x) && (y == r.y);
}

bool vect2::operator!=(const vect2& r) const
{
    return !(*this == r);
}

int& vect2::operator[](int index)
{
    if (index == 0)
        return x;
    else
        return y;
}

const int& vect2::operator[](int index) const
{
    if (index == 0)
        return x;
    else
        return y;
}

std::ostream& operator<<(std::ostream& os, const vect2& v)
{
    return os << "x: " << v.getx() << ",\n"
    << "y: " << v.gety(); 
}

vect2 operator*(int mult, const vect2& r)
{
    return r * mult;
}