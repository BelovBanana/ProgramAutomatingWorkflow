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
    storage_cells = new int* [size_cell];    //������ ������������ ������
    for (int r = 0; r < size_cell; r++)
    {
        storage_cells[r] = new int[size_product];
    }
    const int size_cell_quantity = size_cell;
    const int size_product_quantity = size_product;
    int** storage_cells_quantity;
    storage_cells_quantity = new int* [size_cell_quantity];    //���������� ������������ ������
    for (int h = 0; h < size_cell_quantity; h++)
    {
        storage_cells_quantity[h] = new int[size_product_quantity];
    }

    size_t size_selection = 10;
    int* arr_selection_artikul = new int[size_selection];    //������� ������ � ������
    int* arr_selection_quantity = new int[size_selection];    //���������� ������� ������ � ������

    zeroing_cells(storage_cells, size_cell, size_product, storage_cells_quantity);
    zeroing_articleand_quantity(Base, size);

    char press;
    bool create_acc = false;
    bool end_work = false;
    while (true)
    {
        if (end_work == true)
        {
            cout << "� ���� ���� 5 ����� ��� �� ����� �������, �����." << endl;
            break;
        }
        while (true)
        {
            end_work = false;
            create_acc = false;
            cout << "1.����� � ������������ ������� ������.\n2.������� ����� ������� ������.\n3.��������� ������." << endl;
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
                cout << "����� ���������� � ������." << endl;
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
                cout << "� ����� ������ �� ������ ����������?\n1.������.\n2.����������.\n3.�����\n4.��������.";
                cout << "\n5.����������� ���������� � ������ �� ������.\n6.����������� ���������� � ������ � ������� ��������.\n7.����� �� ������� ������ � �������� ������." << endl;
                cin >> press;
                if (press != '1' && press != '2' && press != '3' && press != '4' && press != '5' && press == '6' && press == '7')
                    cout << "���������� ������� ��� ���." << endl;
                if (press == '1' || press == '2' || press == '3' || press == '4' || press == '5' || press == '6' || press == '7')
                    break;
            }
            switch (press)
            {
            case '1':
                acceptance(Base, size_base, i);     //������
                break;
            case '2':
                placement(storage_cells, storage_cells_quantity, Base, size_base, size_product, size_cell);      //����������
                break;
            case '3':
                selection(storage_cells, storage_cells_quantity, arr_selection_artikul, arr_selection_quantity, size_product, size_cell, Base);     //�����
                break;
            case '4':
                control(arr_selection_artikul, arr_selection_quantity, size_selection);      //��������
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
                cout << "������� ������ ��� ������?\n1.��.\n2.���." << endl;
                cin >> press;
                if (press != '1' && press != '2')
                    cout << "���������� ������� ��� ���." << endl;
                if (press == '1' || press == '2')
                    break;
            }
            if (press == '1')
                cout << "������� �����." << endl;
            if (press == '2')
            {
                clearing_console();
                cout << "� ������ ������� �� ������ ������ �������." << endl;
                break;
            }
        }
    }
    return 0;
}