/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:06 by azaghlou          #+#    #+#             */
/*   Updated: 2024/01/04 22:25:56 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"
#define RED_TEXT "\033[31m"

int ArgsNum = 0;
int comparaisons = 0;

bool    duplicate_error(std::vector<int> vec)
{
    for(std::vector<int>::iterator it = vec.begin(); it < vec.end() - 1; it++)
    {
        if (*it == *(it + 1))
        {
            std::cerr << "Error: duplicate value\n";
            return (true);
        }
    }
    return (false);
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

void    print_vector(std::vector<int> *vec, int increment, std::string name)
{
    std::cout << ORANGE_TEXT << "The " << name << " is: \n" << RESET_TEXT << "[";
    for(std::vector<int>::iterator it = vec->begin(); it < vec->end(); it++)
    {
        if ((it - vec->begin()) % increment == 0 && (it - vec->begin()) != 0)
            std::cout << "]  \n[";
        else if ((it - vec->begin()) != 0)
            std::cout << "  ";
        std::cout << *it;
    }
    std::cout << "]\n\n";
}

void    SwapTwoArgs(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
    int buffer = *it1;
    *it1 = *it2;
    *it2 = buffer;
}

void    swap_elements(std::vector<int> &vec, std::vector<int>::iterator arg1,  std::vector<int>::iterator arg2)
{
    // std::cout << "i want to swap " << *arg1 << " and " << *arg2 << "\n";
    int distance = arg2 - arg1;
    // int distance = std::distance(arg1, arg2);
    distance -= 1;
    std::vector<int>::iterator it1;
    std::vector<int>::iterator it2;
    if (arg1-distance >= vec.begin() && arg2-distance >= vec.begin())
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

void    erase_element(std::vector<int> &vec, std::vector<int>::iterator it, int increment)
{
    increment--;
    it = it - increment;
    for(int x = increment; x >= 0; x--)
        it = vec.erase(it);
}
               
std::vector<int>    push_element(std::vector<int> &V, std::vector<int>::iterator it, int increment)
{
    // std::cout << BLUE_TEXT << "push element entered, increment = " << RESET_TEXT<< increment << std::endl;
    increment--;
    while(increment != -1)
    {
        V.push_back(*(it - increment));
        increment--;
    }
    // std::cout << BLUE_TEXT << "push element exited\n"<< RESET_TEXT;
    return (V);
}

std::vector<int>    InsertToMainChain(std::vector<int> MainChain, std::vector<int>::iterator Pend_it, int bound, int increment)
{
//  Description: this function is really complicated, i hope that it behave well
    
    std::vector<int>::iterator MainChain_it = MainChain.begin();
    if (MainChain.size() > 0)
    {
        MainChain_it += increment - 1;
        // std::cout << "entered 1\n";
    }
    else
        std::cout << RED_TEXT << "There is a problem if that message appears\n" << RESET_TEXT;
    while (1)
    {
        if (MainChain_it < MainChain.end() && *MainChain_it == bound)
        {
            if (MainChain_it == MainChain.end() - 1 && *Pend_it >= *MainChain_it)
            {
                MainChain_it = MainChain.end();
                // std::cout <<  "<- entered 2\n";
            }
            else
            {
                MainChain_it -= increment - 1;
                // std::cout << "entered 3\n";
            }
            int dist = MainChain_it - MainChain.begin();
            increment--;
            for (int x = 0; MainChain_it <= MainChain.end() && x <= increment; x++)
            {
                MainChain.insert(MainChain_it, *(Pend_it - x));
                MainChain_it = MainChain.begin() + dist;
            }
            break;
        }
        MainChain_it += increment;
    }
    return (MainChain);
}
// 1 8 9 10 14
bool    comp(int  V1, int V2)//8
{
    comparaisons++;
    if (V1 > V2)
        return (false);
    return (true);
}

void    binary_search(std::vector<int> &MainChain, std::vector<int> &Pend, int increment, std::vector<int> &limit_vec)
{
    std::vector<int> vec;
    std::vector<int>::iterator MainChain_it;
    __unused std::vector<int>::iterator limit_vec_it = limit_vec.begin();
    std::vector<int>::iterator Pend_it = Pend.begin() + increment - 1;
    unsigned int array[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
    unsigned int *Jacobsthal = array;
    
    unsigned int x = 0;
    // for (int x = (increment*2) - 1; Pend_it < Pend.end(); x += increment)
    std::cout << "pend size is: " << Pend.size() << std::endl;
    std::cout << "number of pend elements is: " << Pend.size()/increment << std::endl;
    while (Pend_it < Pend.end())
    {
        // std::cout << "here\n";
        // Pend_it = Pend.begin() + x;
        MainChain_it = MainChain.begin() + increment - 1;
        if (x == 0 || x == *(Jacobsthal-1)-1)
        {
            x = *(++Jacobsthal) - 1;
            if (Pend.begin() + (increment * x) - 1 >= Pend.end())
            {
                x = (Pend.size() / increment);
                if (x < *(Jacobsthal-1)) // the problem is here
                    break;
                std::cout << "x === " << x+1 << std::endl;
            }
        }
        limit_vec_it = limit_vec.begin() + x - 1; // jacobsthal in that too
        for (; limit_vec.size() > 0 && MainChain_it < MainChain.end() && *MainChain_it <= *limit_vec_it; MainChain_it += increment)
            vec.push_back(*MainChain_it);
        Pend_it = Pend.begin() + (increment * x) - 1;
        x--;
        std::vector<int>::iterator LowrBndIt = std::lower_bound(vec.begin(), vec.end() - 1, *Pend_it, comp);
        MainChain = InsertToMainChain(MainChain, Pend_it, *LowrBndIt, increment);
        vec.clear();
    }
}

void    recursive(std::vector<int> &vec, int &increment)
{
    std::cout << BLUE_TEXT << "----Recurcive begins with " << increment << " in its increment--------------------------------------------\n" << RESET_TEXT;
    std::vector<int> rest;
    std::vector<int>::iterator arg1 = vec.begin() + increment - 1;
    std::vector<int>::iterator arg2 = vec.begin() + (increment*2) - 1;
    while(1)
    {
        if (arg1 + 1 == vec.end())
        {
            rest = push_element(rest, arg1, increment);
            erase_element(vec, arg1, increment);
            break;
        }
        if (arg2 < vec.end() && *arg1 > *arg2 && ++comparaisons)
        {
            // May cause a SEG
            swap_elements(vec, arg1, arg2);
        }
        if (arg2 + 1 >= vec.end())
            break;
        arg1 += increment * 2;
        arg2 += increment * 2;
        // Note: we sort just the pairs, in the first case every number with his next number
    }
    print_vector(&vec, increment, "-vector-");
    print_vector(&rest, increment, "-rest-");
    if (increment*2 <= ArgsNum/2)
    {
        increment *= 2;
        recursive(vec, increment);
    }
    
    // ------------------------------------REVERSE RECURCIVE------------------------------------
    std::cout << BLUE_TEXT << "Reverse Recurcive begins with " << increment << " in its increment--------------------------------------------\n" << RESET_TEXT;
    std::vector<int> MainChain;
    std::vector<int> pend;
    std::vector<int> limit_vec;
    
    std::vector<int>::iterator it = vec.begin() + increment - 1;// This means it = vec[increment-1];

    if (increment < ArgsNum/2)
    {
        print_vector(&vec, increment, "vector in the begining");
        print_vector(&rest, increment, "Rest");

        MainChain = push_element(MainChain, it, increment);
        it += increment;
        MainChain = push_element(MainChain, it, increment);
        // print_vector(&MainChain, increment, "MainChain");
        it += increment * 2;
        while(it < vec.end())
        {
            MainChain = push_element(MainChain, it, increment);
            if (it + 1 == vec.end())
                break;
            it += increment * 2;
        }
        std::vector<int>::iterator MainChain_it = MainChain.begin() + (increment*3) - 1;
        it = vec.begin() + (increment * 3) - 1; // Note: May cause a seg, it needs an if condition, also the one up there
        while(it < vec.end())
        {
            pend = push_element(pend, it, increment);
            limit_vec.push_back(*MainChain_it);
            // std::cout << RED_TEXT << "Het is: " << *(limit_vec.end() - 1) << std::endl << RESET_TEXT;
            if (it + increment + 1 == vec.end())
                break;
            MainChain_it += increment;
            it += increment * 2;
        }
        if (rest.size() > 0)
        {
            pend = push_element(pend, rest.end() - 1, increment);
            limit_vec.push_back(*(MainChain.end() - 1));
            // it_vec.push_back(MainChain.end() - 1);
        }
        print_vector(&MainChain, increment, "MainChain");   // print
        print_vector(&pend, increment, "Pend");     // print
        binary_search(MainChain, pend, increment, limit_vec);
        vec = MainChain;
        print_vector(&vec, increment, "vector in the end");   // print
        increment /= 2;
    }
    if (duplicate_error(vec))
        exit(1);
}

int main(int ac, char **av)
{
    int increment = 1;
    std::vector<int> vec;

    if (ac == 1)
        return (std::cerr << "Error: No arguments\n", 1);
    if (parsing(&av[1]))
        return (std::cerr << "Error: unvalide arguments\n", 1);
    inputToVector(av, &vec);
    recursive(vec, increment);
    std::cout << ORANGE_TEXT << "comparaisons = " << comparaisons << std::endl << RESET_TEXT;
}

// make my && ./ex02 "59 65 57 114 73 18 86 122 127 26 49 75 125 13 111 53 25 104 120 5 48 51 64 100 66 102 54 98 95 68 17 80 37 14 60 70 11 121 9 115 4 35 47 109 78 105 7 33 15 21"