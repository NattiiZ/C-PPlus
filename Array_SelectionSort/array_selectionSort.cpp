#include <iostream>
using namespace std;


void selectionSort(int arr[], int size);


int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);


    cout << "Array before sorting : ";
    for (int i=0; i<size; i++)
        cout << arr[i] << " ";

    cout<<"\nSizeof array : "<< size << endl << endl;
    
    selectionSort(arr, size);
    cout << "Array after sorting: ";
    for (int i=0; i<size; i++) 
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}


void selectionSort(int arr[], int size) 
{
    for (int i=0; i<size-1; i++) 
    {
        int minIndex = i;

        for (int j=i+1; j<size; j++) 
        {
            if (arr[j]>arr[minIndex]) 
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        cout << "Round " << i+1 << " = ";
        for (int k=0; k<size; k++)
            cout << arr[k] << " ";
        
        cout << endl;
    }
}