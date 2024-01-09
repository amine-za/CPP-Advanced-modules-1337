#include <vector>
#include <deque>
#include <iostream>

int main()
{
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(22);
    dq.push_back(33);
    dq.push_back(44);
    dq.push_back(55);
    std::deque<int>::iterator iter = dq.begin() + 2;
    std::cout << *iter << std::endl;
}