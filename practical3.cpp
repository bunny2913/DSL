#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *ln, *rn;
};

class BST
{
public:
    Node *root;

    Node *create_tree(int key)
    {
        root = new Node();
        root->key = key;
        root->ln = NULL;
        root->rn = NULL;
        return root;
    }

    void InsertNode(int key, Node *root)
    {
        Node *node = new Node();
        node->key = key;
        if (root->key > key)
        {
            if (root->ln == NULL)
            {
                root->ln = node;
            }
            else
            {
                InsertNode(key, root->ln);
            }
        }

        else if (root->key < key)
        {
            if (root->rn == NULL)
            {
                root->rn = node;
            }
            else
            {
                InsertNode(key, root->rn);
            }
        }
        else
        {
            cout << "\nNo duplicates allowed!";
        }
    }

    void SearchNode(int Searchkey, Node *root)
    {
        if (root == NULL)
        {
            cout << "\nTree is empty!";
        }

        if (root->key == Searchkey)
        {
            cout << "\nElement found";
        }

        else if (root->key > Searchkey)
        {
            if (root->ln == NULL)
            {
                cout << "\nElement not found!";
            }
            else
            {
                SearchNode(Searchkey, root->ln);
            }
        }

        else if (root->key < Searchkey)
        {
            if (root->rn == NULL)
            {
                cout << "\nElement not found!";
            }
            else
            {
                SearchNode(Searchkey, root->rn);
            }
        }
    }

    void DisplayInorder(Node *root)
    {
        if (root != NULL)
        {
            DisplayInorder(root->ln);
            cout << root->key << "\n";
            DisplayInorder(root->rn);
        }
    }

    void DisplayMin(Node *root)
    {
        while (root->ln != NULL)
        {
            root = root->ln;
        }
        cout << "Minimum number is: " << root->key;
    }

    int LongestPath(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int LCTR = LongestPath(root->ln);
        int RCTR = LongestPath(root->rn);

        if (LCTR > RCTR)
        {
            return LCTR + 1;
        }
        else
        {
            return RCTR + 1;
        }
    }

    Node *SwapNodes(Node *root)
    {
        Node *temp;
        if (root == NULL)
        {
            return NULL;
        }

        temp = root->ln;
        root->ln = root->rn;
        root->rn = temp;

        SwapNodes(root->ln);
        SwapNodes(root->rn);

        return 0;
    }
};

int main()
{
    int choice, order, flag = 0;
    int key, searchKey;
    BST t1;
    Node *root;

    do
    {
        cout << "\n 1. Enter a number\n2. Display\n3. Dispaly min valued node\n4.Swap left and right nodes\n5. Search\n6. No of nodes in longest path\n7. Exit ";

        cout << "Enter choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the num: ";
            cin >> key;
            if (flag == 0) // NO NODE IS PRESENT IN THE TREE
            {
                root = t1.create_tree(key); // create root
                flag = 1;
            }
            else
            {
                t1.InsertNode(key, root);
            }
            break;

        case 2:
            t1.DisplayInorder(root);
            break;
        case 3:
            t1.DisplayMin(root);
            break;

        case 4:
            t1.SwapNodes(root);
            cout << "Swapped! The new list is : ";
            t1.DisplayInorder(root);
            break;

        case 5:
            cout << "\nEnter the key you want to search : ";
            cin >> searchKey;
            t1.SearchNode(searchKey, root);

            break;
        case 6:
            cout << "The height of the tree or the longest path is :" << t1.LongestPath(root);
            break;
        case 7:
            exit(0);
        }
    } while (choice != 7);
    return 0;
}
