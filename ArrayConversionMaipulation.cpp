#include <iostream>

void swap2DArrays(int arr1[][4], int arr2[][4])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp;
        }
    }
}

int main()
{
    const int size = 40;
    int arr[size];

    std::cout << "Enter " << size << " integers:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    int twoDArray[5][2][4];
    int index = 0;
    
    for (int arrayIndex = 0; arrayIndex < 5; arrayIndex++)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                twoDArray[arrayIndex][i][j] = arr[index++];
            }
        }
    }

    swap2DArrays(twoDArray[1], twoDArray[3]);

    index = 0;
    for (int arrayIndex = 0; arrayIndex < 5; arrayIndex++)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                arr[index++] = twoDArray[arrayIndex][i][j];
            }
        }
    }

    std::cout << "Modified array:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
