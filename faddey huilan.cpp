#include <iostream>
#include <Windows.h>
#include <fstream>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;
/*
Задача "Военкомат"
  Есть структура "Soldier".Поля структуры
  - ФИО(полностью)
  - Возраст
  - Рост
  - Вес
  - Гражданская профессия
  - Род войск
Реализовать функции :
*Важно : Поля ФИО заполняются полностью и в файле хранятся полностью
* но при выводе на экран сокращаются до фамилии и инициалов
  - Заполнения с клавиатуры
  - Редактирование
  - Вывод на экран
  - Запись в файл
- Заполнение из файла
  - Поиск по фамилии
*/
struct Soldier
{
  char FIO[100];
  int age;
  int Rost;
  int Ves;
  char CivProf[100];
  char ToA[100];
};
Soldier* Add(Soldier* group, int& size)
{
  if (size == 0)
    group = new Soldier[size + 1];
  else
  {
    Soldier* temp = new Soldier[size + 1];
    for (int i = 0; i < size; i++)
      temp[i] = group[i];
    delete[] group;
    group = temp;
  }
  cin.ignore();
  cout << "Enter FIO of Soldier\n"; cin.getline(group[size].FIO, 100);
  cout << "Enter Age of Soldier\n"; cin >> group[size].age;
  cout << "Enter Rost of Soldier\n"; cin >> group[size].Rost;
  cout << "Enter Ves of Soldier\n"; cin >> group[size].Ves;
  cin.ignore();
  cout << "Enter Civil profession\n"; cin.getline(group[size].CivProf, 100);
  cout << "Enter type of Army\n"; cin.getline(group[size].ToA, 100);
  size++;
  return group;
}
void Show(Soldier* group, int& size)
{
  cout << "#\tFIO\tAge\tRost\tVes\tCivil Prof\tType of Army\n";
  for (int i = 0; i < size; i++)
  {
    cout << i + 1 << "\t" << group[i].FIO << "\t  " << group[i].age << "\t" << group[i].Rost << "\t" << group[i].Ves << "\t" << group[i].CivProf << "\t" << group[i].ToA << "\n";
  }
}
void Search(Soldier* group, int& size)
{
  char* pch1;
  char surname[100];
  cout << "Enter surname\n";
  cin.ignore();
  cin.getline(surname, 100);
  for (int i = 0; i < size; i++)
  {
    pch1 = strtok(group[i].FIO, " ");
    if (pch1 = surname)
    {
      cout << i + 1 << "\t" << group[i].FIO << "\t  " << group[i].age << "\t" << group[i].Rost << "\t" << group[i].Ves << "\t" << group[i].CivProf << "\t" << group[i].ToA << "\n";
    }
  }
}
void Fail(Soldier* group, int& size)
{
  ofstream fin("text.txt");
  for (int i = 0; i < size; i++)
  {
    fin << i + 1 << "\t" << group[i].FIO << "\t  " << group[i].age << "\t" << group[i].Rost << "\t" << group[i].Ves << "\t" << group[i].CivProf << "\t" << group[i].ToA << "\n";
  }
  fin.close();
}
Soldier* Edit(Soldier* group, int& size)
{
  int index;
  cout << "Enter index\n";
  cin >> index;
  Soldier* temp = new Soldier[size];
  for (int i = 0; i < size; i++)
  {
    if (i == index)
    {
      cin.ignore();
      cout << "Enter FIO of Soldier\n"; cin.getline(temp[i].FIO, 100);
      cout << "Enter Age of Soldier\n"; cin >> temp[i].age;
      cout << "Enter Rost of Soldier\n"; cin >>temp[i].Rost;
      cout << "Enter Ves of Soldier\n"; cin >> temp[i].Ves;
      cin.ignore();
      cout << "Enter Civil profession\n"; cin.getline(temp[i].CivProf, 100);
      cout << "Enter type of Army\n"; cin.getline(temp[i].ToA, 100);
    }
    temp[i] = group[i];
  }
  delete[] group;
  group = temp;
  return group;
}
int main()
{
  srand(time(NULL));
  Soldier* group = nullptr;
  int size = 0;
  bool job = 1;
  while (job)
  {
    int choice;
    cout << "Enter choice:\n1 - Add\n2 - Show\n3 - Search\n4 - Edit\n5 - Fail\n0 - Exit\n";
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
      Search(group, size);
      break;
    case 4:
      group = Edit(group, size);
      break;
    case 5:
      Fail(group, size);
      break;
    case 0:
      job = 0;
      break;
    }
  }

  return 0;
}