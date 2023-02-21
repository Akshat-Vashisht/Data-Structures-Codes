#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
};
class BinaryTree
{
    Node *root;

public:
    void create();
    void traverse();
    void insert(Node *, Node *);
    void preOrderTraversal(Node *);
    void inOrderTraversal(Node *);
    void postOrderTraversal(Node *);
    BinaryTree()
    {
        root = NULL;
    }
};
void BinaryTree ::create()
{
    Node *temp;
    int val;
    cout << "\nEnter the data you want to enter into the tree: ";
    cin >> val;
    temp = new Node;
    temp->left = NULL;
    temp->data = val;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        insert(root, temp);
    }
}
void BinaryTree::insert(Node *root, Node *temp)
{
    char child;
    cout << "\nThe current node is: " << root->data;
    cout << "\nPlease enter the position you want to add the new node to (L/R): ";
    cin >> child;
    if (child == 'L' || child == 'l')
    {
        if (root->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left, temp);
        }
    }
    if (child == 'R' || child == 'r')
    {
        if (root->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right, temp);
        }
    }
}
void BinaryTree::traverse()
{
    int menu;
    cout << "\nTraversal options: " << endl;
    cout << "\n1. Pre-order Traversal" << endl;
    cout << "2. In-order Traversal" << endl;
    cout << "3. Post-order Traversal" << endl;
    cout << "\nEnter which traversal you want to perform: ";
    cin >> menu;
    cout << "The data after traversal is : ";
    switch (menu)
    {
    case 1:
        preOrderTraversal(root);
        break;
    case 2:
        inOrderTraversal(root);
        break;
    case 3:
        postOrderTraversal(root);
        break;
    default:
        cout << "\nNot a vaild choice";
        break;
    }
}
void BinaryTree::preOrderTraversal(Node *temp)
{
    if (temp!=NULL){
    cout << temp->data << " ";
    preOrderTraversal(temp->left);
    preOrderTraversal(temp->right);
    }
}
void BinaryTree::inOrderTraversal(Node *temp)
{
    if (temp!=NULL){
    inOrderTraversal(temp->left);
    cout << temp->data << " ";
    inOrderTraversal(temp->right);
    }
}
void BinaryTree::postOrderTraversal(Node *temp)
{
    if (temp!=NULL){
    postOrderTraversal(temp->left);
    postOrderTraversal(temp->right);
    cout << temp->data << " ";
    }
}
int main()
{
    BinaryTree bt;
    int menu;
    cout << "\nWelcome to the program of Binary Tree" << endl;
    do
    {
        cout << "\nEnter the operation you want to perform: " << endl;
        cout << "\n1. Create" << endl;
        cout << "2. Traverse" << endl;
        cout << "3. Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            bt.create();
            break;
        case 2:
            bt.traverse();
            break;
        case 3:
            return 0;
        default:
            cout << "\nPlease enter a correct choice" << endl;
            break;
        }
    } while (menu != 3);
    return 0;
}