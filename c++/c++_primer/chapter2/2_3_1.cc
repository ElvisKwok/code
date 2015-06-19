#include <iostream>

int main()
{
    int base, exp;
    long result = 1;
    std::cout << "enter a base: ";
    std::cin >> base;
    std::cout << "enter a exponent: ";
    std::cin >> exp;

    if (exp < 0) {
        std::cout << "Exponent can't be smaller than 0" << std::endl;
        return -1;
    }

    for (int i = 0; i < exp; i++)
        result *= base;
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
