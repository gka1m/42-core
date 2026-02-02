#include "set.hpp"

set::set(searchable_bag& b) : bag(&b) {}

set::set(const set& other) : bag(other.bag) {}

set::~set() {}

bool set::has(int value) const
{
    return bag->has(value);
}

void set::print() const
{
    return bag->print();
}

void set::clear()
{
    return bag->clear();
}

void set::insert(int value)
{
    if (!has(value))
        bag->insert(value);
}

void set::insert(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        insert(arr[i]);
}

searchable_bag& set::get_bag() const
{
    return *bag;
}