#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
class dfs
{
public:
    int stack[50];
    int top = -1;
    int array[50][50] = {};
    string name[10];
    int area1, area2;
    int poped;
    int visited[30];
    int bsf_visited[30];
    int q[50];
    int front, rear;
    dfs()
    {
        for (int i = 0; i < 30; i++)
        {
            visited[i] = 0;
            bsf_visited[i] = 0;
        }
    }
    void push(int a)
    {
        stack[++top] = a;
    }
    int pop()
    {
        int Value;
        Value = stack[top];
        top--;
        return Value;
    }
    void array_creation(int areas)
    {
        int array[areas][areas];
        for (int i = 0; i < areas; i++)
        {
            for (int j = 0; j < areas; j++)
            {
                array[i][j] = 0;
            }
        }
    }
    void insert(int area_a, int area_b)
    {
        array[area_a][area_b] = 1;
        array[area_b][area_a] = array[area_a][area_b];
    }
    void DisplayGraph(int areas)
    {
        cout << setw(5) << "";
        for (int i = 0; i < areas; i++)
        {
            cout << setw(5) << name[i];
        }
        cout << endl;
        for (int i = 0; i < areas; i++)
        {
            cout << setw(5) << name[i];
            for (int j = 0; j < areas; j++)
            {
                cout << setw(5) << array[i][j];
            }
            cout << endl;
        }
    }
    int displayDfs(int v1, int areas)
    {
        int v2;
        cout << "DFS search is" << endl;
        push(v1);
        while (top != -1)
        {
            v1 = pop();
            if (visited[v1] == 0)
            {
                cout << v1 << endl;
                visited[v1] = 1;
            }
            for (int v2 = 0; v2 < areas; v2++)
                if (array[v1][v2] == 1 && visited[v2] == 0)
                    push(v2);
        }
        return 0;
    }
    int displayBsf(int v1, int areas)
    {
        cout << "BSF search is \n";
        int v2;
        bsf_visited[v1] = 1;
        front = rear = -1;
        q[++rear] = v1;
        while (front != rear)
        {
            v1 = q[++front];
            cout
                << v1 << "\n";
            for (int v2 = 0; v2 < areas; v2++)
            {
                if (array[v1][v2] == 1 && bsf_visited[v2] == 0)
                {
                    q[++rear] = v2;
                    bsf_visited[v2] = 1;
                }
            }
        }
        return 0;
    }
};
int main()
{
    dfs obj;
    int areas, area_a, area_b, edge, choice, v2;
    do
    {
        cout << "==============Enter your choice==============" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Display By DSF" << endl;
        cout << "3) Display by BSF" << endl;
        cout << "4) Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter how many areas:- ";
            cin >> areas;
            obj.array_creation(areas);
            for (int i = 0; i < areas; i++)
            {
                cout << "Enter the name of area ";
                cin >> obj.name[i];
            }
            cout << "\nEnter number of edge ";
            cin >> edge;
            for (int i = 0; i < edge; i++)
            {
                cout << "\nEnter the area number 1:- ";
                cin >> area_a;
                cout << "\nEnter the area number 2:- ";
                cin >> area_b;
                obj.insert(area_a, area_b);
            }
            obj.DisplayGraph(areas);
            break;
        case 2:
            cout << "Enter the vertex from which you want to traverse: ";
            cin >> v2;
            obj.displayDfs(v2, areas);
            break;
        case 3:
            cout << "Enter the vertex from which you want to traverse: ";
            cin >> v2;
            obj.displayBsf(v2, areas);
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice < 4);
    return 0;
}