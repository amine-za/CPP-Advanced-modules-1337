/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:46:00 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/24 22:22:02 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << BLUE_TEXT << "MutanStack subject main" << RESET_TEXT << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << BLUE_TEXT << "list subject main" << RESET_TEXT << std::endl;
    {
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mlist);
    }
    std::cout << BLUE_TEXT << "my test 1" << RESET_TEXT << std::endl;
    {
        MutantStack<int> stck;
        stck.push(22);
        stck.push(23);
        stck.push(24);
        MutantStack<int>::iterator it = stck.begin();
        std::cout << *it << std::endl;
        ++it;                                           // testing operators in iterator
        std::cout << *it << std::endl;
        --it;                                           // testing operators in iterator
        std::cout << *it << std::endl;
        std::cout << *stck.begin() << std::endl;        // testing the begin() function
        std::cout << *stck.end() - 1 << std::endl;      // testing the end() function
    }
    std::cout << BLUE_TEXT << "my test 2" << RESET_TEXT << std::endl;
    {
        MutantStack<int> mstack;
        
        mstack.push(4869);
        mstack.push(1412);
        mstack.push(42);
        mstack.push(1337);
        std::cout << ORANGE_TEXT << "Printing the stack : " << RESET_TEXT << "{" << *(mstack.begin());
        MutantStack<int>::iterator it = mstack.begin() + 1;
        while(it != mstack.end())
        {
            std::cout << ", " << *it;
            it++;
        }
        std::cout << "}\n";
        std::cout << ORANGE_TEXT << "the top of the stack before poping : " << RESET_TEXT << mstack.top() << std::endl;
        std::cout << ORANGE_TEXT << "size of the stack before poping : " << RESET_TEXT << mstack.size() << std::endl;
        mstack.pop();
        std::cout << ORANGE_TEXT << "size of the stack after poping : " << RESET_TEXT << mstack.size() << std::endl;
        std::cout << ORANGE_TEXT << "the size of the stack after poping : " << RESET_TEXT << mstack.top() << std::endl;
    }
}
