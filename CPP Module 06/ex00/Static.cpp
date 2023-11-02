/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Static.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:30:04 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/31 21:08:02 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Static.hpp"

Static::Static()
{
    
}

Static::Static(Static &obj)
{
    *this = obj;
}

Static::~Static()
{}

std::string VisibleChar(char c)
{
    int ascii = c;
    std::string  C_to_str;
    
    C_to_str += '\'';
    C_to_str += c;
    C_to_str += '\'';
    if (ascii >= 32 && ascii < 127)
        return C_to_str;
    return ("Non displayable");
}

std::string    PrintDoubleComma(double d)
{
    float Round = std::floor(d);

    if (d == Round)
        return (".0");
    return("");
}

std::string    PrintFloatComma(float f)
{
    float Round = std::floor(f);
 
    if (f == Round)
        return (".0");
    return("");
}

std::string RemoveF(std::string str) // This function remove the f char if it exist in the end of that string
{
    if (str[str.length()-1] == 'f')
    {
        str[str.length()-1] = '\0';
        return (str);
    }
    return (str);
}

void    char_case(char var)
{
    char    Char = var;
    int     Int = var;
    float   Float = var;
    double  Double = var;

    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float << PrintFloatComma(Float) << "f" << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

void    int_case(int var)
{
    char    Char = var;
    int     Int = var;
    float   Float = var;
    double  Double = var;

    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float  << PrintFloatComma(Float) << "f" << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

void    float_case(float var)
{
    char    Char = std::floor(var);
    int     Int = var;
    float   Float = var;
    double  Double = var;

    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float << PrintFloatComma(Float) << "f" << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

void    double_case(double var)
{
    char    Char = std::floor(var);
    int     Int = var;
    float   Float = var;
    double  Double = var;

    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float  << PrintFloatComma(Float) << "f" << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

int    Static::convert(std::string str)
{
    int pos = -1;
    if (str.length() <= 1 && !std::isdigit(str[0]))
    {
        if (str[0] < 32 && str[0] != '\t')
            return (std::cout << "the char is non printable\n", 0);
        return (char_case(str[0]), 0);
    }
    pos = str.find(".");
    if (pos != -1 && str[pos+1])
    {
        std::string s = &str[pos + 1];
        if (s.find(".") != std::string::npos)
            return (std::cout << "error\n", 0);
    }
    if (pos != -1) // this mean that we found a '.' char       Float check
    {
        if (pos == 0)
            return (std::cout << "error\n", 0);
        if (!str[pos+1] || str[pos+1] == 'f')
            return (std::cout << "error\n", 0);
        for(int x = 0; str[x]; x++)
        {
            if (x == 0 && (str[x] == '-' || str[x] == '+'))
                continue;
            if (!std::isdigit(str[x]) && str[x] != '.' && !(str[x] == 'f' && !str[x+1]))
                return (std::cout << "error\n", 0);
        }
        std::stringstream ss(RemoveF(str));
        float F = 0;
        double D = 0;
        if (str[str.length()-1] == 'f')
        {
            if (ss >> F)
                return (float_case(F), 0);
            else
                return (std::cout << "An error appearse while triying to store a float\n", 0);
        }
        else
        {
            if (ss >> D)
                return (double_case(D), 0);
            else
                return (std::cout << "An error appearse while triying to store a double\n", 0);
        }
    }
    for (int x = 0; str[x] && pos == -1; x++) // Int check
    {
        if (x == 0 && (str[x] == '+' || str[x] == '-'))
            continue;
        if (!std::isdigit(str[x]))
            return (std::cout << "error\n", 0);
        if (!str[x+1]) // i have to check that the number dont exceed the max or the min int 
        {
            std::stringstream ss(str);
            long int nbr = 0;
            ss >> nbr;
            if (str.length() > 10 || nbr > INT_MAX || nbr < INT_MIN) // TO DO : i have to count the length of the number manually
                return (std::cout << "error\n", 0);
            return (int_case(nbr), 0);
        } 
    }
    return (0);
}

Static &Static::operator=(Static &obj)
{
    (void)obj;
    return (*this);
}
