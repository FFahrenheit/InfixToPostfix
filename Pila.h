//
// Created by ivan_ on 01/12/2020.
//

#ifndef PROYECTO_PILA_H
#define PROYECTO_PILA_H

#include <iostream>
#include <stdexcept>
#include "LDL.h"

using namespace std;

template<typename T>
class Pila //stack
{
public:
    Pila()
    {

    }
    ~Pila()
    {
        lista.clear();
    }

    bool empty() const;
    size_t size() const;
    const T& top() const;
    void push(const T& element);
    void pop();

private:
    LDL<T> lista;
};

template<typename T>
bool Pila<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Pila<T>::size() const
{
    return lista.size();
}

template<typename T>
const T& Pila<T>::top() const
{
    if (empty())
    {
        throw runtime_error("Trying top() from empty stack.");
    }
    return lista.front();
}

template<typename T>
void Pila<T>::push(const T& element)
{
    lista.push_front(element);
}

template<typename T>
void Pila<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from empty stack.");
    }
    lista.pop_front();
}

#endif //PROYECTO_PILA_H
