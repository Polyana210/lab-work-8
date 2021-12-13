#include <iostream>

using namespace std;

#include "catalog.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №10. Каталог товаров\n";
    cout << "Автор: Щетина Полина\n\n";
    catalog* prod[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt",prod, size);
        for (int i = 0; i < size; i++)
        {
            cout << prod[i]->cost<< '\n';
            cout << prod[i]->quan << '\n';
            cout << prod[i]->category << '\n';
            cout << prod[i]->name << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete prod[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}