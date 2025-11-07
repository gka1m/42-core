#ifndef VECT2_HPP
#define VECT2_HPP


#include <iostream>

class vect2
{
    private:
        int x;
        int y;

    public:
        vect2();
        vect2(const vect2& other);
        vect2(int newx, int newy);
        vect2& operator=(const vect2& other);
        ~vect2();

        // getters/setters
        int getx() const;
        int gety() const;
        void setx(int newx);
        void sety(int newy);

        // mathematical operators
        vect2 operator+(const vect2& r) const;
        vect2 operator-(const vect2& r) const;
        vect2 operator*(int mult) const;

        vect2& operator+=(const vect2& r);
        vect2& operator-=(const vect2& r);
        vect2& operator*=(int mult);

        // increment/decrement
        vect2& operator++();
        vect2& operator--();
        vect2 operator++(int);
        vect2 operator--(int);
        vect2 operator-() const;

        // comparison
        bool operator==(const vect2& r) const;
        bool operator!=(const vect2& r) const;

        // indexing
        int& operator[](int index);
        const int& operator[](int index) const;
};

std::ostream& operator<<(std::ostream& os, const vect2& v);
vect2 operator*(int mult, const vect2& r);

#endif