#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

extern "C" void __cdecl Sort_cdecl(int*, int, int);
extern "C" void __stdcall Sort_stdcall(int*, int, int);
extern "C" void __fastcall Sort_fastcall(int*, int, int);

extern "C" void mistake()
{
	cout << "Невозмоно удалить больше элементов, чем их есть в массиве!\n";
	exit(-1);
};

int main()
{
	setlocale(LC_ALL, ".1251");
	//srand(time(NULL));
	int n = 20;

	int *A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 100 + -50;
		cout << setw(3) << A[i] << " | ";
	}

	int k;
	cout << endl << "\nhow many numbers should i delete?" << endl;
	cin >> k;

//	Sort_cdecl(A, n, k);
//	Sort_stdcall(A, n, k);
	Sort_fastcall(A, k, n);
	
	for (int i = 0; i < n; i++)
		cout << setw(3) << A[i] << " | ";

	return 0;
}
