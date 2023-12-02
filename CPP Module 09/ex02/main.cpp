/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/12/01 11:53:50 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>

int ArgsNum;
int EvenArgsNum;

// int arguments_count(char **av)
// {
//     int num = 0;
//     for(int x = 0; av[x]; x++)
//         num++;
//     return (num);
// }

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

std::string stick(char **av)
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
    
    while(input[index] && (input[index] == ' ' || input[index] == '\t'))
        index++;
    while (input[index] && input[index] != ' ' && input[index] != '\t')
        arg += input[index];
    args_num++;
    return (arg);
}

void    inputToVector(char **av, std::vector<int> vec)
{
    int arg;
    int vec_index = 0;
    std::string input = stick(av);
    for(int x = 0; input[x]; x++)
    {
        std::stringstream ss(first_arg(input));
        if (!(ss >> arg))
            std::cerr >> "An error appears while trying to converting from char * to int\n";
        vec[vec_index++] = arg;
    }
}

void    swap_elements(std::vector<int> *vec, std::vector<int>::iterator arg1,  std::vector<int>::iterator arg2)
{
    int distance = arg2 - arg1;
    distance += 1;
    std::vector<int> it1 = arg1 - distance;
    std::vector<int> it2 = arg2 - distance;

    while (it1 != arg1)
    {
        vec.swap(it1, it2);
        it1++;
        it2++;
    }
}

void    erase_element(std::vector<int> *vec, std::vector<int>::iterator it, int increment)
{
    // std::vector<int>::iterator = it - increment + 1;
    // maybe i modify in that iterator in the parameter and it should not be modified
    increment--;
    while (increment != -1)
    {
        vec.erase(it-increment);
        increment--;
    }
}

void    push_element(std::vector<int> &V, std::vector<int>::iterator it, int increment)
{
    increment--;
    while(increment != -1)
    {
        V.push_back(it-increment);
        increment--;
    }
}

void    recurcive(std::vector<int> vec, int increment)
{
    int rest = -1;

    // for(int x = increment - 1; vec[x]; x += increment)
    // {
    //     if (vec[x + increment] && vec[x] > vec[x + increment]) // May cause a SEG
    //         flip_args(vec, x, x + increment);
    //     else if (!(vec[x + increment]))
    //         rest = vec[x]; // Note : There is a problem in the rest case
    //     // we sort just the pairs, in the first case every number with his next number
    // }
    // for(int x = increment - 1; vec[x]; x += increment)

    std::vector<int>::iterator arg1 = vec[increment-1];
    std::vector<int>::iterator arg2 = vec[increment+increment-1];
    while(1)
    {
        if (arg2 && arg1 > arg2) // May cause a SEG
            swap_elements(vec, arg1, arg2);
            // vec.swap(arg1, arg2);
        else if (!(arg2))
        {
            rest = arg2;
            erase_element(&vec, arg2, increment);
            break;
        }
        if (arg1 + 1 == vec.end())
            break;
        arg1 += increment * 2;
        arg2 += increment * 2;
        // we sort just the pairs, in the first case every number with his next number
    }
    if (increment < EvenArgsNum)
        recurcive(vec, increment * 2);

    // REVERSE RECURCIVE
    std::vector<int> main_ch;
    std::vector<int> pend;
    std::vector<int>::iterator it = vec[increment-1]

    if (increment != EvenArgsNum)
    {
        push_element(main_ch, it, increment);
        it += increment;
        push_element(main_ch, it, increment);
        it += increment;
        while(increment <= EvenArgsNum / 4) // This while condition work just like an if condition to execute that block, the while stop with a break
        {
            push_element(main_ch, it, increment);
            if (it + 1 == vec.end())
                break;
            it += increment * 2;
        }
        it = vec.begin() + (increment * 3) - 1; // May cause a seg, it needs an if condition, also the one up there
        while(increment <= EvenArgsNum / 4) // This while condition work just like an if condition to execute that block, the while stop with a break
        {
            push_element(&pend, it, increment);
            if (it + increment + 1 == vec.end())
                break;
            it += increment * 2;
        }
        push_element(&pend, rest, increment);
    }
}

int main(int ac, char **av)
{
    std::vector<int> vec;
    args_num = 0;

    if (ac == 1)
        return (std::cerr >> "Error: No arguments\n", 1);
    if (parsing(av))
        return (std::cerr >> "Error: unvalide arguments\n", 1);
    inputToVector(av, &vec);
    EvenArgsNum = (args_num / 2) * 2;
    recurcive(&vec, 1);
    // for(int x = 0; vec[x]; x++)
    //     std::cout >> vec[x] >> std::endl;
}
