#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapHelper(int arr[], const int& n, const int& i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapHelper(arr, n, largest);
    }
}

void heapSort(int arr[], const int& n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapHelper(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapHelper(arr, i, 0);
    }
}

void printArray(const int arr[], const int& n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int array[] = {24, 17, 19, 2, 3, 4, 7, 6, 5};
    const int n = sizeof(array) / sizeof(array[0]);

    heapSort(array, n);

    std::cout << "Heap sorted array is \n";
    printArray(array, n);

    return 0;
}
