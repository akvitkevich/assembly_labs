#include "pch.h"
#include <iostream>
using namespace std;

/*
Преобразовать целочисленную последовательность,
расположив сначала четные элементы, затем нечетные,
сохранив порядок.
*/

extern "C" void __cdecl masSort_cdecl(int *, int);
extern "C" void __stdcall masSort_stdcall(int *, int);
extern "C" void __fastcall masSort_fastcall(int, int *);



int main()	
{
		int A[] = { 1, 6, 7, 8, 9, 10, 2, 3, 1,8};
	//	int A[] = { 2,4,6,8,10,12,14,16,18,20 };
	//  int A[] = { 1,3,5,7,9,11,13,15,17,19 };
	//	int A[] = { 1,2,3,4,5,6,7,8,9,10 };
	//	int A[] = { 12, 7, 14, 1, 0 };
	//	int A[] = { 9,5,6 };
	//	int A[] = { 1 };
	const int n = 10;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	masSort_cdecl(A, n);
//	masSort_stdcall(A, n);
//	masSort_fastcall(n, A);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
