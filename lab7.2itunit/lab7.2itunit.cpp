#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2it/lab7.2it.cpp" 


int SumMinRows(int** a, const int k, const int n);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab721
{
    TEST_CLASS(UnitTestLab721)
    {
    public:

        TEST_METHOD(TestSumMinRows)
        {
            const int k = 3;
            const int n = 3;

            // Виділення пам'яті під тестову матрицю 3x3
            int** a = new int* [k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            // Заповнення матриці конкретними тестовими значеннями:
            // Рядок 0: { 3,  1, 5 } -> min = 1
            // Рядок 1: {-2,  4, 0 } -> min = -2
            // Рядок 2: { 7,  8, 2 } -> min = 2
            a[0][0] = 3;  a[0][1] = 1;  a[0][2] = 5;
            a[1][0] = -2; a[1][1] = 4;  a[1][2] = 0;
            a[2][0] = 7;  a[2][1] = 8;  a[2][2] = 2;

            // Очікувана сума: 1 + (-2) + 2 = 1
            int expected = 1;
            int actual = SumMinRows(a, k, n);

            // Перевірка відповідності очікуваного значення і фактичного
            Assert::AreEqual(expected, actual);

            // Звільнення пам'яті
            for (int i = 0; i < k; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}