#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        int array_size;
        T *array;

    public:
        Array()                         // Orthodox : Default Constructor
        {
            array_size = 0;
            this->array = new T(0);
        }

        Array(unsigned int n)
        {
            array_size = n;
            this->array = new T(n);
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
            this->array = &obj.array;
        }

        Array operator[](size_t index)
        {
            if (index >= this->size)
                throw(std::out_of_range("The index is out of bounds"));
            else
                return (this->array[index]);
        }
};

#endif