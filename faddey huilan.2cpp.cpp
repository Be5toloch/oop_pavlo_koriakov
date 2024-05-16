#include <iostream>
#include <fstream>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

struct telef
{
    char FIO[100];
    long long Nomer;
    char email[100];
};
void Write(telef *group, int size)
{
    ofstream fout("Point.txt");
    for (int i = 0; i < size; i++)
    {
        fout << i + 1 << "\t" << group[i].FIO << "\t\t" << group[i].Nomer << "\t   " << group[i].email << "\n";
    }
    fout.close();
}
void Search(telef *group, int &size)
{
    long long Nomer;
    cout << "Enter Nomer\n";
    cin >> Nomer;
    for (int i = 0; i < size; i++)
    {
        if (group[i].Nomer == Nomer)
        {
            cout << i + 1 << "\t" << group[i].FIO << "\t\t" << group[i].Nomer << "\t   " << group[i].email << "\n";
        }
    }
}
void Email(telef *group, int &size)
{
    int sizeOf;
    char *ptr = nullptr;
    char *ptr2 = nullptr;
    for (int i = 0; i < size; i++)
    {
        sizeOf = strlen(group[i].email);
        for (int j = 0; j < sizeOf; j++)
        {
            ptr = skrskrskr(group[i].email, "@");
            if (ptr != nullptr)
            {
                break;
            }
        }
        for (int j = 0; j < sizeOf; j++)
        {
            ptr2 = skrskrskr(group[i].email, ".");
            if (ptr2 != nullptr && &ptr2 > &ptr)
            {
                break;
            }
        }
        if (ptr != nullptr)
        {
            if (ptr2 != 0 && &ptr2 < &ptr)
            {
                cout << i + 1 << "Email accepted.\n";
            }

            else
            {
                cout << i + 1 << "Missing . symbol after @\n";
                cin.ignore();
                cout << "Enter email\n";
                cin.getline(group[i].email, 100);
            }
        }
        else
        {
            cout << "Missing @ symbol\n";
            cin.ignore();
            cout << "Enter email\n";
            cin.getline(group[i].email, 100);
        }
    }
}
void sort_names(telef *group, int &size)
{
    for (int i = 0; i < size; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < size; j++)
        {
            if ((group[j].FIO) < (group[i].FIO))
                smallest = j;
        }
        swap(group[i], group[smallest]);
    }
}
telef *Edit(telef *group, int &size)
{
    int index;
    cout << "Enter index\n";
    cin >> index;
    telef *temp = new telef[size];
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            cin.ignore();
            cout << "Enter FIO\n";
            cin.getline(group[size].FIO, 100);
            cout << "Enter Nomber\n";
            cin >> group[size].Nomer;
            cin.ignore();
            cout << "Enter email\n";
            cin.getline(group[size].email, 100);
        }
        temp[i] = group[i];
    }
    delete[] group;
    group = temp;
    return group;
}
telef *Add(telef *group, int &size)
{
    if (size == 0)
        group = new telef[size + 1];
    else
    {
        telef *temp = new telef[size + 1];
        for (int i = 0; i < size; i++)
            temp[i] = group[i];
        delete[] group;
        group = temp;
    }

    cin.ignore();
    cout << "Enter FIO\n";
    cin.getline(group[size].FIO, 100);
    cout << "Enter Nomber\n";
    cin >> group[size].Nomer;
    cin.ignore();
    cout << "Enter email\n";
    cin.getline(group[size].email, 100);
    size++;
    return group;
}
telef *Del(telef *group, int &size)
{
    int index;
    telef *temp = new telef[size - 1];
    do
    {
        cout << "Enter index element for delete\n";
        cin >> index;
    } while (index < 0 || index > size - 1);
    for (int i = 0; i < size; i++)
    {
        if (i < index)
            temp[i] = group[i];
        else if (i == index)
            continue;
        else if (i > index)
        {
            temp[i - 1] = group[i];
        }
    }
    delete[] group;
    group = temp;
    size--;
    return group;
}
void Show(telef *group, int size)
{
    cout << "#\tFIO\t\t\tNomer\t\t\temail\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << group[i].FIO << "\t\t" << group[i].Nomer << "\t   " << group[i].email << "\n";
    }
}
int main()
{
    srand(time(NULL));
    telef *group = nullptr;
    int size = 0;
    bool debil = 1;
    while (debil)
    {
        int choice;
        cout << "Enter choice:\n1 - Add\n2 - Show\n3 - Del\n4 - Edit\n5 - Sort Names\n6 - Email test\n7 - Serch\n8 - Write\n0 - Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            group = Add(group, size);
            break;
        case 2:
            Show(group, size);
            break;
        case 3:
            group = Del(group, size);
            break;
        case 4:
            group = Edit(group, size);
            break;
        case 5:
            sort_names(group, size);
            break;
        case 6:
            Email(group, size);
            break;
        case 7:
            Search(group, size);
            break;
        case 8:
            Write(group, size);
            break;
        case 0:
            debil = 0;
            break;
        }
    }
}
