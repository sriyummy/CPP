#include <iostream>

int CBRCompare(int *n1, int *n2)
{
    if (* n1 > * n2)
    {
        return *n1;
    }
    else
    {
        return *n2;
    }
}

int main()
{
    int a,b;

    std::cout << "Enter two numbers you want to compare: " << std::endl;
    std::cin >> a >> b;

    std::cout << "The larger number of the two is: " << CBRCompare(&a,&b);

    return 0;
}