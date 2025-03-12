#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <vector>
#include <memory>

// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    std::shared_ptr<BinaryTreeEnhanced<V>> _left;
    std::shared_ptr<BinaryTreeEnhanced<V>> _right;

    std::weak_ptr<BinaryTreeEnhanced<V>> _parent;

    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t)
    {
        return t->_left_value;
    }
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        return t->_parent.lock().get();
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::shared_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::shared_ptr<BinaryTreeEnhanced<V>> l,
                          std::shared_ptr<BinaryTreeEnhanced<V>> r)
{
    auto tree = std::make_shared<BinaryTreeEnhanced<V>>(BinaryTreeEnhanced<V>{value, std::move(l), std::move(r)});

    if (tree->_left) {
        tree->_left->_parent = tree;
    }

    if (tree->_right) {
        tree->_right->_parent = tree;
    }

    return tree;
}

#endif // __binary_tree_enhanced__