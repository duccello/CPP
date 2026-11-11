#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &other) : std::stack<T>(other) {}
        MutantStack &operator=(const MutantStack &other) 
        { 
            std::stack<T>::operator=(other);
            return *this; 
        }
        ~MutantStack() {}

    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator; 
    typename std::deque<T>::iterator begin() 
    {
        return this->c.begin();
    }
    typename std::deque<T>::iterator end() 
    {
        return this->c.end();
    }
};

#endif
