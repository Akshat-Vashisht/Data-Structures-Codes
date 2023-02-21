#include <iostream>
using namespace std;
int main()
{
    int size, key;
    cout << "\nInput the size of the array: ";
    cin >> size;
    int a[size];
    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "\nThe array is" << endl;
    for (int i = 0; i < size; i++)
    {

        cout << a[i] << " ";
    }
    cout << "\nEnter the element you want to search ";
    cin >> key;
    int last = a[size - 1];
    a[size - 1] = key;
    int i = 0;
    while (a[i] != key)
    {
        i++;
    }
    a[size - 1] = last;
    if (key == a[size - 1] || i < size - 1)
    {
        cout << "Element " << key << " is present at " << i + 1 << " position";
    }
    else
    {
        cout << "Element " << key << " is not present in the list";
    }
}