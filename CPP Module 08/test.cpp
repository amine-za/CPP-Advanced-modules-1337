#include <iostream>
#include <vector>
#include <stack>

int main()
{
    // std::vector<int> vec;
    int array[] = {1, 24, 5, 67,22};
    // std::vector<int> vec(array, &array[4]);
    // // vec.push_back(33);
    // std::cout <<  vec.front() << std::endl; 
    // std::cout << vec.size() << std::endl;
    // std::cout << vec.capacity() << std::endl;
    std::vector<int> vec(array, array+5);
    vec.push_back(1337);
    // vec.push_back(2);
    // vec.push_back(42);
    // std::cout << vec[2] << std::endl;
    // vec.pop_back();
    std::vector<int>::iterator it = vec[2];
    std::cout << it << std::endl;
    std::cout << vec[0] << std::endl;
    return 0;
}