#include<iostream>

#define N 5

using namespace std;

void init(int a[N][N])    //¬вод массива с клавиатуры
{
    int i, j;
    cout << "¬ведите элементы матрицы A: \n";
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "]= ";
            cin >> a[i][j];
        }

}

void init_f(int a[N][N]) //—читывание массива из txt файла
{
    int i, j;
    FILE* fp;
    fopen_s(&fp, "matr.txt", "r");
    if (fp)
    {
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                fscanf_s(fp, "%d", &a[i][j]);
        fclose(fp);
    }
    else cout << "ќшибка открыти€ файла. \n";
}

int main()
{
    setlocale(LC_CTYPE, "");
    int a[N][N], x[N], y, v;
    void (*pfunc)(int[N][N]);
    y = 0;
    do
    {
        cout << ": ";
        cin >> v;
    } while (v != 1 && v != 2);
    if (v == 1) pfunc = &init;
    else pfunc = &init_f;
}