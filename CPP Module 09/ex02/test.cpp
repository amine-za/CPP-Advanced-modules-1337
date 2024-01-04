#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::vector<int>::iterator it = v.begin()+2;
    std::cout << *it << std::endl;
    v.pop_back();
    // v.push_back(4869);
    std::cout << *it << std::endl;
    // for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    //     std::cout << *it << std::endl;
}