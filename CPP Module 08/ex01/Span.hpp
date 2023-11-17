#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
// #include <deque>
// #include <map>
// #include <stack>
// #include <stdexcept>

class Span
{
    private:
        std::vector<int>    vec;
        unsigned int        N;

    public:
        Span();
        Span(unsigned int N);
        ~Span();
        
        void    addNumber(int num);
        int     shortestSpan();
        int     longestSpan();
        void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void    print_container();

        Span    &operator=(Span &obj);
};


#endif