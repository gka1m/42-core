#include "set.hpp"
#include <iostream>

set::set(searchable_bag& b) : bag(&b) {}

set::set(const set& other) : bag(other.bag) {}

set::~set() = default;

void set::insert(int val)
{
    if (!has(val))
        bag->insert(val);
}

void set::insert(int* array, int size)
{
    for (int i = 0; i < size; i++)
        insert(array[i]);
}

bool set::has(int val) const
{
    return bag->has(val);
}

void set::print() const
{
    return bag->print();
}

void set::clear()
{
    return bag->clear();
}

searchable_bag& set::get_bag() const
{
    return *bag;
}