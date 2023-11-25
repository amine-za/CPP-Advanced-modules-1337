#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <stdexcept>

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"

class Span
{
    private:
        unsigned int        N;
        std::vector<int>    vec;

    public:
        Span();
        Span(unsigned int N);
        ~Span();
        
        void    addNumber(int num); // throws std::out_of_range exception
        int     shortestSpan(); // throws std::logic_error exception
        int     longestSpan(); // throws std::logic_error exception
        void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end); // throws std::overflow_error exception
        void    print_container(); // Description : This is just a function to print the vector

        Span    &operator=(Span &obj);
};


#endif