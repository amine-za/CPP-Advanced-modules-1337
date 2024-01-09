/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:06 by azaghlou          #+#    #+#             */
/*   Updated: 2024/01/08 21:56:14 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <chrono>

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"
#define RED_TEXT "\033[31m"

template <typename T1, typename T2>
void    print_vector(T1 &vec, int increment, std::string name);

int ArgsNum = 0;
int comparaisons = 0;

bool check( std::vector<int> container, std::vector<int> copyContainer ) {

    for (size_t i = 0; i < container.size(); i++) {
        if (i + 1 < container.size() && container[i] > container[i + 1])
            return(false);
    }
    for (size_t i = 0; i < container.size();) {
        for (size_t j = 0; j < copyContainer.size(); j++) {
            if (container[i] == copyContainer[j]) {
                copyContainer.erase(copyContainer.begin() + j);
                container.erase(container.begin() + i);
                i = 0;
                break;
            }
            else {
                i++;
                break;
            }
        }
    }
    if (container.empty() && copyContainer.empty())
        return(true);
    return(false);
}

template <typename T1, typename T2>
void    duplicate_case(T1 vec)
{
    // print_vector<T1, T2>(vec, 1, "vec in dup");
    for(T2 it = vec.begin(); it < vec.end() - 1; it++)
    {
        if (*it == *(it + 1))
        {
            std::cerr << "Error: duplicate value" << "\n";
            exit(1);
        }
    }
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
    return (arg);
}

template <typename T1>
void    inputToVector(char **av, T1 &vec)
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
        vec.push_back(arg);
    }
}

template <typename T1, typename T2>
void    print_vector(T1 &vec, int increment, std::string name)
{
    // int x = 0;
    std::cout << ORANGE_TEXT << "The " << name << " is: \n" << RESET_TEXT << "[";
    for(T2 it = vec.begin(); it != vec.end(); it++)
    {
        if ((it - vec.begin()) % increment == 0 && (it - vec.begin()) != 0)
            std::cout << "]  \n[";
        else if ((it - vec.begin()) != 0)
            std::cout << "  ";
        std::cout << *it;
        // std::cout << "      " << ++x;
    }
    std::cout << "]\n\n";
}

template <typename T2>
void    SwapTwoArgs(T2 it1, T2 it2)
{
    int buffer = *it1;
    *it1 = *it2;
    *it2 = buffer;
}

template <typename T1, typename T2>
void    swap_elements(T1 &vec, T2 arg1,  T2 arg2)
{
    int distance = arg2 - arg1;
    distance -= 1;
    T2 it1;
    T2 it2;
    if (arg1-distance >= vec.begin() && arg2-distance >= vec.begin())
    {
        it1 = arg1 - distance;
        it2 = arg2 - distance;
    }
    else
        return;
    while (1)
    {
        SwapTwoArgs(it1, it2);
        if (it1 == arg1)
            break;
        it1++;
        it2++;
    }
}

template <typename T1, typename T2>
void    erase_element(T1 &vec, T2 it, int increment)
{
    increment--;
    it = it - increment;
    for(int x = increment; x >= 0; x--)
        it = vec.erase(it);
}
             
template <typename T1, typename T2>
              
T1    push_element(T1 &V, T2 it, int increment)
{
    increment--;
    while(increment != -1)
    {
        V.push_back(*(it - increment));
        increment--;
    }
    return (V);
}

template <typename T1, typename T2>
T1    InsertToMainChain(T1 MainChain, T2 Pend_it, int bound, int increment)
{
//  Description: this function is really complicated, i hope that it behave well
    T2 MainChain_it = MainChain.begin();
    if (MainChain.size() > 0)
        MainChain_it += increment - 1;
    while (1)
    {
        if (MainChain_it < MainChain.end() && *MainChain_it == bound)
        {
            if (MainChain_it == MainChain.end() - 1 && *Pend_it >= *MainChain_it)
                MainChain_it = MainChain.end();
            else
                MainChain_it -= increment - 1;
            int dist = MainChain_it - MainChain.begin();
            increment--;
            for (int x = 0; MainChain_it <= MainChain.end() && x <= increment; x++)
            {
                MainChain.insert(MainChain_it, *(Pend_it - x));
                MainChain_it = MainChain.begin() + dist;
                // std::advance(MainChain_it, dist);
            }
            break;
        }
        MainChain_it += increment;
    }
    return (MainChain);
}

bool    comp(int  V1, int V2)
{
//  Description: the function that i pass as a fourth argument to std::lower_bound to count how many comparaisons lower_bound do
    comparaisons++;
    if (V1 > V2)
        return (false);
    return (true);
}

template <typename T1, typename T2>
void    insertion(T1 &MainChain, T1 &Pend, int increment, T1 &limit_vec)
{
    T1 vec;
    T2 MainChain_it;
    T2 limit_vec_it = limit_vec.begin();
    T2 Pend_it = Pend.begin() + increment - 1;
    // std::advance(Pend_it, increment - 1);
    unsigned int array[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
    unsigned int *Jacobsthal = array;
    unsigned int x = 0;
    int num = limit_vec.size();
    print_vector<T1, T2>(MainChain, increment, "MainChain");
    print_vector<T1, T2>(Pend, increment, "Pend");
    print_vector<T1, T2>(limit_vec, increment, "limit_vec");
    while (num != 0)
    {
        MainChain_it = MainChain.begin() + increment - 1;
        // std::advance(MainChain_it, increment - 1);
        if (x == 0 || x == *(Jacobsthal-1)-1)
        {
            x = *(++Jacobsthal) - 1;
            if (Pend.size() < (increment * x) - 1 || Pend.size() == 1)
            {
                x = (Pend.size() / increment);
                // if (x < *(Jacobsthal-1))
                //     break;
            }
        }
        limit_vec_it = limit_vec.begin() + x - 1;
        // std::advance(limit_vec_it, x - 1);
        if (limit_vec_it >= limit_vec.end())
            limit_vec_it = limit_vec.end() - 1;
        for (; limit_vec.size() > 0 && MainChain_it < MainChain.end() && *MainChain_it <= *limit_vec_it; MainChain_it += increment)
            vec.push_back(*MainChain_it);
        Pend_it = Pend.begin() + (increment * x) - 1;
        if (Pend_it >= Pend.end())
            Pend_it = Pend.end() - 1;
        std::cout << "pend it = " << *Pend_it << std::endl;
        // std::advance(Pend_it, (increment * x) - 1);
        if (Pend.size() == 1)
            Pend_it = Pend.begin();
        // if (Pend_it >= Pend.end())
        //     break;
        
            // limit_vec_it = limit_vec.end() - 1;
        x--;
        T2 LowrBndIt = std::lower_bound(vec.begin(), vec.end() - 1, *Pend_it, comp);
        MainChain = InsertToMainChain(MainChain, Pend_it, *LowrBndIt, increment);
        vec.clear();
        num--;
    }
    std::cout << "-----------\n";
}

template <typename T1, typename T2>
void    sorting(T1 &vec, int &increment)
{
    // print_vector<T1, T2>(vec, increment, "vec in sort");
    // exit(0);
    T1 rest;
    T2 arg1 = vec.begin() + increment - 1;
    // std::advance(arg1, increment - 1);
    T2 arg2 = vec.begin() + (increment*2) - 1;
    // std::advance(arg2, (increment*2) - 1);
    while(1)
    {
        if (arg1 + 1 == vec.end())
        {
            rest = push_element(rest, arg1, increment);
            erase_element(vec, arg1, increment);
            break;
        }
        if (arg2 < vec.end() && *arg1 > *arg2 && ++comparaisons)
            swap_elements(vec, arg1, arg2);
        if (arg2 + 1 >= vec.end())
            break;
        arg1 += increment * 2;
        arg2 += increment * 2;
    }
    if (increment*2 <= ArgsNum/2)
    {
        increment *= 2;
        sorting<T1, T2>(vec, increment);
    }
    // Reverse recursion begin here
    T1 MainChain;
    T1 pend;
    T1 limit_vec;
    T2 it = vec.begin() + increment - 1;
    // std::advance(it, increment - 1);


    MainChain = push_element(MainChain, it, increment);
    it += increment;
    MainChain = push_element(MainChain, it, increment);
    it += increment * 2;
    while(it < vec.end())
    {
        MainChain = push_element(MainChain, it, increment);
        if (it + 1 == vec.end())
            break;
        it += increment * 2;
    }
    T2 MainChain_it = MainChain.begin() + (increment*3) - 1;
    // std::advance(MainChain_it, (increment*3) - 1);
    it = vec.begin() + (increment*3) - 1;
    // std::advance(it, (increment * 3) - 1);
    while(it < vec.end())
    {
        pend = push_element(pend, it, increment);
        limit_vec.push_back(*MainChain_it);
        if (it + increment + 1 == vec.end())
            break;
        MainChain_it += increment;
        it += increment * 2;
    }
    if (rest.size() > 0)
    {
        pend = push_element(pend, rest.end() - 1, increment);
        limit_vec.push_back(*(MainChain.end() - 1));
    }
    if (pend.size() > 0)
        insertion<T1, T2>(MainChain, pend, increment, limit_vec);
    vec = MainChain;

    increment /= 2;
}

int main(int ac, char **av)
{
    std::vector<int> vec_before;
    std::deque<int> deq;
    int increment = 1;
    if (ac == 1)                                                //
        return (std::cerr << "Error: No arguments\n", 1);       //
    if (parsing(&av[1]))                                        //      Error handling    
        return (std::cerr << "Error: unvalide arguments\n", 1); //
    inputToVector<std::vector<int> >(av, vec_before);                  //      Converting the input to a vector
    ArgsNum = vec_before.size();
    {//---------------------------------------------------------------------------std::vector---------------------------------------------------------------------------
        std::vector<int> vec = vec_before;
        // print_vector<std::vector<int>, std::vector<int>::iterator>(vec, increment, "vec");
        // exit(0);
        increment = 1;
        std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now(); // storing the time in the begin of the work
        
        if (ArgsNum > 1)
            sorting<std::vector<int>, std::vector<int>::iterator>(vec, increment);     // The real work function
        std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now(); // Storing the time in the end of the work
        duplicate_case<std::vector<int>, std::vector<int>::iterator>(vec);            // Checking if there is any duplicates numbers
        // // check
        // if (check(vec, vec_before))
        //     std::cout << "<<<<<ALL GOOD>>>>" << std::endl;
        // else
        //     std::cout << "<<<<oo0OOPS>>>>" << std::endl;
        // // end check
        
        std::cout << ORANGE_TEXT << "Before:   " << RESET_TEXT;                                 //
        for(std::vector<int>::iterator it = vec_before.begin(); it < vec_before.end(); it++)    //      Printing the
            std::cout << *it << " ";                                                            //      input before sorting
        std::cout << std::endl;                                                                 //


        std::cout << ORANGE_TEXT << "After:    " << RESET_TEXT;                     //
        for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)      //      Printing the
            std::cout << *it << " ";                                                //      input after sorting
        std::cout << std::endl;                                                     //

        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // Calculating the time that the work takes
        std::cout << ORANGE_TEXT << "Time to process a range of " << vec.size() << " elements with std::vector : " << RESET_TEXT << duration.count() << " us\n"; // Printing the time
        // std::cout << ORANGE_TEXT << "comparaisons = " << comparaisons << std::endl << RESET_TEXT;
    }
    {//---------------------------------------------------------------------------std::deque---------------------------------------------------------------------------
        increment = 1;
        for(std::vector<int>::iterator it = vec_before.begin(); it != vec_before.end(); it++)      //      Converting the vector to a deque
            deq.push_back(*it);                                                     //      
        std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now(); // storing the time in the begin of the work
        
        if (ArgsNum > 1)
            sorting<std::deque<int>, std::deque<int>::iterator>(deq, increment);       // The real work function
        std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now(); // Storing the time in the end of the work

        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // Calculating the time that the work takes
        std::cout << ORANGE_TEXT << "Time to process a range of " << ArgsNum << " elements with std::deque : " << RESET_TEXT << duration.count() << " us\n"; // Printing the time
        // std::cout << ORANGE_TEXT << "comparaisons = " << comparaisons << std::endl << RESET_TEXT;
    }
}
