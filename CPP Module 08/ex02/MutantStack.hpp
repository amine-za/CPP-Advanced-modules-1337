#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        typedef typename std::stack<int>::container_type::iterator iterator;

        MutantStack(){}

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }

        MutantStack &operator=(MutantStack &obj)
        {
            std::stack<T>::operator=(obj);
            return *this;
        }

        MutantStack(MutantStack &obj) : std::stack<T>(obj) {}
};

// template <typename T>
// class MutantStack : public std::stack<T>
// {
// public:
//     typedef typename std::stack<T>::container_type::iterator iterator;
//     MutantStack() {}
//     typename std::stack<T>::container_type::iterator begin()
//     {
//         return (std::stack<T>::c.begin());
//     }
//     typename std::stack<T>::container_type::iterator end()
//     {
//         return (std::stack<T>::c.end());
//     }
//     MutantStack &operator=(MutantStack &copy)
//     {
//         std::stack<T>::operator=(copy);
//         return (this);
//     }
//     MutantStack(MutantStack &op) : std::stack<T>(op) {}
// };

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }

#endif