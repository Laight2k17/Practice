/*
-----------------------------------------------------------------------------------------------------
��� ��������: ������ ��������� ������������
-----------------------------------------------------------------------------------------------------
�������: 13
-----------------------------------------------------------------------------------------------------
������� �������: ���� ������� �(5x5). ���������� ������ � �� 5 ���������, ������ �� ������� ����� 1, 
���� ���������� ������� ��������������� ������ ����������� � �1 � ��������� ������. 
���������� �������� Y, ��� ���������� �� �������� ��������� ������� X, ������ 1
-----------------------------------------------------------------------------------------------------
*/

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
    pfunc(a); //����� ����� ��������� ����� �� ���� ������� ����� ��������� a
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

int elem_y(int y, const int a[][N], int i, int* x) //������� �������� Y
{
    int k = 0;
    if (i <= 5)
    {
        if (x[i] == 1)
            k = i;
        y = elem_y(y, a, i + 1, x);
        if (y == 0)
            y = k;
    }
    else
    {
        y = 0;
        return y;
    }
    return y;
}

void output(const int  y, const int x[], const int a[][N])
{
    int i, j;
    FILE* fp;

    cout << "������ A:\n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    cout << "������ x:\n";
    for (i = 0; i < N; i++)
        cout << x[i] << " ";

    cout << "\n";
    if (y != 0)
    {
        cout << "�������� Y: " << y;
    }
    else
        cout << "�������� ������ ������� �����������.";

    fopen_s(&fp, "out.txt", "w");
    if (fp)
    {
        fprintf(fp, "������� A:\n");
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                fprintf(fp, "%5d", a[i][j]);
            fprintf(fp, "\n");
        }
        fprintf(fp, "������ X:\n");
        for (i = 0; i < N; i++)
            fprintf(fp, "%5d", x[i]);
        fprintf(fp, "\n");
        if (y != 0)
        {
            fprintf(fp, "�������� Y:");
            fprintf(fp, "%3d", y);
        }
        else
            fprintf(fp, "�������� ������ ������� �����������.");
        fclose(fp);
    }
    else cout << "������ ��������. \n";
}

int main()
{
    setlocale(LC_CTYPE, "");
    int a[N][N], x[N], y, v;
    void (*pfunc)(int[N][N]);
    y = 0;
    do
    {
        cout << "�������� ���� ������� (1 � ����������, 2 �� �����): ";
        cin >> v;
    } while (v != 1 && v != 2);
    if (v == 1) pfunc = &init;// ������������ ��������� ������ ����� �� ������� 
    else pfunc = &init_f;
    output(elem_y(y, a, 0, x), mas_x(a, x, pfunc), a);
}