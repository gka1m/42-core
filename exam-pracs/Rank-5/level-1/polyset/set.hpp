#ifndef SET_HPP
#define SET_HPP

#include "../given/searchable_bag.hpp"

class set
{
    private:
        searchable_bag *bag;

    public:
        set() = delete;
        set& operator=(const set& other) = delete;
        set(searchable_bag& b);
        set(const set& other);
        ~set();

        void insert(int value);
        void insert(int *arr, int size);
        bool has(int value) const;
        void print() const;
        void clear();
        searchable_bag& get_bag() const;
};

#endif