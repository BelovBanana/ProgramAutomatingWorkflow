#include "selection_control.h"



string login_generation(user* arr, size_t size)
{
    int storekeeper = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i].login = arr[i].name + arr[i].surname;
    }
    cout << "��� �����:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].login;
    }
    ofstream login_file;
    login_file.open("Login.txt", ofstream::app);
    login_file << arr[storekeeper].login << " ";
    login_file.close();
    cout << "\n" << endl;
    storekeeper++;
    return arr[storekeeper].login;
}

string password_generation(user* arr, size_t size, char from, char to)
{
    string check;
    int storekeeper = 0;
    while (true)
    {
        cout << "���������� � ������� ������:" << endl;
        cin >> arr[storekeeper].password;
        cout << "������� ������ ��� ���:" << endl;
        cin >> check;
        if (arr[storekeeper].password == check)
        {
            cout << "��� �����! ��������� ���� ������." << endl;
            ofstream password_file;
            password_file.open("Password.txt", ofstream::app);
            password_file << arr[storekeeper].password << " ";
            password_file.close();
            break;
        }
        if (arr[storekeeper].password != check)
        {
            cout << "������ ������ �����������! ���������� �����." << endl;
        }
    }
    storekeeper++;

    return arr[storekeeper].password;
}

void create_an_account(user* arr, size_t size)
{
    bool end = false;
    char press;
    int storekeeper = 0;
    while (true)
    {
        cout << "������� ���� ��� (����������� ��������� �����) :" << endl;
        cin >> arr[storekeeper].name;
        cout << "������� ���� ������� (����������� ��������� �����) :" << endl;
        cin >> arr[storekeeper].surname;
        cout << "��������� ������������� ��������� ������." << "\n" << arr[storekeeper].name << "\n" << arr[storekeeper].surname << endl;
        while (true)
        {
            cout << "1.�� �����\n2.������ ��� ���." << endl;
            cin >> press;
            if (press != '1' && press != '2')
                cout << "������� ������������ ������. ��� ���." << endl;
            if (press == '1' || press == '2')
                break;
        }
        switch (press)
        {
        case '1':
            cout << "�������, ������ �� ������� ��� �����! ��������� ���." << endl;
            end = true;
            break;
        case '2':
            cout << "��� ���." << endl;
            end = false;
            break;
        }
        if (end == true)
        {
            if (storekeeper <= size)
            {
                storekeeper++;
            }
            break;
        }
    }
}

bool account_intrusion(user* arr, size_t size)
{
    bool create = false;
    bool end_create = false;
    string login, password;
    int storekeeper = 0;
    char press;

    ifstream password_file;
    password_file.open("Password.txt");
    for (int j = 0; j < size; j++)
    {
        password_file >> arr[j].password;
    }
    password_file.close();
    ifstream login_file;
    login_file.open("Login.txt");
    for (int j = 0; j < size; j++)
    {
        login_file >> arr[j].login;
    }
    login_file.close();

    while (true)
    {
        cout << "������� ��� ����� � ������:" << endl << "�����:" << endl;
        cin >> login;
        cout << "������:" << endl;
        cin >> password;
        for (; storekeeper < size; storekeeper++)
        {
            if (arr[storekeeper].login == login && arr[storekeeper].password == password)
            {
                create = true;
                end_create = true;
                break;
            }
            if (arr[storekeeper].login != login || arr[storekeeper].password != password)
            {
                end_create = false;
                break;
            }
        }
        if (end_create == false)
        {
            cout << "����� ��� ������ ����� �������.\n1.����������� ��� ���.\n2.�����." << endl;
            cin >> press;
            switch (press)
            {
            case '1':
                break;
            case '2':
                end_create = true;
                break;
            }
        }
        if (end_create == true)
        {
            break;
        }
    }
    return create;
}
