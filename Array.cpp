/*
Write a C++ program to implement array and its operations:
1) Create an array
2) Display array elements
3) Inserting element into an array at any location
4) Deleting elements of array at any location
5) Find minimum number in array
6) Find maximum number in array
Author:- Akshat Vashisht
Enrollment No.:- MITU21BTIT0006
Date:- 24/08/2022
*/
#include <iostream>
using namespace std;
const int maxsize = 50;
class Array
{
    int size, array[maxsize];

public:
    void setArray();
    void displayArray();
    void insertElement();
    void traverseBackwards();
    void deleteElement();
    void searchArray();
    void maxElement();
    void minElement();
    Array()
    {
        size = 0;
    }
};
void Array::setArray()
{
    cout << "\nEnter the size of the array you want to insert: ";
    cin >> size;
    if (size > maxsize)
    {
        cout << "\nThis size array can not be inserted. Kindly enter a lower amount";
    }
    else
    {
        cout << "\nEnter the elements of the array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
    }
}
void Array::displayArray()
{
    if (size == 0)
    {
        cout << "\nArray does not exist. Kindly create an array using DEFINE ARRAY";
    }
    else
    {
        cout << "\nThe array elements are:- " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
    }
}
void Array::traverseBackwards()
{
    if (size == 0)
    {
        cout << "\nArray does not exist. Kindly create an array using DEFINE ARRAY";
    }
    else
    {
        cout << "\nThe elements of array in reverse order is" << endl;
        for (int i = size - 1; i >= 0; i--)
        {
            cout << array[i] << " ";
        }
    }
}
void Array::insertElement()
{
    if (size == 0)
    {
        cout << "\nArray does not exist. Kindly create an array using DEFINE ARRAY";
    }
    else
    {
        int val, index;
        cout << "\nEnter the value of the element: ";
        cin >> val;
        cout << "\nEnter the position (starting from 1) at which you want to insert a new element: ";
        cin >> index;
        size++;
        for (int i = (size - 1); i >= index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index - 1] = val;
    }
}
void Array::searchArray()
{
    if (size == 0)
    {
        cout << "\nArray does not exist. Kindly create an array using DEFINE ARRAY";
    }
    else
    {
        int val, temp = 0;
        cout << "\nEnter the element you want to search in the array: ";
        cin >> val;
        for (int i = 0; i < size; i++)
        {
            if (val == array[i])
            {
                temp = 1;
                break;
            }
        }
        if (temp == 1)
        {
            cout << "\nThe element " << val << " is present in the array";
        }
        else
        {
            cout << "\nThe element " << val << " is not present in the array";
        }
    }
}
void Array::maxElement()
{
    if (size == 0)
    {
        cout << "\nArray does not exist. Kindly create an array using DEFINE ARRAY";
    }
    else
    {
        int max = array[0];
        for (int i = 0; i < size; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }
        cout << "\nThe max element in the array is " << max;
    }
}
void Array::minElement()
{
    if (size == 0)
    {
        cout << "\nArray does not exist. Kindly create an array using DEFINE ARRAY";
    }
    else
    {
        int min = array[0];
        for (int i = 0; i < size; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        cout << "\nThe min element in the array is " << min;
    }
}
void Array::deleteElement()
{
    if (size == 0)
    {
        cout << "\nArray does not exist. Kindly create an array using DEFINE ARRAY";
    }
    else
    {
        int index;
        cout << "\nEnter the position (starting from 1) of the element you want to delete: ";
        cin >> index;

        for (int i = index; i <= (size - 1); i++)
        {
            array[i - 1] = array[i];
        }
        size--;
    }
}
int main()
{
    int menu;
    Array a;
    cout << "\n*****Welcome to the program of Array operations!*****";
    do
    {
        cout << "\n1. Define Array";
        cout << "\n2. Display Array";
        cout << "\n3. Reverse Array";
        cout << "\n4. Insert an Element in the Array";
        cout << "\n5. Delete an Element from the Array";
        cout << "\n6. Search an Element in the Array";
        cout << "\n7. Find Max Element in the Array";
        cout << "\n8. Find Min Element in the Array";
        cout << "\n9. Exit";
        cout << "\nEnter the operation you want to perform: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            a.setArray();
            break;
        case 2:
            a.displayArray();
            break;
        case 3:
            a.traverseBackwards();
            break;
        case 4:
            a.insertElement();
            break;
        case 5:
            a.deleteElement();
            break;
        case 6:
            a.searchArray();
            break;
        case 7:
            a.maxElement();
            break;
        case 8:
            a.minElement();
            break;
        case 9:
            return 0;
            break;
        default:
            cout << "\nPlease enter a valid input";
        }
    } while (menu != 9);
}
