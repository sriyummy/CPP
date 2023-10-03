#include <iostream>
#include <cstdlib>

bool isPrime (int no);
int sumPrime (int *array, int size);

bool isPrime (int no)
{
    int c;

    for (c=2; c<((no/2)+1); c++)
    {
        if (no%c == 0)
        {
            return false;
        }
        else if (no == 2)
        {
            return true;
        }
        else
        {
            return true;
        }
    }
}

int sumPrime (int *array, int size)
{
    int sum=0, c=1;

    for (c=0; c<size; c++)
    {
        if(isPrime(array[c]))
        {
            sum += array[c];
        }
    }

    return sum;
}

int main()
{
    int n;
    std::cout << "Enter the number of elements you want in your array: " << std::endl;
    std::cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    std::cout << "Enter the array elements: " << std::endl;
    for (int i=0; i<n; i++)
    {
        std::cout << "Enter element number " << i+1 << ": " << std::endl;
        std::cin >> arr[i];
    }

    std::cout << "The sum of the prime elements in the array is equal to: " << std::endl;
    std::cout << sumPrime (arr, n);
    return 0;
}