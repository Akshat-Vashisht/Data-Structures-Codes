#include <iostream>
using namespace std;
#define MAX_SIZE 5
class CircularQueue
{
    int queue[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }
    void enqueue();
    void dequeue();
    void display();
    bool isFull();
    bool isEmpty();
}; 
bool CircularQueue::isFull()
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CircularQueue::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void CircularQueue::enqueue()
{
    int element;
    if (isFull())
    {
        cout << "\nThe circular queue is full";
    }
    else if (isEmpty())
    {
        front = rear = 0;
        cout<<"\nEnter the element you want to add to the queue: ";
        cin>>element;
        queue[rear] = element;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
        cout<<"\nEnter the element you want to add to the queue: ";
        cin>>element;
        queue[rear] = element;
    }
}
void CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "\nThe circular queue is empty";
    }
    else if (front == rear)
    {
        front = rear = -1;
        cout << "\nElement deleted";
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
        cout << "\nElement deleted";
    }
}
void CircularQueue::display()
{
    if (isEmpty())
    {
        cout << "\nThe circular queue is empty";
    }
    else
    {
        int i = front;
        while (i!=rear){
            cout<<queue[i]<<" ";
            i = (i+1)%MAX_SIZE;
        } 
        cout<<queue[i];
        cout<<endl;
    }
}
int main()
{
    CircularQueue cq;
    cout << "\n*****WELCOME TO THE PROGRAM OF CIRCULAR QUEUE" << endl;
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
            cq.enqueue();
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            return 0;
            break;
        }
    } while (menu != 4);
    return 0;
}