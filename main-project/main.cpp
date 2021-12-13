#include <iostream>

using namespace std;

#include "catalog.h"
#include "file_reader.h"
#include "constants.h"

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
        for (int i = 0; i < size; i++)
        { /********** ����� ���������� � ������ **********/
            cout << "���������........: ";
            // ����� ���������
            cout << prod[i]->cost<< '\n';
            //����� ����������
            cout << "����������........: ";
            cout << prod[i]->quan << '\n';
            cout << "���������........: ";
            //����� ���������
            cout << prod[i]->category << '\n';
            cout << "��������........: ";
            //����� ��������
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