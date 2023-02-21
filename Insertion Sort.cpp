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
    for (int i = 1; i < size; i++)
    {
        while (a[i - 1] > a[i] && i > 0)
        {
            int temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
            i--;
        }
    }
    cout << "\nThe sorted array is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}