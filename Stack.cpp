#include <iostream>
using namespace std;
#define SIZE 5
class Stack
{
    int top;
    int array[SIZE];

public:
    void pop();
    void push();
    void display();
    bool isFull();
    bool isEmpty();
    Stack()
    {
        top = -1;
    }
};
bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Stack::isFull()
{
    if (top == SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack::push()
{
    if (isFull())
    {
        cout << "\nThe stack is full";
    }
    else
    {
        int val;
        cout << "\nEnter the value you want to add: ";
        cin >> val;
        top++;
        array[top] = val;
    }
}
void Stack::pop()
{
    if (isEmpty())
    {
        cout << "\nThe stack is empty";
    }
    else
    {
        top--;
        cout << "\nElement deleted from the top of stack";
    }
}
void Stack::display()
{
    if (isEmpty())
    {
        cout << "\nThe stack is empty";
    }
    else
    {
        cout << "\nStack elements are: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << endl;
        }
    }
}
int main()
{
    int menu;
    Stack s;
    cout << "\nWelcome to the program of Stack";
    do
    {
        cout << "\nEnter the operation you want to perform";
        cout << "\n1) Push" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Display" << endl;
        cout << "4) Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "\nKindly enter a valid input";
        }
    } while (menu != 4);
    return 0;
}