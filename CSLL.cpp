#include <iostream>
using namespace std;
class node // Class node to have two elements 1) data 2) pointer to next node
{
public:
    node *next;
    int data;
};
class CSLL
{
    node *head, *last; // Head will point to the first node and last will point to the last node
public:
    // Methods to perform the required functionality
    void create();
    void traverse();
    void length();
    void search();
    void insert();
    void remove();
    CSLL() // Constructor to set the initial and final node to NULL when object is created
    {
        head = NULL;
        last = NULL;
    }
};
void CSLL::create()
{
    node *temp; // New node
    int val;
    cout << "\nEnter the value you want to enter in the node: ";
    cin >> val;
    temp = new node; // Memory allocation to temp
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) // If list is not there head and last will point to the same node
    {
        head = temp;
        last = temp;
    }
    else // Otherwise if list is there
    {
        last->next = temp; // last's next pointer points to the new node thus creating a link
        last = temp;       // the temp node becomes the last node
    }
    last->next = head;
}
void CSLL::traverse()
{
    node *temp = head;
    if (temp != NULL) // If condition to check whether the list exists
    {
        cout << "\nLinked List Elements are:- " << endl;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    else
    {
        cout << "\nThe linked list does not exist. Kindly create a new node." << endl;
    }
}
void CSLL ::length()
{
    int length = 0;
    node *temp = head;
    if (temp != NULL)
    {
        do
        {
            length++;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    else
    {
        cout << "\nThe linked list does not exist. Kindly create a new node. " << endl;
    }
    cout << "\nThe length of the linked list is " << length << "." << endl;
}
void CSLL::search()
{
    node *temp = head;
    int key;
    int flag = 1;
    if (temp != NULL)
    {
        cout << "\nEnter the element you want to search: ";
        cin >> key;
        do
        {
            if (temp->data == key)
            {
                cout << "\n"
                     << key << " is present in the linked list." << endl;
                flag = 0;
                break;
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != head);
        if (flag == 1)
        {
            cout << "\n"
                 << key << " is not present in the linked list." << endl;
        }
    }
    else
    {
        cout << "\nThe linked list does not exist. Kindly create a new node. " << endl;
    }
}
void CSLL::insert()
{
    node *temp = head;
    node *newNode;
    int val, key;
    if (temp != NULL)
    {

        int menu;
        cout << "\nWhere do you want to insert the node" << endl;
        cout << "1. At the beginning" << endl;
        cout << "2. At the end" << endl;
        cout << "3. After a particular element" << endl;
        cin >> menu;
        cout << "\nEnter the value you want to add ";
        cin >> val;
        newNode = new node;
        newNode->data = val;
        newNode->next = NULL;
        switch (menu)
        {
        case 1:
            newNode->next = head;
            last->next = newNode;
            head = newNode;
            cout << "\nNode inserted at the starting position" << endl;
            break;
        case 2:
            last->next = newNode;
            newNode->next = head;
            last = newNode;
            cout << "\nNode inserted at the ending position" << endl;
            break;
        case 3:
            cout << "\nEnter the value after which you want to insert the element ";
            cin >> key;
            while (temp != NULL)
            {
                if (temp->data == key)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
            cout << "\nNode inserted after " << key << endl;
            break;
        default:
            cout << "\nEnter a correct value " << endl;
            break;
        }
    }

    else
    {
        cout << "\nThe linked list does not exist. Kindly create a new node. " << endl;
    }
}
void CSLL::remove()
{
    node *temp = head;
    node *newNode;
    int key;
    if (temp != NULL)
    {

        int menu;
        cout << "\nWhere do you want to delete the node from" << endl;
        cout << "1. At the beginning" << endl;
        cout << "2. At the end" << endl;
        cout << "3. Delete a particular element" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            cout << "\nNode deleted from the starting position" << endl;
            break;
        case 2:
            while (temp->next != last)
            {
                temp = temp->next;
            }
            last = temp;
            temp = temp->next;
            delete temp;
            last->next = head;
            cout << "\nNode deleted from the ending position" << endl;
            break;
        case 3:
            cout << "\nEnter the value which you want to delete ";
            cin >> key;
            while (temp != NULL)
            {
                if (temp->data == key)
                {
                    break;
                }
                else
                {
                    newNode = temp;
                    temp = temp->next;
                }
            }

            newNode->next = temp->next;
            delete temp;

            cout << "\nNode " << key << " deleted" << endl;
            break;
        default:
            cout << "\nEnter a correct value " << endl;
            break;
        }
    }

    else
    {
        cout << "\nThe linked list does not exist. Kindly create a new node. " << endl;
    }
}
int main()
{
    CSLL cs;
    int menu;
    cout << "***WELCOME TO CSLL****" << endl;
    do // do while loop to create a menu driven program +
    {
        cout << "\n1. Create a New Node " << endl
             << "2. Traverse Elements of CSLL" << endl
             << "3. Display Length of CSLL " << endl
             << "4. Search Element in CSLL" << endl
             << "5. Insert Node in CSLL" << endl
             << "6. Delete Node from CSLL" << endl
             << "7. Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            cs.create();
            break;
        case 2:
            cs.traverse();
            break;
        case 3:
            cs.length();
            break;
        case 4:
            cs.search();
            break;
        case 5:
            cs.insert();
            break;
        case 6:
            cs.remove();
            break;
        case 7:
            cout << "\nThank you for using the program of Circular Singly Linked List." << endl;
            return 0;
            break;
        default:
            cout << "\nKindly enter a valid input" << endl;
        }
    } while (menu != 7);
    return 0;
}