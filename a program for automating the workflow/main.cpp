#include "creating_account.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 0;
    const int size = 12;
    user User[size];

    size_t size_base = 5;
    product* Base = new product[size_base];

    const int size_cell = 5;
    const int size_product = 10;
    int** storage_cells;
    storage_cells = new int* [size_cell];    //ячейки размещённого товара
    for (int r = 0; r < size_cell; r++)
    {
        storage_cells[r] = new int[size_product];
    }
    const int size_cell_quantity = size_cell;
    const int size_product_quantity = size_product;
    int** storage_cells_quantity;
    storage_cells_quantity = new int* [size_cell_quantity];    //количество размещённого товара
    for (int h = 0; h < size_cell_quantity; h++)
    {
        storage_cells_quantity[h] = new int[size_product_quantity];
    }

    size_t size_selection = 10;
    int* arr_selection_artikul = new int[size_selection];    //артикул товара в отборе
    int* arr_selection_quantity = new int[size_selection];    //количество каждого товара в отборе

    zeroing_cells(storage_cells, size_cell, size_product, storage_cells_quantity);
    zeroing_articleand_quantity(Base, size);

    char press;
    bool create_acc = false;
    bool end_work = false;
    while (true)
    {
        if (end_work == true)
        {
            cout << "У тебя есть 5 минут что бы зайти обратно, сынок." << endl;
            break;
        }
        while (true)
        {
            end_work = false;
            create_acc = false;
            cout << "1.Войти в существующую учётную запись.\n2.Создать новую учётную запись.\n3.Закончить работу." << endl;
            cin >> press;
            switch (press)
            {
            case '1':
                clearing_console();
                if (account_intrusion(User, size) == true)
                {
                    create_acc = true;
                    clearing_console();
                }
                break;
            case '2':
                clearing_console();
                create_an_account(User, size);
                login_generation(User, size);
                password_generation(User, size, '1', 'z');
                clearing_console();
                break;
            case '3':
                end_work = true;
                break;
            }
            if (create_acc == true)
            {
                cout << "Добро пожаловать в работу." << endl;
                break;
            }
            if (end_work == true)
                break;
        }
        while (true)
        {
            if (end_work == true)
                break;
            while (true)
            {
                if (end_work == true)
                    break;
                clearing_console();
                cout << "К какой работе Вы хотите приступить?\n1.Приёмка.\n2.Размещение.\n3.Отбор\n4.Проверка.";
                cout << "\n5.Просмотреть информацию о товаре на приёмке.\n6.Просмотреть информацию о товаре в ячейках хранения.\n7.Выйти из учётной записи и окончить работу." << endl;
                cin >> press;
                if (press != '1' && press != '2' && press != '3' && press != '4' && press != '5' && press == '6' && press == '7')
                    cout << "Попробуйте выбрать ещё раз." << endl;
                if (press == '1' || press == '2' || press == '3' || press == '4' || press == '5' || press == '6' || press == '7')
                    break;
            }
            switch (press)
            {
            case '1':
                acceptance(Base, size_base, i);     //приёмка
                break;
            case '2':
                placement(storage_cells, storage_cells_quantity, Base, size_base, size_product, size_cell);      //размещение
                break;
            case '3':
                selection(storage_cells, storage_cells_quantity, arr_selection_artikul, arr_selection_quantity, size_product, size_cell, Base);     //отбор
                break;
            case '4':
                control(arr_selection_artikul, arr_selection_quantity, size_selection);      //проверка
                break;
            case '5':
                clearing_console();
                show_product_acceptance(Base, size_base);
                break;
            case '6':
                clearing_console();
                viewing_cells(storage_cells, size_cell, size_product, storage_cells_quantity);
                break;
            case '7':
                end_work = true;
                break;
            }
            if (end_work == true)
                break;
            while (true)
            {
                cout << "Выбрать другой вид работы?\n1.Да.\n2.Нет." << endl;
                cin >> press;
                if (press != '1' && press != '2')
                    cout << "Попробуйте выбрать ещё раз." << endl;
                if (press == '1' || press == '2')
                    break;
            }
            if (press == '1')
                cout << "Хороший выбор." << endl;
            if (press == '2')
            {
                clearing_console();
                cout << "С такими темпами Вы будете быстро уволены." << endl;
                break;
            }
        }
    }
    return 0;
}