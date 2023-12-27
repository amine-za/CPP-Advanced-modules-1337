#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {1, 2, 3};
    std::vector<int>::iterator it = v.begin();
    // if (v.begin() == v.end())
    //     std::cout << "v is empty" << std::endl;
    // std::cout << *(v.begin()) << std::endl;
    v.insert(v.begin(), 4869);
    std::cout << *(v.begin());
    std::cout << *it;
}