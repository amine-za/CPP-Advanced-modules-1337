/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Static.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:30:04 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/08 13:38:26 by azaghlou         ###   ########.fr       */
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
    float Round = static_cast<float>(std::floor(d));

    if (d == Round)
        return (".0");
    return("");
}

std::string    PrintFloatComma(float f)
{
    float Round = static_cast <float> (std::floor(f));

// NOTE : (f != 1.0 / 0.0)  AND  (f != -1.0 / 0.0) refers that the var f is not equal to inf or -inf
// NOTE : And (f < 999999.5) refers to if the float is with the "e" methode
    if (f == 1.0 / 0.0 || f == -1.0 / 0.0 || f >= 999999.5)
        return ("");
    if ((f == Round) && (f != 1.0 / 0.0) && (f != -1.0 / 0.0) && (f < 999999.5))
        return (".0f");
    return("f");
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
    char    Char = static_cast<char>(var);
    int     Int = static_cast<int>(var);
    float   Float = static_cast<float>(var);
    double  Double = static_cast<double>(var);

    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float << PrintFloatComma(Float) << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

void    int_case(int var)
{
    char    Char = static_cast<char>(var);
    int     Int = static_cast<int>(var);
    float   Float = static_cast<float>(var);
    double  Double = static_cast<double>(var);

    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float  << PrintFloatComma(Float) << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

void    float_case(float var)
{
    char    Char = static_cast<char>(std::floor(var));
    int     Int = static_cast<int>(var);
    float   Float = static_cast<float>(var);
    double  Double = static_cast<double>(var);

    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float << PrintFloatComma(Float) << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

void    double_case(double var)
{
    char    Char = static_cast<char>(std::floor(var));
    int     Int = static_cast<int>(var);
    float   Float = static_cast<float>(var);
    double  Double = static_cast<double>(var);
    
    // std::cout << "double casr float = " << Float << std::endl;
    // PrintFloatComma(Float);
    // exit(0);

    // printf("var = %f\n", var);
    // printf("float = %f\n", Float);
    std::cout << "char: " << VisibleChar(Char) << std::endl;
    std::cout << "int: " << Int << std::endl;
    std::cout << "float: " << Float << PrintFloatComma(Float) << std::endl;
    std::cout << "double: " << Double << PrintDoubleComma(Double) << std::endl;
}

void    error()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

int    Static::convert(std::string str)
{
    int pos = -1;
    if (str.length() <= 1 && !std::isdigit(str[0]))
    {
        if (str[0] < 32 && str[0] != '\t')
            return (error(), 0);
        return (char_case(str[0]), 0);
    }
    pos = str.find(".");
    if (pos != -1 && str[pos+1])
    {
        std::string s = &str[pos + 1];
        if (s.find(".") != std::string::npos)
            return (error(), 0);
    }
    if (pos != -1) // this mean that we found a '.' char       Float check
    {
        if (pos == 0)
            return (error(), 0);
        if (!str[pos+1] || str[pos+1] == 'f')
            return (error(), 0);
        for(int x = 0; str[x]; x++)
        {
            if (x == 0 && (str[x] == '-' || str[x] == '+'))
                continue;
            if (!std::isdigit(str[x]) && str[x] != '.' && !(str[x] == 'f' && !str[x+1]))
                return (error(), 0);
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
            return (error(), 0);
        if (!str[x+1]) // i have to check that the number dont exceed the max or the min int 
        {
            std::stringstream ss(str);
            long int nbr = 0;
            ss >> nbr;
            if (str.length() > 10 || nbr > INT_MAX || nbr < INT_MIN) // TO DO : i have to count the length of the number manually
                return (error(), 0);
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
