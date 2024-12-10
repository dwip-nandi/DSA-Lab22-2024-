// User input What types of sorting want
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void printArray(int arr[], int n)
{
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
int main()
{
    cout << "Enter the number of Element of Your Array:";
    int n;
    cin >> n;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "The unsorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    // case cheking
    cout << "Choose a Sorting Algorithm :" << endl;
    cout << "Enter 1 for use Bubble Sort." << endl;
    cout << "Enter 2 for use Selection Sort." << endl;
    cout << "Enter 3 for use Insertion Sort." << endl;
    cout << "-------------" << endl;
    cout << "Enter your Choice:";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        bubbleSort(arr, n);
        cout << "For Sorted Using Bubble sort" << endl;
        break;
    case 2:
        selectionSort(arr, n);
        cout << "For Sorted Using Selection sort" << endl;
        break;
    case 3:
        insertionSort(arr, n);
        cout << "For Sorted Using Insertion sort" << endl;
        break;

    default:
        cout << "Invalid Choose !!" << endl;
        return 1;
    }

    // print the sorted array
    printArray(arr, n);
    cout << endl;
}