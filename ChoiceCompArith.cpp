/*Write a menu driven program to create a structure to represent complex number and perform the following operation using function.
1. addition of two complex number  (call by value)
2. multiplication of two complex number (call by address)*/

#include <iostream>

struct Complex
{
    float real, imaginary;
};

Complex addComplex(Complex no1, Complex no2)
{
    Complex sum;
    sum.real = no1.real + no2.real;
    sum.imaginary = no1.imaginary + no2.imaginary;

    return sum;
}

Complex prodComplex(Complex *no1, Complex *no2)
{
    Complex prod;
    prod.real = (no1->real * no2->real) - (no1->imaginary * no2->imaginary);
    prod.imaginary = (no1->real * no2->imaginary) + (no1->imaginary * no2->real);

    return prod;
}

int main()
{
    Complex n1, n2, res;
    int ch;

    std::cout << "Enter 1 to add 2 complex numbers.\nEnter 2 to multiply 2 complex numbers." << std::endl;
    std::cin >> ch;
    
    switch (ch)
    {
        case 1:
        {
            std::cout << "Enter the real and imaginary parts of the first number:";
            std::cin >> n1.real >> n1.imaginary;

            std::cout << "\nEnter the real and imaginary parts of the second number:";
            std::cin >> n2.real >> n2.imaginary;

            res = addComplex(n1, n2);
            std::cout << "The sum is: " << res.real << " + " << res.imaginary << "i" << std::endl;

            break;
        }

        case 2:
        {
            std::cout << "Enter the real and imaginary parts of the first number:";
            std::cin >> n1.real >> n1.imaginary;

            std::cout << "\nEnter the real and imaginary parts of the second number:";
            std::cin >> n2.real >> n2.imaginary;

            res = prodComplex(&n1, &n2);
            std::cout << "The product is: " << res.real << " + " << res.imaginary << "i" << std::endl;

            break;
        }

        default:
        {
            std::cout << "Please enter a valid choice!" << std::endl;
            break;
        }
    }

    return 0;
}
