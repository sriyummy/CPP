//Print the Factorial of a Number using Functions

#include <iostream>

int factorial (int number)
{
    int fact =1;
    
    if (number>1)
    {
        for (int i=number; i>=2; i--)
        {
            fact = fact * i;
        }
        
        return fact;
    }
    else if (number==1 || number==0)
    {
        fact = 1;
        
        return fact;
    }

    else
    {
        std::cout << "Bad Input" << std::endl;
        return 0;
    }
}

int main()
{
    int n;

    std::cout << "Enter a number: " << std::endl;
    std::cin >> n;

    std::cout << "Factorial of " << n << " is: " << factorial(n) << std::endl;

    return 0;
}