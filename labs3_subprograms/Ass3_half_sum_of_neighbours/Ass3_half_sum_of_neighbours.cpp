#include "pch.h"
#include <iostream>

using namespace std;

/*
 В  последовательности из N элементов (1<=N<=100) выбрать без повторений те элементы,
 которые равны полусумме соседних элементов.
*/

extern "C" int __cdecl halfSum_cdecl(int *A, const int n, int *B);
extern "C" int __stdcall halfSum_stdcall(int *A, const int n, int *B);
extern "C" int __fastcall halfSum_fastcall(const int n, int*A, int *B);

extern "C" void noAns()
{
	cout << "Таких чисел нет!\n";
}

int main()
{
	system("chcp 1251");
	int A[] = { 1, 7, 13, 4, 5, 6, 4, 2, 10, 18, 12, 6, 8, 11, 14, 7, 0, 6, 3, 0 };
	const int n = 20;
	//int A[] = { 1, 3, 3};
	//const int n = 3;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	int *B = new int[n - 2];
	int k;
//	k = halfSum_cdecl(A, n, B);
//	k = halfSum_stdcall(A, n, B);
	k = halfSum_fastcall(n,A, B);
	for (int i = 0; i < k; ++i)
	{
		cout << B[i] << " ";
	}
	delete[] B;
	return 0;
}
