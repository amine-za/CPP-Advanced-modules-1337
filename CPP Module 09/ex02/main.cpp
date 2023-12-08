/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/12/08 09:28:42 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>

int ArgsNum;
int EvenArgsNum;

void    print_vector(std::vector<int> *vec)
{
    for( std::vector<int>::iterator it = vec->begin(); it != vec->end(); it++)
        std::cout << *it << " | ";
    std::cout << std::endl;
}

bool    parsing(char **av)
{
    for(int x = 0; av[x]; x++)
    {
        for(int y = 0; av[x][y]; y++)
        {
            if (!std::isdigit(av[x][y]) && av[x][y] != ' ' && av[x][y] != '\t')
                return (true);
        }
    }
    return (false);
}

std::string join(char **av)
{
    std::string str;
    for(int x = 0; av[x]; x++)
    {
        str += av[x];
        str += " ";
    }
    return (str);
}

std::string first_arg(std::string input)
{
    static int index;
    std::string arg;
    
    if (!input[index])
        return ("");
    while(input[index] && (input[index] == ' ' || input[index] == '\t'))
        index++;
    while (input[index] && input[index] != ' ' && input[index] != '\t')
        arg += input[index++];
    ArgsNum++;
    return (arg);
}

void    inputToVector(char **av, std::vector<int> *vec)
{
    int arg;
    std::string str;
    std::string input = join(&av[1]);
    for(int x = 0; input[x]; x++)
    {
        str = first_arg(input);
        if (str == "")
            break;
        std::stringstream ss(str);
        if (!(ss >> arg))
            std::cerr << "An error appears while trying to converting from char * to int\n";
        vec->push_back(arg);
    }
}

void    SwapTwoArgs(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
    int buffer = *it1;
    *it1 = *it2;
    *it2 = buffer;
}

void    swap_elements(std::vector<int> *vec, std::vector<int>::iterator arg1,  std::vector<int>::iterator arg2)
{
    // std::cout << "i want to swap " << *arg1 << " and " << *arg2 << "\n";
    int distance = arg2 - arg1;
    // int distance = std::distance(arg1, arg2);
    distance -= 1;
    std::vector<int>::iterator it1;
    std::vector<int>::iterator it2;
    if (arg1-distance >= vec->begin() && arg2-distance >= vec->begin())
    {
        it1 = arg1 - distance;
        it2 = arg2 - distance;
    }
    else // should be removed
    {
        std::cout << "Error: in swap elements function arg1 : " << *arg1 << " arg2 : " << *arg2 << "\n";
        return;
    }
    while (1)
    {
        SwapTwoArgs(it1, it2);
        if (it1 == arg1)
            break;
        it1++;
        it2++;
    }
}

void    erase_element(std::vector<int> *vec, std::vector<int>::iterator it, int increment)
{
    // maybe i modify in that iterator in the parameter and it should not be modified
    print_vector(vec);
    std::cout << "The iterator passed is: " << *it << " and the increment is : " << increment << std::endl;
    
    increment--;
    // while (increment != -1)
    // {
    //     if (it-increment < vec->end())
    //         std::cout << "i want to erase " << *(it-increment) << std::endl;
    //     it = vec->erase(it-increment);
    //     std::cout << "passed erase\n";
    //     increment--;
    // }
    it = it - increment;
    for(int x = increment; x >= 0; x--)
        it = vec->erase(it);
    std::cout << "erase_element exited\n";
}

void    push_element(std::vector<int> *V, std::vector<int>::iterator it, int increment)
{
    // std::cout << "push element entered";
    std::cout << "push element entered, increment = " << increment << std::endl;
    V->push_back(*it);
    // std::cout << " it = " << *it << std::endl;
    // print_vector(V);
    increment--;
    while(increment != -1)
    {
        V->push_back(*(it - increment));
        increment--;
    }
    std::cout << "push element exited\n";
}

void    InsertElementInMainChain(std::vector<int> *MainCain, std::vector<int>::iterator Pend_it, int bound, int increment)
{
//  this function is really complicated, i hope that it behave well
//  but it may seg cause of end() and begin() uuhhhggggg
    std::vector<int>::iterator MainChain_it = MainCain->begin() + increment - 1;
    Pend_it -= increment + 1;
    while (1)
    {
        if (*MainChain_it == bound)
        {
            for(int x = 0; x < increment; x++)
            {
                MainChain_it++;
                MainCain->insert(MainChain_it-increment, *Pend_it);
                Pend_it++;
            }
            break;
        }
        MainChain_it += increment;
    }
}

void    binary_search(std::vector<int> *MainChain, std::vector<int> *Pend, int increment)
{
    std::vector<int> vec;
    std::vector<int>::iterator Pend_it = Pend->begin() + increment - 1;
    std::vector<int>::iterator MainChain_it = MainChain->begin() + increment - 1;

    for (; MainChain_it != MainChain->end(); MainChain++)
        vec.push_back(*MainChain_it);
    std::vector<int>::iterator pend_it = Pend->begin();
    while(pend_it != Pend->end())
    {
        std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), *pend_it);
        InsertElementInMainChain(MainChain, Pend_it, *it, increment);
        pend_it += increment;
    }
}

void    recurcive(std::vector<int> *vec, int increment)
{
    std::cout << "Recurcive begins with " << increment << " increment value\n";
    std::vector<int> rest;
    std::vector<int>::iterator arg1 = vec->begin() + increment - 1;
    std::vector<int>::iterator arg2 = vec->begin() + (increment*2) - 1;
    while(1)
    {
        std::cout << "111\n";
        if (arg2 < vec->end() && *arg1 > *arg2) // May cause a SEG
        {
            std::cout << "                  SWAP\n";
            // std::cout << "i want to swap11 : " << *arg1 << " and " << *arg2 << "\n";
            swap_elements(vec, arg1, arg2);
        }
        else if (arg1 + 1 == vec->end())
        {
            std::cout << "                  PUSH\n";
            push_element(&rest, arg1, increment);
            erase_element(vec, arg1, increment);
            break;
        }
        else if (arg2 + 1 >= vec->end())
            break;
        std::cout << "The bottom of while(1)\n";
        arg1 += increment * 2;
        arg2 += increment * 2;
        // we sort just the pairs, in the first case every number with his next number
    }
    std::cout << "            " << increment << " recurcive ends\n";
    std::cout << "                  increment = "<< increment << " ArgsNum = " << ArgsNum << "\n";
    if (increment*2 <= ArgsNum/2)
        recurcive(vec, increment * 2);
    
    // ------------------------------------REVERSE RECURCIVE------------------------------------
    std::cout << "Reverse Recurcive begins\n";
    std::vector<int> MainChain;
    std::vector<int> pend;
    std::vector<int>::iterator it = vec->begin() + increment - 1;//vec[increment-1];

    if (increment*2 > ArgsNum/2)
    {
        push_element(&MainChain, it, increment);
        it += increment;
        push_element(&MainChain, it, increment);
        it += increment;
        while(increment <= EvenArgsNum / 4) // This while condition work just like an if condition to execute that block, the while stop with a break
        {
            push_element(&MainChain, it, increment);
            if (it + 1 == vec->end())
                break;
            it += increment * 2;
        }
        it = vec->begin() + (increment * 3) - 1; // May cause a seg, it needs an if condition, also the one up there
        while(increment <= EvenArgsNum / 4) // This while condition work just like an if condition to execute that block, the while stop with a break
        {
            push_element(&pend, it, increment);
            if (it + increment + 1 == vec->end())
                break;
            it += increment * 2;
        }
        push_element(&pend, rest.end() - 1, increment);
        std::vector<int>::iterator it = pend.begin();
        for(;it != pend.end(); it++)
            std::cout << *it << "\n";
        // vec = binary_search(&main_ch, &pend);
    }
}

int main(int ac, char **av)
{
    std::vector<int> vec;
    ArgsNum = 0;

    if (ac == 1)
        return (std::cerr << "Error: No arguments\n", 1);
    if (parsing(&av[1]))
        return (std::cerr << "Error: unvalide arguments\n", 1);
    inputToVector(av, &vec);
    EvenArgsNum = (ArgsNum / 2) * 2;
    recurcive(&vec, 1);
}
