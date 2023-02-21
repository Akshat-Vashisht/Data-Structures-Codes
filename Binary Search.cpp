#include <iostream>
using namespace std;
int main()
{
    int size, key;
    cout << "\nInput the size of the array: ";
    cin >> size;
    int a[size];
    int low = 0;
    int high = size - 1;
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
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            cout << "\nElement " << key << " found at position " << mid + 1;
            break;
        }
        else if (key > a[mid])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (low>high)
    {
        cout << "\nElement " << key << " is not present in the list";
    }
}