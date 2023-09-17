#include <iostream>

int** getMiddleRows(int inputArray[][3], int numRows, int numCols)
{
    int middleRowIndex = numRows / 2;
    
    int** middleRows = new int*[1];
    
    middleRows[0] = new int[numCols];
    for (int i = 0; i < numCols; i++)
    {
        middleRows[0][i] = inputArray[middleRowIndex][i];
    }
    
    return middleRows;
}

int main()
{
    const int numRows = 4;
    const int numCols = 3;
    int twoDimensionalArray[numRows][numCols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    int** middleRows = getMiddleRows(twoDimensionalArray, numRows, numCols);

    int middleRowCount = 1; 
    std::cout << "Middle Row(s):" << std::endl;
    for (int i = 0; i < middleRowCount; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cout << middleRows[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < middleRowCount; i++)
    {
        delete[] middleRows[i];
    }
    delete[] middleRows;
    
    return 0;
}
