#include <iostream>
using namespace std;

struct Node
{
    char label[15];
    int ch_count;

    Node *child[15];
} * root;

class Tree
{
public:
    void createTree();
    void displayTree(Node *r1);

    Tree()
    {
        root = NULL;
    }
};

void Tree::createTree()
{
    int tchapters, i, j, k;

    root = new Node(); // root node is created
    cout << "Enter name of book: ";
    cin >> root->label;

    cout << "Enter no. of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;

    for (i = 0; i < tchapters; i++) // chapters
    {
        root->child[i] = new Node; // chapter is created

        cout << "Enter Chapter name: \n";
        cin >> root->child[i]->label;

        cout << "Enter no. of sections in this Chapter: ";
        cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++) // sections

        {
            root->child[i]->child[j] = new Node;
            cout << "Enter section head: ";
            cin >> root->child[i]->child[j]->label;

            cout << "Enter no. of sub-sections in this section: ";
            cin >> root->child[i]->child[j]->ch_count;

            for (k = 0; k < root->child[i]->child[j]->ch_count; k++)
            {
                root->child[i]->child[j]->child[k] = new Node;
                cout << "Enter Sub-section head: ";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void Tree::displayTree(Node *r1)
{
    cout << "\nBook Hierarchy";
    cout << "\rBook Name: " << r1->label;
    int tchapters = r1->ch_count;

    for (int i = 0; i < tchapters; i++)
    {
        cout << "\rChapter " << i + 1 << ": " << root->child[i]->label;

        for (int j = 0; j < root->child[i]->ch_count; j++)
        {
            cout << "\rSection"
                 << ":" << root->child[i]->child[j]->label;

            for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
            {
                cout << "\rSub-section: "
                     << ": " << root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

int main()
{
    int choice;
    Tree t1;
    cout << "\n";
    cout << "Book Hierarchy" << endl;
    cout << "1.Create" << endl;
    cout << "2.Display" << endl;
    cout << "3.Quit" << endl;
    do
    {
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t1.createTree();
            break;
        case 2:
            t1.displayTree(root);
            break;
        case 3:
            cout << "Exit";
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (choice != 3);
}
