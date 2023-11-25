/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:42:04 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/24 22:24:00 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    this->N = 0;
}

Span::Span(unsigned int n)
{
    this->N = n;
}

Span::~Span()
{}

void    Span::addNumber(int num)
{
    if (this->vec.size() < this->N)
        this->vec.push_back(num);
    else
        throw(std::out_of_range("The vector is full"));
}

int    Span::shortestSpan()
{
    if (this->vec.size() > 1) // That means that there is more than one argument in the vector
    {
        int dist = std::numeric_limits<int>::max();
        for(int x = 0; x < static_cast<int>(this->vec.size()) - 1; x++)
        {
            if (abs(vec[x] - vec[x+1]) < dist)
                dist = abs(vec[x] - vec[x+1]);
        }
        return (dist);
    }
    else
        throw(std::logic_error("There isn't enough arguments to do the shortestSpan check"));
}

int    Span::longestSpan()
{
    if (this->vec.size() > 1) // That means that there is more than one argument in the vector
    {
        int dist = 0;
        for(int x = 0; x < static_cast<int>(this->vec.size()) - 1; x++)
        {
            if (abs(vec[x] - vec[x+1]) > dist)
                dist = abs(vec[x] - vec[x+1]);
        }
        return (dist);
    }
    else
        throw(std::logic_error("There isn't enough arguments to do the longestSpan check"));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    size_t remainingSpace = this->N - vec.size();
    size_t inputSize = std::distance(begin, end);

    if (inputSize > remainingSpace)
    {
        throw std::overflow_error("Not enough space to add the entire range.");
    }
    std::copy(begin, end, std::back_inserter(vec));
}

void    Span::print_container()
{
    std::cout << "vec = {" << this->vec[0];
    for(int x = 1; x < (int)this->vec.size(); x++)
    {
        std::cout << ", ";
        std::cout << this->vec[x];
    }
    std::cout << "}" << std::endl;
}

Span    &Span::operator=(Span &obj)
{
    this->N = obj.N;
    this->vec = obj.vec;
    return(*this);
}
