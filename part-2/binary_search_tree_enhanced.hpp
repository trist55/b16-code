#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    auto t = tree;
    while (left(t)) {
        t = left(t);
    }
    return t;
}

template <typename T> T bst_max(const T &tree)
{
    auto t = tree;
    while (right(t)) {
        t = right(t);
    }
    return t;
}

#endif // __binary_saerch_tree_enhanced__