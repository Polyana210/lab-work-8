#include <iostream>
#include "catalog.h"
#include "file_reader.h"
#include "constants.h"
#include"filter_reader.h"
using namespace std;

void out (catalog* prod){
    /********** ����� ���������� � ������ **********/
    cout << "���������........: ";
    // ����� ���������
    cout << prod->cost << '\n';
    //����� ����������
    cout << "����������........: ";
    cout << prod->quan << '\n';
    cout << "���������........: ";
    //����� ���������
    cout << prod->category << '\n';
    cout << "��������........: ";
    //����� ��������
    cout << prod->name << '\n';
    cout << '\n';
}

int main()
{

    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �8. GIT\n";
    cout << "������� �10. ������� �������\n";
    cout << "�����: ������ ������\n\n";
    catalog* prod[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt",prod, size);
        cout << "***** ������� ������� *****\n\n";
     /*   for (int i = 0; i < size; i++)
        {
            out(prod[i]);
        }*/
        bool (*check_function)(catalog*);


        cout << "�������� ����������  : ";

        int item;

        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:


            check_function = check_book_promtovary;
            cout << "*****   ��������� ��������� 1    *****\n\n";
            break;
        case 2:
            check_function = check_book_cost;
            cout << "*****     ��������� ���������� 2    *****\n\n";
            break;
        default:
            throw " ��� ����� ���������� ";
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