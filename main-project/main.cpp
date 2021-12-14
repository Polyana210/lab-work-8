#include <iostream>
#include "catalog.h"
#include "file_reader.h"
#include "constants.h"
#include"filter_reader.h"
using namespace std;

void out (catalog* prod){
    /********** вывод информации о товаре **********/
    cout << "Стоимость........: ";
    // вывод стоимости
    cout << prod->cost << '\n';
    //вывод количества
    cout << "Количество........: ";
    cout << prod->quan << '\n';
    cout << "Категория........: ";
    //вывод категории
    cout << prod->category << '\n';
    cout << "Название........: ";
    //вывод названия
    cout << prod->name << '\n';
    cout << '\n';
}

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
        cout << "***** Каталог товаров *****\n\n";
     /*   for (int i = 0; i < size; i++)
        {
            out(prod[i]);
        }*/
        bool (*check_function)(catalog*);


        cout << "Выберите фильтрацию  : ";

        int item;

        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:


            check_function = check_book_promtovary;
            cout << "*****   Результат фильрации 1    *****\n\n";
            break;
        case 2:
            check_function = check_book_cost;
            cout << "*****     Результат фильтрации 2    *****\n\n";
            break;
        default:
            throw " Нет такой фильтрации ";
        }
        int new_size;
        catalog** filtered = filter(prod, size, check_function, new_size);
        for (int i = 0; i < new_size; i++)
        {
            out(filtered[i]);
        }
        delete[] filtered;







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