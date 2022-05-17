#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class employee
{
    int eid;
    int salary;
    char name[50];
    char desg[50];

public:
    void setData()
    {
        cout << "Enter employee ID : ";
        cin >> eid;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter designation: ";
        cin >> desg;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void showData()
    {
        cout << "\nEmployee ID: " << eid;
        cout << "\nEmployee name : " << name;
        cout << "\nDesignation: " << desg;
        cout << "\nSalary: " << salary << endl;
    }

    int reteID()
    {
        return eid;
    }
};

void write_record()
{
    ofstream outFile;
    outFile.open("employee.dat", ios::binary | ios::app);
    employee obj;
    obj.setData();
    outFile.write((char *)&obj, sizeof(obj));
    outFile.close();
}

void display()
{
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);
    employee obj;
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        obj.showData();
    }
    inFile.close();
}

int search(int n)
{
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);
    int flag = 0;
    employee obj;

    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.reteID() == n)
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
    employee obj;
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);

    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.reteID() != n)
        {
            outFile.write((char *)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("employee.dat");
    rename("temp.dat", "student.dat");
}

int main()
{
    int ch, ret, ret1;
    do
    {
        cout << "\nFile operations\n1.write\n2.display\n3.search\n4.delete";
        cout << "\nEnter your choice: ";
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
            cout << "Enter employee id: ";
            int s;
            cin >> s;
            ret = search(s);
            if (ret == 0)
            {
                cout << "\nEmployee does not exist!";
            }
            break;
        case 4:
            cout << "Enter employee to be deleted: ";
            int d;
            cin >> d;
            ret1 = search(d);
            if (ret1 == 0)
            {
                cout << "\nEmployee Not Found";
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
