#ifndef STATIC_HPP
#define STATIC_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Static
{
    private :
        Static();
        Static(Static &obj);

    public :
        ~Static();
        static int    convert(std::string str);

        Static &operator=(Static &obj);
};

#endif