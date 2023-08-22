//Program to add 2 numbers using Functions

#include <iostream>

int sum (int x, int y)
{
    return x+y;
}

int main()
{
    int a, b;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> a >> b;

    std::cout << "The sum of " << a << " and " << b << " is: " << sum(a,b);
}