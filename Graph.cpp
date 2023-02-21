#include <iostream>
using namespace std;
class Graph
{
public:
    int g[20][20];
    int v1, v2; // for 2 vertices
    int edges, vertices;
    int Queue[20];   // for bfs
    int front, rear; // to manage queue
    void add(int);   // queue fun
    int remove();    // queue fun
    int Visit[20];   // for bfs (track visited)
    int Stack[20];   // for dfs
    int top;         // stack fun
    void push(int);
    int pop();
    void create();
    void display();
    void BFS();
    void DFS();
    Graph()
    {
        for (int row = 1; row <= 10; row++)
        {
            for (int col = 1; col <= 10; col++)
            {
                g[row][col] = 0;
            }
        }
        front = rear = -1;            // for queue
        top = -1;                     // for stack
        for (int i = 0; i <= 10; i++) // all vertices unvisited
        {
            Visit[i] = 0;
        }
    }
};
void Graph::create()
{
    cout << "\nEnter number of vertices: ";
    cin >> vertices;
    cout << "\nEnter number of edges: ";
    cin >> edges;
    for (int i = 1; i <= edges; i++)
    {
        cout << "Enter an edge (Vertex V1 and V2): ";
        cin >> v1;
        cin >> v2;
        g[v1][v2] = 1;
        g[v2][v1] = 1;
    }
}
void Graph::display()
{
    cout << "\nThe matrix representation is: " << endl;
    for (int row = 1; row <= vertices; row++)
    {
        for (int col = 1; col <= vertices; col++)
        {
            cout << g[row][col] << " ";
        }
        cout << endl;
    }
}
void Graph::add(int v1)
{
    Queue[++rear] = v1;
}
void Graph::BFS()
{
    cout << "\nEnter the starting vertex for BFS: ";
    cin >> v1;
    add(v1);
    while (front != rear)
    {
        v1 = remove();
        Visit[v1] = 1;
        cout << v1 << " ";
        for (v2 = 1; v2 <= vertices; v2++)
        {
            if (g[v1][v2] == 1 && Visit[v2] == 0)
            {
                add(v2);
                Visit[v2] = 1;
            }
        }
    }
}
int Graph::remove()
{
    return Queue[++front];
}
void Graph::DFS()
{
    cout << "\nEnter starting vertex for DFS: ";
    cin >> v1;
    push(v1);
    while (top != -1)
    {
        v1 = pop();
        if (Visit[v1] == 0)
        {
            cout << v1 << " ";
            Visit[v1] = 1;
            for (v2 = 1; v2 <= vertices; v2++)
            {
                if (g[v1][v2] == 1)
                {
                    push(v2);
                }
            }
        }
    }
}
void Graph::push(int v1)
{
    Stack[++top] = v1;
}
int Graph::pop()
{
    return Stack[top--];
}
int main()
{
    int menu;
    Graph gr;
    cout << "\nWelcome to the program of graph";
    do
    {
        cout << "\nEnter the operation you want to perform";
        cout << "\n1. Read Graph" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. BFS " << endl;
        cout << "4. DFS " << endl;
        cout << "5. Exit " << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            gr.create();
            break;
        case 2:
            gr.display();
            break;
        case 3:
            gr.BFS();
            for (int i = 0; i <= 10; i++)
            {
                gr.Visit[i] = 0;
            }
            break;
        case 4:
            gr.DFS();
            for (int i = 0; i <= 10; i++)
            {
                gr.Visit[i] = 0;
            }
            break;
        case 5:
            break;
        default:
            cout << "\nEnter valid input";
            break;
        }
    } while (menu != 5);
    return 0;
}