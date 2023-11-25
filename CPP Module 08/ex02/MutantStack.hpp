#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<int>::container_type::iterator iterator;

        MutantStack() : std::stack<T>() {}

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }
};

#endif