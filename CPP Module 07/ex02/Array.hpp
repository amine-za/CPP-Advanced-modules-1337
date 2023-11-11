#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"

template <typename T>
class Array
{
    private:
        T *array;                       // The Array
        int array_size;

    public:

        Array()                         // Orthodox : Default Constructor
        {
            array_size = 0;
            this->array = new T[0];
        }

        Array(unsigned int n)
        {
            array_size = n;
            this->array = new T[n];
            array[0] = "test";
        }

        Array(Array &obj)               // Orthodox : copy constructor
        {
            *this = obj;
        }

        ~Array()                        // Orthodox : Destructor
        {}

        int size() const
        {
            return (this->array_size);
        }

        Array operator=(Array &obj)     // Orthodox : copy assignement opperator
        {
            this->array_size = obj.array;
            for(int x = 0; obj.array[x]; x++)
                this->array[x] = obj.array[x];
        }

        T &operator[](int index)
        {
            // std::cout << "The operator[] has been called\n";
            if (index >= this->array_size)
                throw(std::out_of_range("The index is out of bounds"));
            else
                return (this->array[index]);
        }
};

#endif