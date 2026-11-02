#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int SumMinRows(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -20;
    int High = 50;

    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    // Динамічне виділення пам'яті під матрицю k x n
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int sumMin = SumMinRows(a, k, n);
    cout << "Sum of min elements in rows = " << sumMin << endl;

    // Звільнення виділеної пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumMinRows(int** a, const int k, const int n)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int minInRow = a[i][0];
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < minInRow)
                minInRow = a[i][j];
        }
        sum += minInRow;
    }
    return sum;
}