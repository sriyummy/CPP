#include <iostream>
#include <algorithm>

void rearrangeArray(int inputArray[][3], int numRows, int numCols)
{
    const int totalElements = numRows * numCols;

    int flattenedArray[totalElements];
    int index = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            flattenedArray[index++] = inputArray[i][j];
        }
    }

    std::sort(flattenedArray, flattenedArray + totalElements);

    index = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            inputArray[i][j] = flattenedArray[index++];
        }
    }
}

int main()
{
    const int numRows = 4;
    const int numCols = 3;
    int originalArray[numRows][numCols] = {{4, 2, 3}, {1, 5, 3}, {4, 5, 2}, {1, 4, 1}};

    rearrangeArray(originalArray, numRows, numCols);

    std::cout << "Modified 2D array:" << std::endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cout << originalArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
