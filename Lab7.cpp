#include<iostream>

#define N 5

using namespace std;

void init(int a[N][N])    //���� ������� � ����������
{
    int i, j;
    cout << "������� �������� ������� A: \n";
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "]= ";
            cin >> a[i][j];
        }

}

void init_f(int a[N][N]) //���������� ������� �� txt �����
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
    else cout << "������ �������� �����. \n";
}

int* mas_x(int(*a)[N], int* x,  //������� �������� X
    void (*pfunc)(int[N][N]))
{
    int i, j, min;
    pfunc(a); //
    for (i = 0; i < N; i++) {

        min = a[i][0];

        for (j = 0; j < N; j++) {

            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
        x[i] = min;

        if (min < 0)
            x[i] = -1;
        else
            x[i] = 1;
    }
    return x;
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