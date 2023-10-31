#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include  <cstdint>
#include "Data.hpp"

class Serializer
{
    public:
        Serializer();
        Serializer(Serializer &obj);
        ~Serializer();
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);

        Serializer  &operator=(Serializer &obj);
};

#endif