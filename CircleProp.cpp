//Print the Area and Circumference of a Ciecle

#include <iostream>

float circumference(float radius)
{
    return 2*3.14*radius;
}

float area(float radius)
{
    return 3.14*radius*radius;
}

int main()
{
    float r;

    std::cout << "Enter the radius of the circle: " << std::endl;
    std::cin >> r;

    std::cout << "Circumference = " << circumference(r) << "\nArea = " << area(r);
}