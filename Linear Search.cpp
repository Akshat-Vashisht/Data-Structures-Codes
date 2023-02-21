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
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (a[i] == key)
        {
            cout << "Element " << key << " is present at " << i + 1 << " position";
            break;
        }
    }
    if (i == size)
    {
        cout << "Element " << key << " is not present in the list";
    }
}