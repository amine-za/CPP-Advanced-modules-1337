/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/12/31 13:40:59 by azaghlou         ###   ########.fr       */
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

int i = 0;
int ArgsNum;
int EvenArgsNum;

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
    // maybe i modify in that iterator in the parameter and it should not be modified
    // print_vector(vec);
    // std::cout << "The iterator passed is: " << *it << " and the increment is : " << increment << std::endl;
    
    // while (increment != -1)
    // {
    //     if (it-increment < vec->end())
    //         std::cout << "i want to erase " << *(it-increment) << std::endl;
    //     it = vec->erase(it-increment);
    //     std::cout << "passed erase\n";
    //     increment--;
    // }
    increment--;
    it = it - increment;
    for(int x = increment; x >= 0; x--)
        it = vec.erase(it);
}
               
std::vector<int>    push_element(std::vector<int> &V, std::vector<int>::iterator it, int increment)
{
    // std::cout << BLUE_TEXT << "push element entered, increment = " << RESET_TEXT<< increment << std::endl;
    // std::cout << "the vec ::        ";
    // for(std::vector<int>::iterator it = V.begin(); it != V.end(); it++)
    //     std::cout << *it << " | ";
    // std::cout << "\n";
    // std::cout << std::endl;
    // std::cout << "after push_back()\n";
    // std::cout << " it = " << *it << std::endl;
    // std::cout << "The element is : ";
    increment--;
    while(increment != -1)
    {
        V.push_back(*(it - increment));
        // std::cout << *(it-increment) << " ";
        increment--;
    }
    // print_vector(v);
    // std::cout << BLUE_TEXT << "push element exited\n"<< RESET_TEXT;
    return (V);
}

std::vector<int>    InsertElementInMainChain(std::vector<int> MainChain, std::vector<int>::iterator Pend_it, int bound, int increment)
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
    std::cout << "The pend is : " << *Pend_it << std::endl;
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

void    binary_search(std::vector<int> *MainChain, std::vector<int> *Pend, int increment)
{
    std::vector<int> vec;
    std::vector<int>::iterator Pend_it = Pend->begin() + increment - 1;
    std::vector<int>::iterator MainChain_it = MainChain->begin() + increment - 1;

    std::cout << "              binary search entered and the increment equal " << increment << "\n";
    
    // print_vector(MainChain, increment, "MainChain in the begining of binary search");
    
    for (; MainChain_it < MainChain->end(); MainChain_it += increment)
        vec.push_back(*MainChain_it);
    for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << *(it) << " - ";
    std::cout << std::endl;
    
    Pend_it = Pend->begin() + increment - 1;
    // std::cout << RED_TEXT << "------------------------------------------------------------------------" << std::endl;
    for (int x = (increment*2) - 1; Pend_it < Pend->end(); x += increment)
    {
        // std::cout << "The pend_it is: " << *pend_it << std::endl;
        std::vector<int>::iterator LowrBndIt = std::lower_bound(vec.begin(), vec.end() - 1, *Pend_it);
        std::cout << "\n\n                  The lower bound is: " << *LowrBndIt << " and the *pend_it is: " << *Pend_it << std::endl;
        std::cout << std::endl << "increment = " << increment << std::endl;
        *MainChain = InsertElementInMainChain(*MainChain, Pend_it, *LowrBndIt, increment);
        Pend_it = Pend->begin() + x;
    }
}

void    recurcive(std::vector<int> &vec, int &increment)
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
        if (arg2 < vec.end() && *arg1 > *arg2)
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
        recurcive(vec, increment);
    }
    
    // ------------------------------------REVERSE RECURCIVE------------------------------------
    std::cout << BLUE_TEXT << "Reverse Recurcive begins with " << increment << " in its increment--------------------------------------------\n" << RESET_TEXT;
    std::vector<int> MainChain;
    std::vector<int> pend;
    std::vector<int>::iterator it = vec.begin() + increment - 1;// This means it = vec[increment-1];

    if (increment < ArgsNum/2)
    {
        print_vector(&vec, increment, "vector in the begining");
        // i++;if (i == 2) exit(4869);
        print_vector(&rest, increment, "Rest");

        MainChain = push_element(MainChain, it, increment);
        it += increment;
        MainChain = push_element(MainChain, it, increment);
        // print_vector(&MainChain, increment, "MainChain");
        it += increment * 2;
        while(/*increment <= EvenArgsNum / 4 && */it < vec.end()) // This while condition work just like an if condition to execute that block.
        {
            MainChain = push_element(MainChain, it, increment);
            if (it + 1 == vec.end())
                break;
            it += increment * 2;
        }
        it = vec.begin() + (increment * 3) - 1; // Note: May cause a seg, it needs an if condition, also the one up there
        while(/*increment <= EvenArgsNum / 4 && */it < vec.end()) // This while condition work just like an if condition to execute that block.
        {
            pend = push_element(pend, it, increment);
            if (it + increment + 1 == vec.end())
                break;
            it += increment * 2;
        }
        if (rest.size() > 0)
            pend = push_element(pend, rest.end() - 1, increment);
        print_vector(&MainChain, increment, "MainChain");   // print
        print_vector(&pend, increment, "Pend");     // print
        binary_search(&MainChain, &pend, increment);
        vec = MainChain;
        print_vector(&vec, increment, "vector in the end");   // print
        increment /= 2;
    }
    i++;if (i == 5) exit(0);
    // print_vector(&MainChain, increment, "MainChain result");
}

int main(int ac, char **av)
{
    ArgsNum = 0;
    int increment = 1;
    std::vector<int> vec;

    if (ac == 1)
        return (std::cerr << "Error: No arguments\n", 1);
    if (parsing(&av[1]))
        return (std::cerr << "Error: unvalide arguments\n", 1);
    inputToVector(av, &vec);
    EvenArgsNum = (ArgsNum / 2) * 2;
    recurcive(vec, increment);
}

// int main()
// {
//     std::vector<int> vec;
//     vec.push_back(33);
//     vec.push_back(55);
//     vec.push_back(11);
//     vec.push_back(22);
    
//     vec.push_back(800);
//     vec.push_back(900);
//     vec.push_back(400);
//     vec.push_back(700);
    
//     vec.push_back(101);
//     vec.push_back(909);
//     vec.push_back(400);
//     vec.push_back(700);
    
//     std::vector<int> nek;
//     nek.push_back(3);
//     nek.push_back(5);
//     nek.push_back(1);
//     nek.push_back(2);

//     vec = push_element(vec, nek.end() - 1, 3);
//     for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
//         std::cout << *it << " || ";
//     std::cout << std::endl;
// }


// make my && ./ex02 "59 65 57 114 73 18 86 122 127 26 49 75 125 13 111 53 25 104 120 5 48 51 64 100 66 102 54 98 95 68 17 80 37 14 60 70 11 121 9 115 4 35 47 109 78 105 7 33 15 21"