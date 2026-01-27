#ifndef SEARCHABLE_TREE_BAG
#define SEARCHABLE_TREE_BAG

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, searchable_bag
{
    searchable_tree_bag();
    searchable_tree_bag(const searchable_tree_bag& other);
    searchable_tree_bag& operator=(const searchable_tree_bag& other);
    ~searchable_tree_bag();

    bool has(int val) const override;
}
#endif