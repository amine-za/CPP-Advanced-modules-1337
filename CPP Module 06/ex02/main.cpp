/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:25:10 by azaghlou          #+#    #+#             */
/*   Updated: 2024/02/12 11:07:02 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <c

Base *generate(void)
{
    int                 random_number;
    std::random_device  rand;
    std::uniform_int_distribution<int> dist(1,3);

    random_number = dist(rand);
rand();
    
    if (random_number == 1)
        return (new A());

    else if (random_number == 2)
        return (new B());

    else if (random_number == 3)
        return (new C());
    return(NULL);
}

void identify(Base* p)
{
    // std::cout << "pointer identify has been called\n";
    A *a;
    B *b;
    C *c;

    a = dynamic_cast <A*>(p);
    if (a)
    {
        std::cout << "A" << std::endl;
        return;
    }
    b = dynamic_cast <B*>(p);
    if (b)
    {
        std::cout << "B" << std::endl;
        return;
    }
    c = dynamic_cast <C*>(p);
    if (c)
    {
        std::cout << "C" << std::endl;
        return;
    }
}

void identify(Base& p)
{
    // std::cout << "reference identify has been called\n";
    bool EnteredOrNot = false;
    try
    {
        __unused A &a = dynamic_cast <A&>(p);
    }
    catch(std::bad_cast&)
    {
        EnteredOrNot = true;
    }
    if (!EnteredOrNot) // This means that the code didnt entered the catch block so no exception is thrown
    {
        std::cout << "A" << std::endl;
        return;
    }
    
    
    EnteredOrNot = false;
    try
    {
        __unused B &b = dynamic_cast <B&>(p);
    }
    catch(std::bad_cast&)
    {
        EnteredOrNot = true;
    }
    if (!EnteredOrNot) // This means that the code didnt entered the catch block so no exception is thrown
    {
        std::cout << "B" << std::endl;
        return;        
    }

    EnteredOrNot = false;
    try
    {
        __unused C &c = dynamic_cast <C&>(p);
    }
    catch(std::bad_cast&)
    {
        EnteredOrNot = true;
    }
    if (!EnteredOrNot) // This means that the code didnt entered the catch block so no exception is thrown
    {
        std::cout << "C" << std::endl;
        return;
    }
}

int main()
{
    Base    *pointer = NULL;
    pointer = generate();
    Base    &reference = *pointer;

    identify(pointer);
    identify(reference);
    return (0);
}