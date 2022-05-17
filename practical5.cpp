#include <iostream>
using namespace std;

class Hashing
{
public:
    int HashTable[10];

    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = -1;
        }
    }

    void InsertLinearProbe(int value)
    {
        int hash_val = value % 10;

        if (HashTable[hash_val] == value)
        {
            cout << "\rElement already exists!";
        }

        else
        {
            if (hash_val == 9 && HashTable[9] != -1)
            {
                hash_val = 0;
                if (HashTable[hash_val] == -1)
                {
                    HashTable[hash_val] = value;
                }

                else
                {
                    while (HashTable[hash_val] != -1)
                    {
                        hash_val += 1;
                    }
                    HashTable[hash_val] = value;
                }
            }

            else
            {
                while (HashTable[hash_val] != -1)
                {
                    hash_val += 1;
                }
                HashTable[hash_val] = value;
            }
        }

        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            if (HashTable[j] != -1)
            {
                count += 1;
            }
        }

        if (count == 10)
        {
            cout << "\nTable is full!";
        }
    }

    void InsertQuadraticProbe(int value)
    {
        int hash_val = value % 10;
        if (HashTable[hash_val] == value)
        {
            cout << "\nElement already exists!";
        }

        if (HashTable[hash_val] == -1)
        {
            HashTable[hash_val] = value;
        }

        else
        {
            for (int i = 0; i < 10; i++)
            {
                hash_val = (value + i * i) % 10;
                if (HashTable[hash_val] == -1)
                {
                    HashTable[hash_val] = value;
                    break;
                }
            }
        }

        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            if (HashTable[j] != -1)
            {
                count += 1;
            }
        }

        if (count == 10)
        {
            cout << "\nTable is full!";
        }
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "a[" << i << "]" << HashTable[i] << endl;
        }
    }

    void search(int searchkey)
    {
        for (int i = 0; i < 10; i++)
        {
            if (HashTable[i] == searchkey)
            {
                cout << "\nElement " << searchkey << " found!";
            }
        }
    }
};

int main()
{
    Hashing h1;
    int value, searchkey, choice;

    cout << "\n1. Insert using linear probing\n2. Insert using quadratic probing\n3. Display hash table\n4. Search a number\n5. Exit";
    do
    {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter number: ";
            cin >> value;
            h1.InsertLinearProbe(value);
            break;
        case 2:
            cout << "\nEnter number: ";
            cin >> value;
            h1.InsertQuadraticProbe(value);
            break;
        case 3:
            h1.display();
            break;
        case 4:
            cout << "\nEnter number to be searched: ";
            cin >> searchkey;
            h1.search(searchkey);
            break;
        case 5:
            cout << "\nExit";
            break;
        default:
            cout << "\nWrong choice!";
            break;
        }
    } while (choice != 5);
}