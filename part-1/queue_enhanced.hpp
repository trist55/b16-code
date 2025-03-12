#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        assert(this->_size > 0);
        return this->_storage[_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        assert(this->_size > 0);
        return this->_storage[_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        assert(this->_size < this->_storage.size());
        if (this->empty()) {
            if (this->_position == 0) {
                this->_position = this->_storage.size() - 1;
            } else {
                this->_position--;
            }
        }
        auto index = this->_position + this->_size + 1;
        if (index >= this->_storage.size()) { index -= this->_storage.size(); }
        this->_storage[index] = value;
        this->_size++;
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        assert(this->_size >= 1);
        this->_size--;
        this->_position++;
        if (this->_position == this->_storage.size()) {
            this->_position = 0;
        }
    }

    // Remove all elements from the queue
    void clear() { 
        this->_size = 0;
        this->_position = 0;
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        assert(this->_size >= 1);
        auto index = this->_position + 1;
        if (index == this->_storage.size()) { index = 0; }
        return index;
    }
};

#endif // __queue_enhanced__