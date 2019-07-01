#include "pch.h"
#include <iostream>
using namespace std;

extern "C" void sortMas(int *A, int n);

int main()
{
	setlocale(LC_ALL, ".1251");
	int A[100];
	int n;
	cout << "Введите кол-во элементов в массиве (<100): ";
	cin >> n;
	cout << "Введите элементы массива" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	cout << endl;
	sortMas(A, n);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	return 0;
}
