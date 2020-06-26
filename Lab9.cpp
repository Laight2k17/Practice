#include <iostream>

using namespace std;

void input_matr(int**& p, int n)
{
    int i, j;
    p = new int* [n];
    cout << "��������� �����: \n";
    for (i = 0; i < n; i++)
    {
        p[i] = new int[n];
        for (j = 0; j < n; j++)
        {
            cout << "�������[" << i << "][" << j << "] = ";
            cin >> p[i][j];
        }
    }
}

void output_matr(int** p, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
}

void delete_p(int** p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        delete[] p[i];
    }
    delete[] p;
}

int main()
{
    setlocale(LC_CTYPE, "");
    int n;
    cout << "������� ����������� �������: ";
    cin >> n;
    int** p = NULL;
    input_matr(p, n);
    cout << "��������� ������: \n";
    output_matr(p, n);
    //work(p, n);
    cout << "���������������� ������: \n";
    output_matr(p, n);
    delete_p(p, n);
}