/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/12/27 23:17:13 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h>

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"

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
    // print_vector(vec);
    // std::cout << "The iterator passed is: " << *it << " and the increment is : " << increment << std::endl;
    
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
    // std::cout << "erase_element exited\n";
}

std::vector<int>    push_element(std::vector<int> &V, std::vector<int>::iterator it, int increment)
{
    // std::cout << "\n••••••••••••••••••••••••••••ENTER••••••••••••••••••••••••••••••••••\n";
    // std::cout << "push element entered, increment = " << increment << std::endl;
    // std::cout << "the vec ::        ";
    // for(std::vector<int>::iterator it = V.begin(); it != V.end(); it++)
    //     std::cout << *it << " | ";
    // std::cout << "\n";
    // std::cout << std::endl;
    // std::cout << "after push_back()\n";
    // std::cout << " it = " << *it << std::endl;
    increment--;
    // std::cout << "The element is : ";
    while(increment != -1)
    {
        V.push_back(*(it - increment));
        // std::cout << *(it-increment) << " ";
        increment--;
    }
    // std::cout << "\n\n";
    // for( std::vector<int>::iterator it = V.begin(); it != V.end(); it++)
    //     std::cout << *it << " | ";
    // std::cout << std::endl;
    // std::cout << "push element exited\n";
    // std::cout << "•••••••••••••••••••••••••••••END•••••••••••••••••••••••••••••••••\n\n";
    
    // static int i;i++;if (i == 2)exit(0);
    
    return (V);
}

std::vector<int>    InsertElementInMainChain(std::vector<int> MainChain, std::vector<int>::iterator Pend_it, int bound, int increment)
{
//  Description: this function is really complicated, i hope that it behave well
    
    std::vector<int>::iterator MainChain_it = MainChain.begin();
    if (MainChain.size() > 0)
        MainChain_it += increment - 1;

    while (1)
    {
        std::cout << "1!\n";
        if (MainChain_it < MainChain.end() && *MainChain_it == bound)
        {
            std::cout << "2!\n";
            MainChain_it = MainChain.begin();
            if (MainChain_it >= MainChain.begin()+increment+1)
                MainChain_it -= increment+1;
            int dist = MainChain_it - MainChain.begin();
            increment--;
            while (increment != -1 && MainChain_it < MainChain.end())
            {
                MainChain_it = MainChain.begin() + dist;
                MainChain.insert(MainChain_it, *(Pend_it - increment));
                increment--;
            }
            break;
        }
        std::cout << "*MainCharin_it = " << *MainChain_it << " bound = " << bound << std::endl;
        MainChain_it += increment;
    }
    return (MainChain);
}

// #include <unistd.h> // must be removed
void    binary_search(std::vector<int> *MainChain, std::vector<int> *Pend, int increment)
{
    std::vector<int> vec;
    std::vector<int>::iterator Pend_it = Pend->begin() + increment - 1;
    std::vector<int>::iterator MainChain_it = MainChain->begin() + increment - 1;

    std::cout << "              binary search entered and the increment equal " << increment << "\n";
    
    std::cout << "MainChain : \n";
    for(std::vector<int>::iterator it = MainChain->begin(); it < MainChain->end(); it++)
        std::cout << *it << " | ";
    std::cout << "\n";
    
    for (; MainChain_it < MainChain->end(); MainChain_it += increment)
    {
        vec.push_back(*MainChain_it);
    }
    for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << *(it) << " - ";
        
    std::cout << "\n\n--------\n\n";
    
    std::vector<int>::iterator pend_it = Pend->begin();
    while(pend_it != Pend->end())
    {
        std::vector<int>::iterator LowrBndIt = std::lower_bound(vec.begin(), vec.end(), *pend_it);
        std::cout << "lower: " << *LowrBndIt << std::endl;
        for(std::vector<int>::iterator it = MainChain->begin(); it < MainChain->end(); it++)
            std::cout << *it << " | ";
        std::cout << std::endl << "increment = " << increment << std::endl;
        // sleep(3);
        *MainChain = InsertElementInMainChain(*MainChain, Pend_it, *LowrBndIt, increment); // It segfaults here
        std::cout << "passed\n";
        pend_it += increment;
        break;
    }
}

void    recurcive(std::vector<int> *vec, int increment)
{
    // std::cout << "Recurcive begins with " << increment << " increment value\n";
    std::vector<int> rest;
    std::vector<int>::iterator arg1 = vec->begin() + increment - 1;
    std::vector<int>::iterator arg2 = vec->begin() + (increment*2) - 1;
    while(1)
    {
        // std::cout << "111\n";
        if (arg2 < vec->end() && *arg1 > *arg2) // May cause a SEG
        {
            // std::cout << "                  SWAP\n";
            // std::cout << "i want to swap11 : " << *arg1 << " and " << *arg2 << "\n";
            swap_elements(vec, arg1, arg2);
        }
        else if (arg1 + 1 == vec->end())
        {
            std::cout << BLUE_TEXT << "                  REST\n" << RESET_TEXT;
            rest = push_element(rest, arg1, increment);
            
            std::cout << "printing the REST: ";
            for(std::vector<int>::iterator it = rest.begin(); it < rest.end(); it++)
                std::cout << *it << "  ";
            std::cout << std::endl;
            
            erase_element(vec, arg1, increment);
            break;
        }
        else if (arg2 + 1 >= vec->end())
            break;
        arg1 += increment * 2;
        arg2 += increment * 2;
        // we sort just the pairs, in the first case every number with his next number
    }
    // std::cout << "            " << increment << " recurcive ends\n";
    // std::cout << "                  increment = "<< increment << " ArgsNum = " << ArgsNum << "\n";
    if (increment*2 <= ArgsNum/2)
        recurcive(vec, increment * 2);
    
// ------------------------------------REVERSE RECURCIVE------------------------------------
    std::cout << "Reverse Recurcive begins\n";
    std::vector<int> MainChain;
    std::vector<int> pend;
    std::vector<int>::iterator it = vec->begin() + increment - 1;//vec[increment-1];

    if (increment*2 > ArgsNum/2)
    {
        std::cout << ORANGE_TEXT << "ja!\n" << RESET_TEXT;
        MainChain = push_element(MainChain, it, increment);
        std::cout << "printing the MainChain: ";
        for(std::vector<int>::iterator it = MainChain.begin(); it < MainChain.end(); it++)
            std::cout << *it << "  ";
        std::cout << std::endl;
        it += increment;
        MainChain = push_element(MainChain, it, increment);
        std::cout << "printing the MainChain: ";
        for(std::vector<int>::iterator it = MainChain.begin(); it < MainChain.end(); it++)
            std::cout << *it << "  ";
        std::cout << std::endl;
        it += increment;
        // std::cout << "                                          pushed the two elements to MC\n";
        while(increment <= EvenArgsNum / 4) // This while condition work just like an if condition to execute that block, the while stop with a break
        {
            MainChain = push_element(MainChain, it, increment);
            if (it + 1 == vec->end())
                break;
            it += increment * 2;
        }
        it = vec->begin() + (increment * 3) - 1; // May cause a seg, it needs an if condition, also the one up there
        while(increment <= EvenArgsNum / 4) // This while condition work just like an if condition to execute that block, the while stop with a break
        {
            pend = push_element(pend, it, increment);
            if (it + increment + 1 == vec->end())
                break;
            it += increment * 2;
        }
        pend = push_element(pend, rest.end() - 1, increment);
        // for(std::vector<int>::iterator it = pend.begin(); it != pend.end(); it++)
        //     std::cout << "->" << *it << "\n";
        std::cout << "      FINISHED\n\n\n";
        binary_search(&MainChain, &pend, increment);
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

// int main()
// {
//     std::vector<int> vec;
//     // vec.push_back(33);
//     // vec.push_back(55);
//     // vec.push_back(11);
//     // vec.push_back(22);
//     std::vector<int> nek;
//     nek.push_back(33);
//     nek.push_back(55);
//     nek.push_back(11);
//     nek.push_back(22);

//     vec = push_element(vec, nek.end() - 1, 3);
//     for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
//         std::cout << *it << " || ";
//     std::cout << std::endl;
// }
