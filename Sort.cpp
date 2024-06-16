#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values = {3, 5, 1, 4, 2};

    std::sort(values.begin(), values.end(), std::greater<int>());

    for (int value : values)
        std::cout << value << std::endl;

    std::sort(values.begin(), values.end(), [](int a, int b) { // if you use an function you have to return true if a should be before than b and false otherwise.
        if (a == 1)
            return false;
        if (b == 1)
            return true;
        return a < b;

    });

    for (int value : values)
        std::cout << value << std::endl;
}