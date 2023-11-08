#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


class test
{
    public :
        int var;
        test()
        {
            var = 0;
        }
        test(int input)
        {
            var = input;
        }
        int getter()
        {
            return  (var);
        }
        void    setter(int input)
        {
            var = input;
        }
};

// template <typename T>
// class Array
// {
//     private:

//     public:
//         int size;
//         T array[size];

//         Array();                        // Orthodox
//         Array(Array A);                 // Orthodox
//         ~Array();                       // Orthodox

//         Array(unsigned int n)
//         {
//             size = n;
//         }

//         Array operator=(Array &obj)     // Orthodox
//         {
//             this->size = obj.size;
//         }
// };

#endif