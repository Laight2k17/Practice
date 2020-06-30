/*
-----------------------------------------------------------------------------------------------------
��� ��������: ������ ��������� ������������
-----------------------------------------------------------------------------------------------------
�������: 13
-----------------------------------------------------------------------------------------------------
������: ��-192
-----------------------------------------------------------------------------------------------------
������� �������: ���� ������� �(nxn). ����� � ������ ������ ����� ��������, ����� �� �������
��������� ������ �������, � ������ ������ ������� ��������.
-----------------------------------------------------------------------------------------------------
*/

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
    for (int i = 0; i < n; i++)
    {
        delete[] p[i];
    }
    delete[] p;
}

void work(int** p, int n, int** c)
{
    bool AllNumbersLeftSmaller = false;
    bool AllNumbersRightBigger = false;
    bool NoNumbersInRow = false;

    c = new int* [2];
    for (int i = 0; i < n; i++)
        c[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        NoNumbersInRow = true;
        for (int j = 0; j < n; j++)
        {
            if ((j > 0) and (j < n - 1))
            {
                int x = p[i][j];
                for (int k = 0; k < n; k++)
                {
                    int x_2 = p[i][k];
                    if (k < j)
                    {
                        if (x > x_2)
                        {
                            AllNumbersLeftSmaller = true;
                        }
                        else
                        {
                            AllNumbersLeftSmaller = false;
                        }
                    }

                    else if (k > j)
                    {
                        if (x < x_2)
                        {
                            AllNumbersRightBigger = true;
                        }
                        else
                        {
                            AllNumbersRightBigger = false;
                        }
                    }
                }

                if ((AllNumbersLeftSmaller) and (AllNumbersRightBigger))
                {
                    c[0][j] = -1;
                    c[1][j] = x;
                    NoNumbersInRow = false;
                }
                else
                {
                    c[0][j] = 0;
                    c[1][j] = x;
                }
            }
        }

        if (NoNumbersInRow)
        {
            cout << i << " ������ ��� �����, ���������������� �������";
        }

        else
        {
            cout << i << " ������ ���� �����, ��������������� �������";

            for (int i = 0; i < n; i++)
            {

                if (c[0][i] == -1)
                {
                    cout << "\n" << "�����, ��������������� �������: " << c[1][i];
                }

            }
        }
        cout << "\n";
    }

}

int main()
{
    setlocale(LC_CTYPE, "");
    int n;
    cout << "������� ����������� �������: ";
    cin >> n;
    int** p = NULL;
    int** c = NULL;
    input_matr(p, n);
    cout << "��������� ������: \n";
    output_matr(p, n);
    work(p, n, c);
    delete_p(p, n);
}