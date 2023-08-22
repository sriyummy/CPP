//Program to find out he largest and smallest among 3 entered numbers

#include <iostream>

int max(int a, int b, int c)
{
    if (a>=b && a>=c)
    {
        return a;
    }
    else if (b>=c && b>=a)
    {
        return b;
    } 
    else
    {
        return c;
    }
}

int min(int a, int b, int c)
{
    if (a<=b && a<=c)
    {
        return a;
    }
    else if (b<=c && b<=a)
    {
        return b;
    } 
    else
    {
        return c;
    }
}

int main()
{
    int n1, n2, n3;

    std::cout << "Enter 3 numbers: " << std::endl;
    std::cin >> n1 >> n2 >> n3;

    std::cout << "Largest: " << max(n1,n2,n3) << std::endl;
    std::cout << "Smallest: " << min(n1,n2,n3) << std::endl;

    return 0;
}