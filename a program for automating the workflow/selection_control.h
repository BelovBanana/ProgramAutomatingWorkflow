#include "acceptance_placement.h"


//==============================================================================================================

void selection(int** storage_cells, int** storage_cells_quantity, int* arr_selection_artikul,    // ����� ������ �� ��������
    int* arr_selection_quantity, size_t size_product, size_t size_cell, product* Base)
{
    bool end = false;
    int cell = 0;
    int artikul = 0;
    int matches = 0;
    char press;
    int quantity_produkt = 0;
    int quantity = 0;
    int size = 0;
    viewing_cells(storage_cells, size_cell, size_product, storage_cells_quantity);
    while (true)
    {
        while (true)
        {
            matches = 0;
            cout << "������� ����� ������ ��� ������ ������ (�� 1 �� " << size_cell - 1 << ") : " << endl;
            cin >> cell;
            if (cell > size_product - 1 || cell <= 0)
                cout << "����������� ����� ����� ������, ���������� ��� ���" << endl;
            if (cell <= size_product - 1 && cell > 0)
                break;
        }
        while (true)
        {
            cout << "������� ������� ����������� ������:" << endl;
            cin >> artikul;
            for (int i = 0; i < size_product; i++)
            {
                if (artikul == storage_cells[cell][i])
                {
                    arr_selection_artikul[size] = artikul;
                    cout << "[" << arr_selection_artikul[size] << "]" << endl;
                    quantity = i;
                    matches++;
                }
            }
            if (matches == 1)
                break;
            if (matches == 0)
                cout << "���������� �� �������" << endl;
        }
        matches = 0;
        while (true)
        {
            cout << " Co " << quantity << endl;
            cout << "������� ���������� ����������� ������:" << endl;
            cin >> quantity_produkt;
           
        if (quantity_produkt <= storage_cells_quantity[cell][quantity] && quantity_produkt > 0)
        {
           arr_selection_quantity[size] = quantity_produkt;
           size++;
           matches++;
           break;
        }
           
        if (matches == 1)
            break;
        if (matches == 0)
            cout << "������� ������������ ����������. ���������� �����" << endl;
        }
        for (int j = 0; j < size_product; j++)
        {
            if (artikul == storage_cells[cell][j] && quantity_produkt == storage_cells_quantity[cell][j])
            {
                storage_cells[cell][j] = 0;
                storage_cells_quantity[cell][j] = 0;
            }
        }
        deleting_cell_files_articul();
        if (cell == 1)
        {
            ofstream storage_cells_file_1;
            storage_cells_file_1.open("Storage_cells_1.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells[1][j] != 0)
                    storage_cells_file_1 << storage_cells[1][j] << " ";
            }
            storage_cells_file_1.close();
        }
        if (cell == 2)
        {
            ofstream storage_cells_file_2;
            storage_cells_file_2.open("Storage_cells_2.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells[2][j] != 0)
                    storage_cells_file_2 << storage_cells[2][j] << " ";
            }
            storage_cells_file_2.close();
        }
        if (cell == 3)
        {
            ofstream storage_cells_file_3;
            storage_cells_file_3.open("Storage_cells_3.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells[3][j] != 0)
                    storage_cells_file_3 << storage_cells[3][j] << " ";
            }
            storage_cells_file_3.close();
        }
        if (cell == 4)
        {
            ofstream storage_cells_file_4;
            storage_cells_file_4.open("Storage_cells_4.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells[4][j] != 0)
                    storage_cells_file_4 << storage_cells[4][j] << " ";
            }
            storage_cells_file_4.close();
        }
        deleting_cell_files_quantity();
        if (cell == 1)
        {
            ofstream Storage_cells_quantity_file_1;
            Storage_cells_quantity_file_1.open("Storage_cells_quantity_1.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells_quantity[1][j] != 0)
                    Storage_cells_quantity_file_1 << storage_cells_quantity[1][j] << " ";
            }
            Storage_cells_quantity_file_1.close();
        }
        if (cell == 2)
        {
            ofstream Storage_cells_quantity_file_2;
            Storage_cells_quantity_file_2.open("Storage_cells_quantity_2.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells_quantity[2][j] != 0)
                    Storage_cells_quantity_file_2 << storage_cells_quantity[2][j] << " ";
            }
            Storage_cells_quantity_file_2.close();
        }
        if (cell == 3)
        {
            ofstream Storage_cells_quantity_file_3;
            Storage_cells_quantity_file_3.open("Storage_cells_quantity_3.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells_quantity[3][j] != 0)
                    Storage_cells_quantity_file_3 << storage_cells_quantity[3][j] << " ";
            }
            Storage_cells_quantity_file_3.close();
        }
        if (cell == 4)
        {
            ofstream Storage_cells_quantity_file_4;
            Storage_cells_quantity_file_4.open("Storage_cells_quantity_4.txt", ofstream::app);
            for (int j = 0; j < size_product; j++)
            {
                if (storage_cells_quantity[4][j] != 0)
                    Storage_cells_quantity_file_4 << storage_cells_quantity[4][j] << " ";
            }
            Storage_cells_quantity_file_4.close();
        }
        zeroing_cells(storage_cells, size_cell, size_product, storage_cells_quantity);
        filling_cells_with_data(storage_cells, size_product);
        filling_cells_with_data_quantity(storage_cells_quantity, size_product);
        viewing_cells(storage_cells, size_cell, size_product, storage_cells_quantity);
        while (true)
        {
            cout << "���������� ����� ������?\n 1.��.\n 2.���." << endl;
            cin >> press;
            if (press != '1' && press != '2')
                cout << "���������� ������� ��� ���." << endl;
            if (press == '1' || press == '2')
                break;
        }
        switch (press)
        {
        case '1':
            end = false;
            break;
        case '2':
            end = true;
            break;
        default:
            break;
        }
        if (end == true)
            break;
    }
}

//==============================================================================================================

void control(int* arr_selection_artikul, int* arr_selection_quantity, size_t size)     //�������� ������ ����� ���������
{
    bool end;
    int check_artikul = 0;
    int artikul = 0;
    int quantity_produkt = 0;
    int product = 0;
    char press;
    while (true)
    {
        product = 0;
        while (true)
        {
            cout << "������� ������� ������:" << endl;
            cin >> artikul;
            for (int i = 0; i < size; i++)
            {
                if (artikul == arr_selection_artikul[i])
                {
                    check_artikul++;
                    break;
                }
                product++;
            }
            if (check_artikul == 1)
            {
                cout << "����� � ����� ��������� ������������ � ��������." << endl;
                break;
            }
            if (check_artikul == 0)
                cout << "���������� �� ������� , ���������� ��� ���." << endl;
        }
        while (true)
        {
            cout << "������� ���������� ����������� ������ � ������ ���������:" << endl;
            cin >> quantity_produkt;
            if (quantity_produkt > arr_selection_quantity[product] && quantity_produkt <= 0)
                cout << "������� ���������� ����������� ����������� ���������� ������. �������������." << endl;
            if (quantity_produkt == arr_selection_quantity[product])
            {
                cout << "�� �����." << endl;
                break;
            }
        }
        while (true)
        {
            cout << "���������� �������� ������?\n1.��.\n2.���." << endl;
            cin >> press;
            if (press != '1' && press != '2')
                cout << "���������� ������� ��� ���." << endl;
            if (press == '1' || press == '2')
                break;
        }
        switch (press)
        {
        case '1':
            end = true;
            break;
        case '2':
            cout << "������� �� ������." << endl;
            end = false;
            break;
        }
        if (end == false)
        {
            break;
        }
    }
}



