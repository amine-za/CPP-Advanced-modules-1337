/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:25:55 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/29 16:55:26 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string    *add_arg_to_array(std::string *array, std::string arg)
{
//  Function Description : that is  just a function that takes an argument and an array 
//  and it create a copy of that array and add that argument to it and return the new one
    static int i;
    std::string *new_array = new std::string[i+2];

    for(int x = 0; x < i; x++)
        new_array[x] = array[x];
    new_array[i] = arg;
    delete[] array;
    i++;
    return (new_array);
}

std::string combining_strings(char **av)
{
    std::string str;

    for(int x = 0; av[x]; x++)
    {
        str += av[x];
        str += ' ';
    }
    return (str);
}

bool valid_character(std::string input)
{
    for(int x = 0; input[x]; x++)
    {
        if (!std::isdigit(input[x]) && input[x] != ' ' && input[x] != '\t' &&           // if the character is not equal to a space or tabe and not a number
            input[x] != '+' && input[x] != '-' && input[x] != '*' && input[x] != '/')   // if the character is not equal to a athematical expression
            return (true);
    }
    return (false);
}

std::string *tokenization(std::string input)
{
    std::string str;
    std::string *arguments = new std::string[1];

    for(int x = 0; input[x];)
    {
        while (input[x] == ' ' || input[x] == '\t')
            x++;
        while(input[x] && input[x] != ' ' && input[x] != '\t')
        {
            if ((input[x] == '+' || input[x] == '-' || input[x] == '*' || input[x] == '/'))
            {
                if (str.empty())
                    str += input[x++];
                break;
            }
            str += input[x++];
        }
        arguments = add_arg_to_array(arguments, str);
        str = "";
    }
    return (arguments);
}

bool    its_a_mathematical_expression(std::string str)
{
//  Function Description : A function to determine if the parameter represent a mathematical expression or not {+, -, *, /}
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return (true);
    return (false);
}
    
bool GoodOrganized(std::string *arguments)
{
    int number = 0;

    // if (arguments[1].empty() || arguments[2].empty())
    //     return (false);
    // if (!std::isdigit(arguments[0][0]) || (!arguments[1].empty() && !std::isdigit(arguments[1][0])))
    //     return (false);
    for(int x = 0; !arguments[x].empty(); x++)
    {
        std::stringstream ss(arguments[x]);
        // if (its_a_mathematical_expression(arguments[x]) && (arguments[x+1].empty() || its_a_mathematical_expression(arguments[x+1])))
        //     return (false);
        if(std::isdigit(arguments[x][0]) && (!(ss >> number) || number >= 10))
            return (false);
        // if (x > 0 && std::isdigit(arguments[x][0]) && !arguments[x+1].empty() && std::isdigit(arguments[x+1][0]))
        //     return(false);
    }
    return (true);
}

int main(int ac, char **av)
{
    int number;
    std::stack<int> S;
    
    if (ac == 1)
        return (std::cerr << "Error: No argument entered\n", 1);
    std::string input = combining_strings(&av[1]);
    if (valid_character(input))
        return(std::cerr << "Error: It appears that you entered some unvalide characters\n", 1);
    std::string *arguments = tokenization(input);
    if (!GoodOrganized(arguments)) // Check if the arguments are organized well, i talk here about the order of the numbers and the mathematical expression
        return(std::cerr << "Error: It appears that you entered some unordered arguments\n", 1);
    for(int x = 0; !arguments[x].empty(); x++) // Calculating (The real work)
    {
        std::stringstream ss(arguments[x]);
        if (std::isdigit(arguments[x][0]))
        {
            if (!(ss >> number))
                return(std::cerr << "Error: An error appears while trying to convert using stringstream\n", 1);
            S.push(number);
        }
        else if (its_a_mathematical_expression(arguments[x]) && S.size() >= 2 && S.size() > 1)
        {
            int num2 = S.top();
            S.pop();
            int num1 = S.top();
            S.pop();
            if (arguments[x] == "+")
                S.push(num1 + num2);
            else if (arguments[x] == "-")
                S.push(num1 - num2);
            else if (arguments[x] == "*")
                S.push(num1 * num2);
            else if (arguments[x] == "/")
            {
                if(num2 == 0)
                    return (std::cerr << "Error: cant devide by zero\n", 1);
                S.push(num1 / num2);
            }
        }
        else
            return (std::cerr << "Error\n", 1);
    }
    if (S.size() != 1)
        return (std::cerr << "Error\n", 1);
    std::cout << S.top() << std::endl;
    return(0);
}
