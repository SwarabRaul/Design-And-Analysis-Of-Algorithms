#include <iostream>

using namespace std;

void swap(int *a, int *b);
void InsertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int n;
    cout << "Enter the number of Elements: " << endl;
    cin >> n;

    int arr[n];
    cout << "Please enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    InsertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void InsertionSort(int arr[], int n)
{
    int i = 0, key = 0, j = 0;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            swap(arr[j], arr[j + 1]);
            j = j - 1;
        }
    }
}