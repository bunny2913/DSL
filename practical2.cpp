#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class student
{
    int admno;
    char div;
    char name[50];
    char addr[50];

public:
    void setData()
    {
        cout << "Enter Roll NO : ";
        cin >> admno;
        cout << "Enter name: ";
        cin >> name;
        cout<<"Enter division of the student: ";
        cin>>div;
        cout << "Enter the address of the student: ";
        cin >> addr;
    }

    void showData()
    {
        cout << "\n*Student Roll No  : " << admno;
        cout << "\n*Student Name : " << name;
        cout << "\n*Division: " << div;
        cout << "\n*Address: " << addr<<endl;
    }

    int retAdmno()
    {
        return admno;
    }
};

void write_record()
{
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    student obj;
    obj.setData();
    outFile.write((char *)&obj, sizeof(obj));
    outFile.close();
}

void display()
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    student obj;
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        obj.showData();
    }
    inFile.close();
}

int search(int n)
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    int flag = 0;
    student obj;

    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retAdmno() == n)
        {
            obj.showData();
            flag = 1;
            break;
        }
    }
    inFile.close();
    return flag;
}

void delete_record(int n)
{
    student obj;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);

    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retAdmno() != n)
        {
            outFile.write((char *)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

int main()
{
    int ch, ret, ret1;
    do
    {
        cout << "\n*******************File operations************************** \n1.write\n2.display\n3.search\n4.delete";
        cout << "\n\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {

        case 1:
            cout << "Enter number of records: ";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
                write_record();
            break;
        case 2:

            cout << "\nList of records";
            display();
            break;
        case 3:
            cout << "Enter Student Roll No : ";
            int s;
            cin >> s;
            ret = search(s);
            if (ret == 0)
            {
                cout << "\nRecord Not Found";
            }
            break;
        case 4:
            cout << "Enter no to be deleted: ";
            int d;
            cin >> d;
            ret1 = search(d);
            if (ret1 == 0)
            {
                cout << "\nRecord Not Found";
            }
            else
            {
                delete_record(d);
                cout << "\nRecord Deleted";
            }
            break;
        case 5:
            return 0;
        }
    } while (ch != 5);
}
