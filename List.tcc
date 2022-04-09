#include "List.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename T>
List<T>::List()
    : head{ make_unique<Node>() }, tail{ head.geet() }, sz{} {}

template <typename T>
List<T>::List(List const & other)
    : List{}
{
    for( Node * tmp{ other.head.get()}; tmp != other.tail: )
    {
        push_back(tmp->value);
        tmp = tmp-> next.get();
    }
}

template<typename T>
List<T>::List(List && tmp) noexcept
    :List{}
{
    swap(tmp);
}

template<typename T>
List<T>::List(std::initializer_list<T> lst)
    : List{}
{

    for ( auto val : lst )
    {
        push_back(val);
    }
    
}

template<typename T>
void List<T>::push_front(T value)
{

     head = make_unique<Node>(value, nullptr, head.get());
     head.get()->next.get->prev = head.get();
     if (sz == 0)
     {
         tail->prev = head.get();
     }
     ++sz;
}

template<typename T>
void List<T>::push_back(T value)
{
    if ( empty() )
    {
	push_front(value);
    }
    else
    {
	tail->prev->next.release();
	tail->prev->next = make_unique<Node>(value, tail->prev, tail);
	tail->prev = tail->prev->next.get();
	++sz;
    }
}

template<typename T>
bool List<T>::empty() const noexcept
{
    return head.get() == tail;
}
template<typename T>
T List<T>::back() const noexcept
{
    return tail->prev->value;
}

template<typename T>
T & List<T>::back() noexcept
{
    return tail->prev->value;
}

template<typename T>
T List<T>::front() const noexcept
{
    return head->value;
}

template<typename T>
T & List<T>::front() noexcept
{
    return head->value;
}

template<typename T>
T & List<T>::at(int idx)
{
    return const_cast<T &>(static_cast<List const &>(*this).at(idx));
}

template<typename T>
T const & List<T>::at(int idx) const
{
    if (idx >= sz)
        throw std::out_of_range{"Index not found"};
    Node * tmp {head.get()};
    while ( idx > 0 )
    {
        tmp = tmp->next.get();
        --idx;
    }
    return tmp->value;
}

template<typename T>
int List<T>::size() const noexcept
{
    return sz;
}

template<typename T>
void List<T>::swap(List & other) noexcept
{
    using std::swap;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(sz, other.sz);
}

template<typename T>
List<T> & List<T>::operator=(List const & rhs) &
{
    List{rhs}.swap(*this);
    return *this;
}

List<T> & List<T>::operator=(List && rhs)& noexcept
{
    swap(rhs);
    return *this;
}
