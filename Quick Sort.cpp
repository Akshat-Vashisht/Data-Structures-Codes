#include <iostream>
using namespace std;
int partition(int array[], int lb, int ub)
{
    int pivot = array[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    if (start > end)
    {
        int temp = array[end];
        array[end] = array[lb];
        array[lb] = temp;
    }
    return end;
}
void quickSort(int array[], int lb, int ub)
{
    if (lb < ub)
    {
        int pos = partition(array, lb, ub);
        quickSort(array, lb, pos - 1);
        quickSort(array, pos + 1, ub);
    }
}
int main()
{
    int size;
    cout << "\nInput the size of the array: ";
    cin >> size;
    int a[size];
    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "\nThe unsorted array is" << endl;
    for (int i = 0; i < size; i++)
    {

        cout << a[i] << " ";
    }
    quickSort(a, 0, size - 1);
    cout << "\nThe sorted array is" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}