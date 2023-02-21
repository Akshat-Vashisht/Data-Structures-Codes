#include <iostream>
using namespace std;
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
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    cout << "\nThe sorted array is" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}