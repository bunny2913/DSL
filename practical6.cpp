#include <iostream>
#include <iomanip>
using namespace std;

class graph
{
public:
    int ar[50][50];
    string names[15];
    int city1, city2;

    void createarray(int cities)
    {
        for (int i = 0; i < cities; i++)
        {
            for (int j = 0; j < cities; j++)
            {
                ar[i][j] = 0;
            }
        }
    }

    void insert(int city1, int city2)
    {
        cout << "\rEnter distance b/w " << city1 << " and " << city2 << ": ";
        cin >> ar[city1][city2];
        ar[city2][city1] = ar[city1][city2];
    }

    void display(int cities)
    {
        for (int i = 0; i < cities; i++)
        {
            cout << setw(5) << names[i];
        }
        cout << endl;

        for (int i = 0; i < cities; i++)
        {
            cout << names[i];

            for (int j = 0; j < cities; j++)
            {
                cout << setw(5) << ar[i][j];
            }
            cout << endl;
        }
    }
};

int main()
{
    graph obj;
    int edges, city1, city2, cities;

    cout << "\nEnter number of cities: ";
    cin >> cities;
    obj.createarray(cities);

    for (int i = 0; i < cities; i++)
    {
        cout << "\rEnter name of city: ";
        cin >> obj.names[i];
    }
    cout << "\nEnter number of edges: ";
    cin >> edges;

    for (int j = 0; j < edges; j++)
    {
        cout << "\nEnter city-1: ";
        cin >> city1;
        cout << "\rEnter city-2: ";
        cin >> city2;
        obj.insert(city1, city2);
    }

    obj.display(cities);
    return 0;
}