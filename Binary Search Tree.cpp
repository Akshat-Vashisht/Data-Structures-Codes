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
public:
    Node *root;
    void create();
    void traverse();
    void insert(Node *, Node *);
    void search(Node *,int key);
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
    if (temp->data<root->data)
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
    if (temp->data>root->data)
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
void BinaryTree::search(Node *root, int key)
{
    if (root==NULL){
        cout<<"\nThe element doesn't exist";
    }
    else {
        if (root->data==key){
            cout<<key<<" is present in the tree";
        }
        else if (key<root->data){
            search(root->left,key);
        }
        else if (key>root->data){
            search(root->right,key);
        }
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
        cout << "\n1. Insert " << endl;
        cout << "2. Search" << endl;
        cout << "3. Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            bt.create();
            break;
        case 2:
            int key;
            cout<<"\nEnter the value you want to search: ";
            cin>>key;
            bt.search(bt.root,key);
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