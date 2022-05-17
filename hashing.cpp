#include <iostream>

using namespace std;

class hashing
{
public:
    int size;
    int *HashTable = new int[size];
    hashing() // Default constructor
    {
        cout << "\nEnter size of hash table: ";
        cin >> size;
        for (int i = 0; i < size; i++) // all array elements set to -1 for reference
        {
            HashTable[i] = -1;
        }
    }

    void insertElementLinearProbing(long long int value) // function for linear probing
    {
        int hash_val = value % size; // hash value or key

        for (int i = 0; i < size; i++)
        {
            if (HashTable[i] == value)
            {
                cout << "Element already exists!";
            }
        }

        if (HashTable[hash_val] == -1)
        {
            HashTable[hash_val] = value;
        }

        else
        {
            if (hash_val == size - 1 && HashTable[size - 1] != -1) // jumping from last element to first element
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

        for (int i = 0; i < size; i++)
        {
            if (HashTable[i] != -1)
                count += 1;
        }

        if (count == size)
        {
            cout << "\nTable full!";
        }
    }

    void insertElementLQuadraticProbing(long long int value) // function for quadratic probing
    {
        int hash_val = value % size;

        for (int i = 0; i < size; i++)
        {
            if (HashTable[i] == value)
            {
                cout << "Element already exists!";
            }
        }

        if (HashTable[hash_val] == -1)
        {
            HashTable[hash_val] = value;
        }

        else
        {
            for (int j = 1; j < size; j++)
            {
                int hash_new = (hash_val + (j * j)) % size; // new key

                if (HashTable[hash_new] == -1)
                {
                    HashTable[hash_new] = value;
                    break;
                }

                else
                {
                    cout << "\nBlock not empty";
                }
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "\na[" << i << "] :" << HashTable[i];
        }
    }

    void SearchNumber(long long int temp)
    {
        int temp1;
        for (int i = 0; i < size; i++)
        {
            if (temp == HashTable[i])
            {
                cout << "\nNumber found!";
                break;
            }
            else
            {
                cout << "\nnumber not found!";
                break;
            }
        }
    }
};

int main()
{
    hashing h;
    long long int num, temp;
    int ch, ret;
    cout << "Telephone Directory";
    cout << "\n1.Insert using linear probing\n2.Insert using quadratic probing\n3.Display\n4.Search a number\n5.Exit";
    do
    {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter phone no. to be inserted : ";
            cin >> num;
            h.insertElementLinearProbing(num);
            break;
        case 2:
            cout << "\nEnter phone no. to be inserted : ";
            cin >> num;
            h.insertElementLQuadraticProbing(num);
            break;
        case 3:
            cout << "Telephone Directory";
            h.display();
            break;
        case 4:
            cout << "\nEnter number to be searched: ";
            cin >> temp;
            h.SearchNumber(temp);
            break;
        case 5:
            cout << "\nExit!";
        default:
            cout << "\nWrong choice!";
        }
    } while (ch != 5);
}

// Skip list

/* #include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;

} * HashTable[10];

class hashing
{
public:
    hashing()
    {

        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }
    }

    int HashFunction(int value)
    {
        return (value % 10);
    }

    node *create_node(int x)
    {
        node *temp = new node;
        temp->next = NULL;
        temp->value = x;
        return temp;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            node *temp = new node;
            temp = HashTable[i];
            cout << "a[" << i << "] : ";
            while (temp != NULL)
            {
                cout << " ->" << temp->value;
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    bool searchElement(int value)
    {
        bool flag = false;
        int hash_val = HashFunction(value);
        node *entry = HashTable[hash_val];
        cout << "\nElement found at : ";
        while (entry != NULL)
        {
            if (entry->value == value)
            {
                cout << hash_val << " : " << entry->value << endl;
                flag = true;
            }

            entry = entry->next;
        }
        return flag;
    }

    void deleteElement(int value)
    {

        int hash_val = HashFunction(value);
        node *entry = HashTable[hash_val];

        if (entry == NULL)
        {
            cout << "No Element found ";
            return;
        }

        if (entry->value == value)
        {
            HashTable[hash_val] = entry->next;
            return;
        }
        while ((entry->next)->value != value)
        {
            entry = entry->next;
        }
        entry->next = (entry->next)->next;
    }

    void insertElement(int value)
    {
        int hash_val = HashFunction(value);
        node *temp = new node;
        node *head = new node;
        head = create_node(value);
        temp = HashTable[hash_val];
        if (temp == NULL)
        {
            HashTable[hash_val] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
};

int main()
{
    int ch;
    int data, search, del;
    hashing h;
    do
    {
        cout << "\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit \n\n OPTION: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter phone no. to be inserted : ";
            cin >> data;
            h.insertElement(data);
            break;
        case 2:
            h.display();
            break;
        case 3:
            cout << "\nEnter the no to be searched : ";
            cin >> search;

            if (h.searchElement(search) == true)
            {
                cout << "No element found at key ";
                continue;
            }
            break;
        case 4:
            cout << "\nEnter the phno. to be deleted : ";
            cin >> del;
            h.deleteElement(del);
            cout << "Phno. Deleted" << endl;
            break;
        }
    } while (ch != 5);

    return 0;
} */