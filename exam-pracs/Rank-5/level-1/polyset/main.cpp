#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include <cstdlib>
#include <iostream>
#include "set.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
        return 1;

    searchable_bag* tree = new searchable_tree_bag;
    searchable_bag* arr = new searchable_array_bag;

    for (int i = 1; i < ac; i++)
    {
        tree->insert(atoi(av[i]));
        arr->insert(atoi(av[i]));
    }
    tree->print();
    tree->arr();

    for (int i = 1; i < ac; i++)
    {
        std::cout << tree->has(atoi(av[i])) << "\n"
        << arr->has(atoi(av[i])) << "\n"
        << tree->has(atoi(av[i - 1])) << "\n"
        << arr->has(atoi(av[i - 1])) << std::endl;
    }

    tree->clear();
    arr->clear();

    
}