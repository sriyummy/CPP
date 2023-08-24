//Program to find the n'th term of the Fibonacci Series using Recursion

#include <iostream>

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    std::cout << "Enter the n'th term you want to find of the Fibonacci Series: " << std::endl;
    std::cin >> n;

    int result = fibonacci(n-1);
    std::cout << "The " << n << "th term of the Fibonacci series is: " << result << std::endl;
    
    return 0;
}
