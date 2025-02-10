#include <iostream>
using namespace std;

void selectionSort2D(int arr[][4], int rows, int cols);


int main()
{
    int matrix[][4] = {{5, 2, 9, 7}, {8, 1, 6, 2}, {3, 7, 4, 1}};
    int rows = 3;
    int cols = 4;

    cout << "Before Sorting 2D array:" << endl;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    selectionSort2D(matrix, rows, cols);
    cout << "Sorted 2D array:" << std::endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}


void selectionSort2D(int arr[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            int minIndex = j;
            for (int k = j + 1; k < cols; k++)
            {
                if (arr[i][k] < arr[i][minIndex])
                {
                    minIndex = k;
                }
            }
            // Swap the elements
            if (minIndex != j)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[i][minIndex];
                arr[i][minIndex] = temp;
            }
        }
    }
}