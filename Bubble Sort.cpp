#include <iostream>
using namespace std;
int main()
{
    int size, pass;
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
    pass = size - 1;
    for (int i = 0; i < pass; i++)
    {
        for (int j = 0; j < pass - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "\nThe sorted array is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}