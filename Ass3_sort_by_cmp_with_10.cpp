#include "pch.h"
#include <iostream>
using namespace std;

/*
Преобразовать целочисленную последовательность,
расположив сначала элементы <=10, затем остальные,
сохранив порядок.
*/

extern "C" void __cdecl sort_cdecl(int*, int);
extern "C" void __stdcall sort_stdcall(int*, int);
extern "C" void __fastcall sort_fastcall(int, int*);


int main()
{
	//  int A[] = { 1, 6, 7, 8, 9, 10, 2, 3, 4, 5 };
	//  int A[] = { 2,4,6,8,10,12,14,16,18,20 };
	//  int A[] = { 1,3,5,7,9,11,13,15,17,19 };
	int A[] = { 1,11,41,02,05,12,5,7,12,7 };
	const int n = 10;
	//  int A[] = { 10,12 };
	//  int A[] = { 12,10 };
	//  const int n = 2;
	//  int A[] = { 1 };
	//  const int n = 1;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	//sort_cdecl(A, n);
	//sort_stdcall(A, n);
	sort_fastcall(n, A);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}