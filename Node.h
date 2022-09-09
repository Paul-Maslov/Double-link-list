#pragma once

template<class T>
class Node
{
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
public:
    Node(const T& val);
    T getData()const;
    void setData(const T& val);
    Node<T>* getNext()const;
    void setNext(Node<T>* n);
    Node<T>* getPrev()const;
    void setPrev(Node<T>* p);
};

template<class T>
Node<T>::Node(const T& val)
{
    data = val;
}

template<class T>
T Node<T>::getData() const
{
    return data;
}

template<class T>
void Node<T>::setData(const T& val)
{
    data = val;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}

template<class T>
void Node<T>::setNext(Node<T>* n)
{
    next = n;
}

template<class T>
Node<T>* Node<T>::getPrev() const
{
    return prev;
}

template<class T>
void Node<T>::setPrev(Node<T>* p)
{
    prev = p;
}
