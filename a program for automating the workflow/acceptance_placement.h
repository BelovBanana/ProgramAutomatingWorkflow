#include "functions.h"

//==============================================================================================================

int acceptance(product* Base, size_t size_base, int i)   //������������� ������ ������
{
    bool end = true;
    char press;
    int artikul = 0;
    int quantity = 0;
    clearing_console();
    while (true)
    {
        while (true)
        {
            artikul = 0;
            if (size_acceptance(Base, size_base) == size_base)
            {
                cout << "��������� ������������ ����� ���������� ������ (" << size_base << ")." << endl;
                break;
            }
            cout << "������� ������� ������ (�� 7 ����):" << endl;
            cin >> artikul;
            if (artikul < 9999999 && artikul > 0)
            {
                Base[i].artikul = artikul;
                ofstream artikul_file;
                artikul_file.open("Artikul.txt", ofstream::app);
                artikul_file << Base[i].artikul << " ";
                artikul_file.close();
                break;
            }
            if (artikul > 9999999 || artikul <= 0)
            {
                cout << "����� ������������ �������. ���������� �����" << endl;
            }
        }
        while (true)
        {
            if (size_acceptance(Base, size_base) == size_base)
            {
                break;
            }
            cout << "������� ���������� ������:" << endl;
            cin >> quantity;
            if (quantity <= 0)
                cout << "������� ������������ ��������. ���������� ��� ���." << endl;
            if (quantity > 0)
            {

                Base[i].quantity = quantity;
                ofstream quantity_file;
                quantity_file.open("Quantity.txt", ofstream::app);
                quantity_file << Base[i].quantity << " ";
                quantity_file.close();

                break;
            }
        }
        if (continuation(end, i) == false)
        {
            break;
        }
    }

    return i, Base[i].artikul, Base[i].quantity;
}

//========================================================================================================================

void placement(int** storage_cells, int** storage_cells_quantity, product* Base, size_t size_base, size_t size_product, size_t size_cell)    //������������� ���������� ������
{
    bool end = false;
    int cell = 0;
    int artikul = 0;
    int produkt = 0;
    int quantity = 0;
    int quantity_produkt = 0;
    char press;
    short int check = 0;
    int i = 0;
    clearing_console();
    cout << "���������� ����� �� ������ ������ � ������ ��������." << endl;
    while (true)
    {
        show_product_acceptance(Base, size_base);
        if (continuation(end, i) == false)
        {
            break;
        }
        while (true)
        {
            cout << "������� ����� ������ ��� ���������� ������ (�� 1 �� " << size_cell - 1 << ") : " << endl;
            cin >> cell;
            if (cell > size_cell - 1 || cell <= 0)
                cout << "����������� ����� ����� ������, ���������� ��� ���" << endl;
            if (cell <= size_cell - 1 && cell > 0)
                break;
        }
        while (true)
        {
            quantity_produkt = 0;
            produkt = 0;
            cout << "������� ������� ������������ ������:" << endl;
            cin >> artikul;
            for (int j = 0; j < size_base; j++)
            {
                if (artikul == Base[j].artikul)
                {
                    produkt++;
                    break;
                }
                quantity_produkt++;
            }
            if (produkt == 0)
                cout << "������� ������ �� ������ �� ������. ��������� ������." << endl;
            if (produkt == 1)
                break;
        }
        while (true)
        {
            cout << "������� ���������� ������������ ������:" << endl;
            cin >> quantity;
            if (quantity > Base[quantity_produkt].quantity || quantity <= 0)
                cout << "������� ���������� ������ , ��� ���� �� ������ , ������ ��� 0. ��������� ������." << endl;
            if (quantity <= Base[quantity_produkt].quantity && quantity > 0)
                break;
        }
        cout << "����� ������� ��������!" << endl;

        storage_cells[cell][i] = artikul;
        writing_data_cells(cell, i ,storage_cells);

        storage_cells_quantity[cell][i] = quantity;
        writing_data_cells_quantity(cell,i, storage_cells_quantity);

        Base[quantity_produkt].quantity = Base[quantity_produkt].quantity - quantity;
        if (Base[quantity_produkt].quantity == 0)
        {
            Base[quantity_produkt].artikul = 0;
        }
        remove("Artikul.txt");
        ofstream artikul_file;
        artikul_file.open("Artikul.txt", ofstream::app);
        for (int j = 0; j < size_base; j++)
        {
            if (Base[j].artikul != 0 && Base[j].artikul > 0)
                artikul_file << Base[j].artikul << " ";
        }
        artikul_file.close();

        remove("Quantity.txt");
        ofstream quantity_file;
        quantity_file.open("Quantity.txt", ofstream::app);
        for (int j = 0; j < size_base; j++)
        {
            if (Base[j].quantity != 0 && Base[j].quantity > 0)
                quantity_file << Base[j].quantity << " ";
        }
        quantity_file.close();
        if (continuation(end, i) == false)
        {
            break;
        }
    }
}

