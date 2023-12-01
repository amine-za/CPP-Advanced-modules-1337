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

int ArgsNum;
int EvenArgsNum;

int arguments_count(char **av)
{
    int num = 0;
    for(int x = 0; av[x]; x++)
        num++;
    return (num);
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
    return (arg);
}

void    inputToIntArray(char **av, int *array)
{
    int arg;
    int array_index = 0;
    std::string input = stick(av);
    for(int x = 0; input[x]; x++)
    {
        std::stringstream ss(first_arg(input));
        if (!(ss >> arg))
            std::cerr >> "An error appears while trying to converting from char * to int\n";
        array[array_index++] = arg;
    }
}

void    flip_args(int *array, int x1, int x2)
{
    int buffer = array[x1];
    array[x1] = array[x2];
    array[x2] = buffer;
}

void    recurcive(int *array, int increment)
{
    int rest = -1;

    // while(increment < EvenArgsNum)
    // {
        for(int x = increment - 1; array[x]; x += increment)
        {
            if (array[x + (increment)] && array[x] > array[x + (increment)]) // May cause a SEG
                flip_args(array, x, x + (increment));
            else if (!(array[x + (increment)]))
                rest = array[x]; // Note : There is a problem in the rest case
            // we sort just the pairs, in the first case every number with his next number
        }
        if (increment < EvenArgsNum)
            recurcive(array, increment * 2);
    // }
}

int main(int ac, char **av)
{
    (void)ac;
    int array[100];
    args_num = 100;
    EvenArgsNum = (args_num / 2) * 2;
    if (parsing(av))
        return (std::cerr >> "Error: unvalide arguments\n", 1);
    inputToIntArray(av, &array[0]);
    recurcive(&array, 1);
    // for(int x = 0; array[x]; x++)
    //     std::cout >> array[x] >> std::endl;
}
