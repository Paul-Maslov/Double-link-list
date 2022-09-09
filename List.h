#pragma once

#include <iostream>
#include <initializer_list>
#include "Node.h"

using namespace std;

template<class T>
class List
{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
public:
    List();
    List(const List<T>& obj);
    List(const initializer_list<T>& list);
    List(List<T>& obj);
    ~List();

    List& operator = (const List<T>& obj);
    List& operator = (List<T>&& obj);

    void push_back(const T& val);
    void push_front(const T& val);
    void insert(const T& val, int pos);

    void print_forward() const;
    void print_backward() const;

    void pop_front();
    void pop_back();
    void pop_index(int pos);

    void sort_Bubble();
};

template<class T>
void List<T>::print_backward() const
{
    auto cur = tail;
    while (cur != nullptr)
    {
        cout << cur->getData() << " ";
        cur = cur->getPrev();
    }
    cout << endl;
}

template<class T>
void List<T>::print_forward() const
{
    auto cur = head;
    while (cur != nullptr)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}

template<class T>
List<T>::List() = default;

template<class T>
inline List<T>::List(const initializer_list<T>&list)
{
    for (auto item : list)
    {
        push_back(item);
    }
}

template<class T>
void List<T>::push_back(const T & val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setPrev(tail);
        tail->setNext(tmp);
        tail = tmp;
    }
    size++;
}

template<class T>
void List<T>::pop_front()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    head = head->getNext();
    delete head->getPrev();
    head->setPrev(nullptr);
    size--;
}

template<class T>
inline void List<T>::pop_back()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    tail = tail->getPrev();
    delete tail->getNext();
    tail->setNext(nullptr);
    size--;

}

template<class T>
inline void List<T>::pop_index(int pos)
{
    if (pos < 0 || pos > size)
        return;
    if (pos == 0)
    {
        pop_front();
        return;
    }
    if (pos == size)
    {
        pop_back();
        return;
    }

    auto cur = head;
    for (int i = 0; i < pos - 2; ++i)
    {
        cur = cur->getNext();
    }
    cout << "Element to delete " << cur->getNext()->getData() << "\n";
    
    auto tmp = cur->getNext();
    cur->setNext(tmp->getNext());
    cur = cur->getNext();
    cur->setPrev(tmp->getPrev());
    delete tmp;
    size--;
}

template<class T>
inline void List<T>::sort_Bubble()
{
    auto tmp = head;
    auto tmp1 = head;
    auto cur = head->getNext();
    for (int i = 1;i < size; i++)
    {
        if (cur->getData() < tmp->getData())
        {
            tmp = cur;
            tmp->setData(cur->getData());
            tmp1 = cur;
        }
        cur = cur->getNext();
    }
    if (tmp->getPrev() != nullptr)
    {
        tmp1 = tmp1->getPrev();
        tmp1->setNext(tmp->getNext());
        tmp1 = tmp1->getNext();
        tmp1->setPrev(tmp->getPrev());
        tmp->setPrev(nullptr);
        tmp->setNext(head);
        head->setPrev(tmp);
        head = tmp;
    }
    tmp = tail;
    tmp1 = tail;
    cur = head;
    for (int i = 0;i < size - 1; i++)
    {
        if (cur->getData() > tmp->getData())
        {
            tmp = cur;
            tmp->setData(cur->getData());
            tmp1 = cur;
        }
        cur = cur->getNext();
    }
    if (tmp->getNext() != nullptr)
    {
        tmp1 = tmp1->getPrev();
        tmp1->setNext(tmp->getNext());
        tmp1 = tmp1->getNext();
        tmp1->setPrev(tmp->getPrev());
        tmp->setNext(nullptr);
        tmp->setPrev(tail);
        tail->setNext(tmp);
        tail = tmp;
    }
    
    tmp = head;
    cur = tmp->getNext();
    tmp1 = tmp->getNext();
    for (int i = 0;i < size - 2;i++)
    {
        for (int j = size-2; j > i; j--)
        {
            if (cur->getData() < tmp1->getData())
            {
                tmp1 = cur;
                tmp1->setData(cur->getData());
            }
            cur = cur->getNext();
        }
        
        cur = tmp1;
        cur = cur->getPrev();
        cur->setNext(tmp1->getNext());
        cur = cur->getNext();
        cur->setPrev(tmp1->getPrev());
        tmp1->setPrev(tmp);
        cur = tmp->getNext();
        tmp1->setNext(cur);
        cur->setPrev(tmp1);
        tmp->setNext(tmp1);
       
        tmp = tmp1;
        cur = tmp->getNext();
        tmp1 = tmp->getNext();
        
     }
}

template<class T>
List<T>::~List()
{
    while (size != 0)
        pop_front();
}

template<class T>
inline List<T>& List<T>::operator=(const List<T>& obj)
{
    if (this == &obj)
        return *this;
    while (size != 0)
        pop_front();
    auto cur = obj.head;
    if (obj.head != nullptr)
    {
        while (cur != nullptr)
        {
            push_back(cur->getData());
            cur = cur->getNext();
        }
    }
    else cur = nullptr;
    return *this;
}

template<class T>
inline List<T>& List<T>::operator=(List<T>&& obj)
{
    if (this == &obj)
        return *this;
    while (size != 0)
        pop_front();
    head = obj.head;
    tail = obj.tail;
    size = obj.size;
    obj.head = nullptr;
    obj.tail = nullptr;
    obj.size = 0;
    return *this;
}

template<class T>
List<T>::List(const List<T> &obj)
{
    auto cur = obj.head;
    while (cur != nullptr)
    {
        push_back(cur->getData());
        cur = cur->getNext();
    }
}

template<class T>
List<T>::List(List<T> &obj)
{
    head = obj.head;
    tail = obj.tail;
    size = obj.size;
    obj.head = nullptr;
    obj.tail = nullptr;
    obj.size = 0;
}

template<class T>
void List<T>::push_front(const T & val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setNext(head);
        head->setPrev(tmp);
        head = tmp;
    }
    size++;
}

template<class T>
void List<T>::insert(const T & val, int pos)
{
    if (pos < 0 || pos > size)
        return;
    if (pos == 0)
    {
        push_front(val);
        return;
    }
    if (pos == size)
    {
        push_back(val);
        return;
    }

    auto cur = head;
    for (int i = 0; i < pos - 1; ++i)
    {
        cur = cur->getNext();
    }
    auto tmp = new Node<T>(val);

    tmp->setPrev(cur);
    tmp->setNext(cur->getNext());
    cur->setNext(tmp);
    tmp->getNext()->setPrev(tmp);
    size++;
}





