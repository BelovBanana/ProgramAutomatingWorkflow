#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct product    //���� ������ ������� �� ������
{
    int artikul;
    int quantity;
};

struct user
{
    string name;
    string surname;
    string login;
    string password;
};

int size_storage_cells(int cell, int** storage_cells, size_t size_product, int** storage_cells_quantity);

//==============================================================================================================

void zeroing_cells(int** arr, size_t row, size_t col, int** arr_quantity)      // ��������� �����
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr_quantity[i][j] = 0;
        }
    }
}

//==============================================================================================================

void  filling_cells_with_data_quantity(int** storage_cells_quantity, size_t size_product)     //������ ���������� ���������� ������ � ������  
{
    ifstream Storage_cells_quantity_file_1;
    Storage_cells_quantity_file_1.open("Storage_cells_quantity_1.txt");
    for (int i = 0; i < size_product; i++)
    {
        Storage_cells_quantity_file_1 >> storage_cells_quantity[1][i];
    }
    Storage_cells_quantity_file_1.close();

    ifstream Storage_cells_quantity_file_2;
    Storage_cells_quantity_file_2.open("Storage_cells_quantity_2.txt");
    for (int i = 0; i < size_product; i++)
    {
        Storage_cells_quantity_file_2 >> storage_cells_quantity[2][i];
    }
    Storage_cells_quantity_file_2.close();

    ifstream Storage_cells_quantity_file_3;
    Storage_cells_quantity_file_3.open("Storage_cells_quantity_3.txt");
    for (int i = 0; i < size_product; i++)
    {
        Storage_cells_quantity_file_3 >> storage_cells_quantity[3][i];
    }
    Storage_cells_quantity_file_3.close();

    ifstream Storage_cells_quantity_file_4;
    Storage_cells_quantity_file_4.open("Storage_cells_quantity_4.txt");
    for (int i = 0; i < size_product; i++)
    {
        Storage_cells_quantity_file_4 >> storage_cells_quantity[4][i];
    }
    Storage_cells_quantity_file_4.close();
}

//==============================================================================================================

void filling_cells_with_data(int** storage_cells, size_t size_product)    // ������ ���������� (�������) � ������
{
    ifstream storage_cells_file_1;
    storage_cells_file_1.open("Storage_cells_1.txt");
    for (int i = 0; i < size_product; i++)
    {
        storage_cells_file_1 >> storage_cells[1][i];
    }
    storage_cells_file_1.close();

    ifstream storage_cells_file_2;
    storage_cells_file_2.open("Storage_cells_2.txt");
    for (int i = 0; i < size_product; i++)
    {
        storage_cells_file_2 >> storage_cells[2][i];
    }
    storage_cells_file_2.close();

    ifstream storage_cells_file_3;
    storage_cells_file_3.open("Storage_cells_3.txt");
    for (int i = 0; i < size_product; i++)
    {
        storage_cells_file_3 >> storage_cells[3][i];
    }
    storage_cells_file_3.close();

    ifstream storage_cells_file_4;
    storage_cells_file_4.open("Storage_cells_4.txt");
    for (int i = 0; i < size_product; i++)
    {
        storage_cells_file_4 >> storage_cells[4][i];
    }
    storage_cells_file_4.close();
}

//==============================================================================================================

void deleting_cell_files_articul()    //�������� ������ (������)
{
    remove("Storage_cells_1.txt");
    remove("Storage_cells_2.txt");
    remove("Storage_cells_3.txt");
    remove("Storage_cells_4.txt");
    
}

//==============================================================================================================

void deleting_cell_files_quantity()
{
    remove("Storage_cells_quantity_1.txt");
    remove("Storage_cells_quantity_2.txt");
    remove("Storage_cells_quantity_3.txt");
    remove("Storage_cells_quantity_4.txt");
}

//==============================================================================================================

int viewing_cells(int** storage_cells, size_t size_cell, size_t size_product, int** storage_cells_quantity)    // ���������� � ������
{
    char press;
    bool end = false;
    int cell = 0;

    while (true)
    {
        zeroing_cells(storage_cells, size_cell, size_product, storage_cells_quantity);
        filling_cells_with_data(storage_cells, size_product);
        filling_cells_with_data_quantity(storage_cells_quantity, size_product);
        while (true)
        {
            cout << "������� ����� ������ ��� ��������� ����������� � ��� ������ (�� 1 �� " << size_cell - 1 << "):" << endl;
            cin >> cell;
            if (cell > size_cell - 1 || cell <= 0)
                cout << "����������� ����� ����� ������, ���������� ��� ���" << endl;
            if (cell <= size_cell - 1 && cell > 0)
                break;
        }
        if (size_storage_cells(cell, storage_cells,size_product,storage_cells_quantity) != 0)
        {
            cout << "��� ����� � ������ " << cell << " :" << endl;
            for (int i = 0; i < size_product + 1; i++)
            {
                if (storage_cells[cell][i] > 0)
                {
                    cout << storage_cells[cell][i] << " | ";
                }
            }
            cout << "\n���������� ������� ������ � ������ " << cell << " :" << endl;
            for (int i = 0; i < size_product + 1; i++)
            {
                if (storage_cells_quantity[cell][i] > 0)
                {
                    cout << storage_cells_quantity[cell][i] << " | ";
                }
            }
            cout << endl;
        }
        if (size_storage_cells(cell ,storage_cells, size_product, storage_cells_quantity) == 0)
        {
            cout << "����� � ������ �����������." << endl;
        }
        while (true)
        {
            cout << "����������� ���?\n1.��.\n2.���." << endl;
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
            end = false;
            break;
        }
        if (end == false)
            break;
    }
    return storage_cells[cell][size_product], storage_cells_quantity[cell][size_product];
}

//==============================================================================================================


int zeroing_articleand_quantity(product* Base, size_t size_base)    //��������� ���������� �� �������� � ���������� ������ ������������ � ����
{
    for (int i = 0; i < size_base; i++)
    {
        Base[i].artikul = 0;
        Base[i].quantity = 0;
    }
    return Base[size_base].artikul, Base[size_base].quantity;
}
//========================================================================================================================

int show_product_acceptance(product* Base, size_t size_base)    //�������� ���������� � ������ �� ������
{
    char press;
    int info = 0;

    zeroing_articleand_quantity(Base, size_base);
    ifstream artikul_file;
    artikul_file.open("Artikul.txt");
    for (int j = 0; j < size_base; j++)
    {
        artikul_file >> Base[j].artikul;
    }
    artikul_file.close();
    ifstream quantity_file;
    quantity_file.open("Quantity.txt");
    for (int j = 0; j < size_base; j++)
    {
        quantity_file >> Base[j].quantity;
    }
    quantity_file.close();

    while (true)
    {
        cout << "����������� ���������� � ������ �� ������?\n1.��.\n2.���." << endl;
        cin >> press;
        if (press != '1' && press != '2')
            cout << "���������� ������� ��� ���." << endl;
        if (press == '1' || press == '2')
            break;
    }
    switch (press)
    {
    case '1':
        for (int i = 0; i < size_base + 1; i++)
        {
            if (Base[i].artikul > 0 && Base[i].quantity > 0)
            {
                cout << "[" << i << "]" << "�������: " << Base[i].artikul << "\n���������� ������: " << Base[i].quantity << endl << endl;
                info++;
            }
        }
        break;
    case '2':
        break;
    }
    if (info == 0)
    {
        cout << "�� ������ ����������� �����." << endl;
    }
    return Base[size_base].artikul, Base[size_base].quantity;
}

//========================================================================================================================

int size_storage_cells(int cell, int** storage_cells,size_t size_product, int** storage_cells_quantity)
{
    int show_product_acceptance_number = 0;
    for (int k = 0; k < size_product; k++)
    {
        if (storage_cells[cell][k] != 0 && storage_cells_quantity[cell][k] != 0)
            show_product_acceptance_number++;
    }
    return show_product_acceptance_number;
}

//========================================================================================================================

int size_acceptance(product* Base, size_t size_base)     //������ ���������� �������
{
    int show_product_acceptance_number = 0;
    for (int k = 0; k < size_base; k++)
    {
        if (Base[k].artikul > 0 && Base[k].quantity > 0)
            show_product_acceptance_number++;
    }
    return show_product_acceptance_number;
}



//========================================================================================================================

void writing_data_cells(int cell,int i, int** storage_cells)     //������ � ��������� ���� ������ �� �����
{
    if (cell == 1)
    {
        ofstream storage_cells_file_1;
        storage_cells_file_1.open("Storage_cells_1.txt", ofstream::app);
        storage_cells_file_1 << storage_cells[1][i] << " ";
        storage_cells_file_1.close();
    }
    if (cell == 2)
    {
        ofstream storage_cells_file_2;
        storage_cells_file_2.open("Storage_cells_2.txt", ofstream::app);
        storage_cells_file_2 << storage_cells[2][i] << " ";
        storage_cells_file_2.close();
    }
    if (cell == 3)
    {
        ofstream storage_cells_file_3;
        storage_cells_file_3.open("Storage_cells_3.txt", ofstream::app);
        storage_cells_file_3 << storage_cells[3][i] << " ";
        storage_cells_file_3.close();
    }
    if (cell == 4)
    {
        ofstream storage_cells_file_4;
        storage_cells_file_4.open("Storage_cells_4.txt", ofstream::app);
        storage_cells_file_4 << storage_cells[4][i] << " ";
        storage_cells_file_4.close();
    }
      
}

//==============================================================================================================

void writing_data_cells_quantity(int cell, int i, int** storage_cells_quantity)
{
    if (cell == 1)
    {
        ofstream Storage_cells_quantity_file_1;
        Storage_cells_quantity_file_1.open("Storage_cells_quantity_1.txt", ofstream::app);
        Storage_cells_quantity_file_1 << storage_cells_quantity[1][i] << " ";
        Storage_cells_quantity_file_1.close();
    }
    if (cell == 2)
    {
        ofstream Storage_cells_quantity_file_2;
        Storage_cells_quantity_file_2.open("Storage_cells_quantity_2.txt", ofstream::app);
        Storage_cells_quantity_file_2 << storage_cells_quantity[2][i] << " ";
        Storage_cells_quantity_file_2.close();
    }
    if (cell == 3)
    {
        ofstream Storage_cells_quantity_file_3;
        Storage_cells_quantity_file_3.open("Storage_cells_quantity_3.txt", ofstream::app);
        Storage_cells_quantity_file_3 << storage_cells_quantity[3][i] << " ";
        Storage_cells_quantity_file_3.close();
    }
    if (cell == 4)
    {
        ofstream Storage_cells_quantity_file_4;
        Storage_cells_quantity_file_4.open("Storage_cells_quantity_4.txt", ofstream::app);
        Storage_cells_quantity_file_4 << storage_cells_quantity[4][i] << " ";
        Storage_cells_quantity_file_4.close();
    }
}

//==============================================================================================================

void clearing_console()    //������� �������
{
    cout << "\033c";
}

//==============================================================================================================

bool continuation(bool end, int i)     // ����������� 
{
    char press;
    while (true)
    {
        cout << "����������?\n1.��.\n2.���." << endl;
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
        i++;
        break;
    case '2':
        cout << "������� �� ������." << endl;
        end = false;
        break;
    }
    return end;
}