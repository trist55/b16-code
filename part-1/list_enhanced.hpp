
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T> void list_delete_after(Node<T> *node)
{
    auto last_node = node;

    while (node->next) {
        node->value = node->next->value;
        node = node->next.get();
    }

    // Delete the last node
    if (last_node && last_node->next) {
        while (last_node->next->next) {
            last_node = last_node->next.get();
        }
        last_node->next = nullptr;
    }
}

#endif // __list_enhanced__