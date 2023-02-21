#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
class LinearQueue
{
    int array[MAX_SIZE];
    int front;
    int rear;

public:
    LinearQueue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue();
    void dequeue();
    bool isFull();
    bool isEmpty();
    void display();
};
void LinearQueue ::enqueue()
{
    int element;
    if (isEmpty())
    {
        front = 0;
        rear = 0;
        cout << "\nEnter the element you want to add to the linear queue: ";
        cin >> element;
        array[rear] = element;
    }
    else if (isFull())
    {
        cout << "\nThe linear queue is currently full";
    }
    else
    {
        rear++;
        cout << "\nEnter the element you want to add to the linear queue: ";
        cin >> element;
        array[rear] = element;
    }
}
void LinearQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "\nThe linear queue is currently empty";
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        cout << "\nElement dequeued";
    }
    else
    {
        front++;
        cout << "\nElement dequeued";
    }
}
bool LinearQueue::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
        return false;
}
bool LinearQueue::isFull()
{
    if (rear == MAX_SIZE - 1)
    {
        return true;
    }
    else
        return false;
}
void LinearQueue::display()
{
    if (isEmpty())
    {
        cout << "\nThe linear queue is currently empty";
    }
    else
    {
        cout << "\nThe elements of the queue are:- " << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << array[i] << " ";
        }
    }
}
int main()
{
    LinearQueue lq;
    cout << "\n*****WELCOME TO THE PROGRAM OF LINEAR QUEUE" << endl;
    int menu;
    do
    {
        cout << "\nEnter the operation you want to perform";
        cout << "\n1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) Display" << endl;
        cout << "4) Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            lq.enqueue();
            break;
        case 2:
            lq.dequeue();
            break;
        case 3:
            lq.display();
            break;
        case 4:
            return 0;
            break;
        }
    } while (menu != 4);
    return 0;
}
