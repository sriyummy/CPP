//Using Recursion to print the multiplication table of 15

#include <iostream>

void table (int x, int y)
{
    if (y!=1)
    {
        table (x, y-1);
    }

    std::cout << x*y << std::endl;
}

int main()
{
    table (15, 10);

    return 0;
}