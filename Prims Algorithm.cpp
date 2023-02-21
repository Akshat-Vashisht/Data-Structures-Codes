#include <iostream>
using namespace std;
class Prims
{
public:
    int costMatrix[20][20];
    int v1, v2; // for 2 vertices
    int Visit[20];
    int edges, vertices;
    int row, col;
    int weight;
    int min;
    int finalCost = 0;
    void create();
    void display();
    void MST();

    Prims()
    {
        for (int row = 1; row <= 10; row++)
        {
            for (int col = 1; col <= 10; col++)
            {
                costMatrix[row][col] = -1;
            }
        }
        for (int i = 0; i <= 20; i++)
        {
            Visit[i] = 0;
        }
    }
};
void Prims::create()
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
        cout << "\nEnter its weight :";
        cin >> weight;
        costMatrix[v1][v2] = weight;
        costMatrix[v2][v1] = weight;
    }
}
void Prims::display()
{
    cout << "\nThe matrix representation is: " << endl;
    for (int row = 1; row <= vertices; row++)
    {
        for (int col = 1; col <= vertices; col++)
        {
            cout << costMatrix[row][col] << " ";
        }
        cout << endl;
    }
}
void Prims::MST()
{
    cout << "\nEnter starting vertex: ";
    cin >> v1;
    Visit[v1] = 1;
    for (int k = 1; k <= vertices - 1; k++)
    {
        min = 999;
        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                if (Visit[i] == 1 && Visit[j] == 0)
                {
                    if (costMatrix[i][j] != -1 && min >= costMatrix[i][j])
                    {
                        min = costMatrix[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        finalCost = finalCost + min;
        Visit[col] = 1;
        costMatrix[row][col] = -1;
        costMatrix[col][row] = -1;
    }
    cout << "\nThe cost of MST is " << finalCost;
}

int main()
{
    int menu;
    Prims pr;
    cout << "\nWelcome to the program of prims";
    do
    {
        cout << "\nEnter the operation you want to perform";
        cout << "\n1. Read Graph" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. Prims" << endl;
        cout << "4. Exit " << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            pr.create();
            break;
        case 2:
            pr.display();
            break;
        case 3:
            pr.MST();
            break;
        case 4:
            break;
        default:
            cout << "\nEnter valid input";
            break;
        }
    } while (menu != 4);
    return 0;
}
