#include "selection_control.h"



string login_generation(user* arr, size_t size)
{
    int storekeeper = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i].login = arr[i].name + arr[i].surname;
    }
    cout << "Ваш логин:" << endl;
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
        cout << "Придумайте и введите пароль:" << endl;
        cin >> arr[storekeeper].password;
        cout << "Введите пароль ещё раз:" << endl;
        cin >> check;
        if (arr[storekeeper].password == check)
        {
            cout << "Это верно! Запомните свой пароль." << endl;
            ofstream password_file;
            password_file.open("Password.txt", ofstream::app);
            password_file << arr[storekeeper].password << " ";
            password_file.close();
            break;
        }
        if (arr[storekeeper].password != check)
        {
            cout << "Пароль введен неправильно! Попробуйте снова." << endl;
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
        cout << "Введите Ваше имя (используйте латинские буквы) :" << endl;
        cin >> arr[storekeeper].name;
        cout << "Введите Вашу фамилию (используйте латинские буквы) :" << endl;
        cin >> arr[storekeeper].surname;
        cout << "Проверьте достоверность введенных данных." << "\n" << arr[storekeeper].name << "\n" << arr[storekeeper].surname << endl;
        while (true)
        {
            cout << "1.Всё верно\n2.Ввести ещё раз." << endl;
            cin >> press;
            if (press != '1' && press != '2')
                cout << "Введены некорректные данные. Ещё раз." << endl;
            if (press == '1' || press == '2')
                break;
        }
        switch (press)
        {
        case '1':
            cout << "Отлично, сейчас Вы увидите Ваш логин! Сохраните его." << endl;
            end = true;
            break;
        case '2':
            cout << "Ещё раз." << endl;
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
        cout << "Введите Ваш логин и пароль:" << endl << "Логин:" << endl;
        cin >> login;
        cout << "Пароль:" << endl;
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
            cout << "Логин или пароль введён неверно.\n1.Попробовать ещё раз.\n2.Назад." << endl;
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
