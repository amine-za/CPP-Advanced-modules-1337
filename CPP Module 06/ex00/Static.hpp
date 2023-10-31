#ifndef STATIC_HPP
#define STATIC_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Static
{
    public :
        Static();
        Static(Static &obj);
        ~Static();
        int    convert(std::string str);

        Static &operator=(Static &obj);
};

#endif