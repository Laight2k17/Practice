#include <iostream>

using namespace std;

void input_matr(int**& p, int n)
{
    int i, j;
    p = new int* [n];
    cout << "Заполните масив: \n";
    for (i = 0; i < n; i++)
    {
        p[i] = new int[n];
        for (j = 0; j < n; j++)
        {
            cout << "Элемент[" << i << "][" << j << "] = ";
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
    cout << "Введите размерность матрицы: ";
    cin >> n;
    int** p = NULL;
    input_matr(p, n);
    cout << "Введенный массив: \n";
    output_matr(p, n);
    //work(p, n);
    cout << "Модифицированный массив: \n";
    output_matr(p, n);
    delete_p(p, n);
}