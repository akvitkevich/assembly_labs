#include "pch.h"
#include <iostream>
using namespace std;

extern "C" int __cdecl calculator1(int*, int, int);
extern "C" int __stdcall calculator2(int*, int, int);
extern "C" int __fastcall calculator3(int*, int, int);

extern "C" void k_is_greater_than_n()
{
	cout << "Derivate is zero because k>=n!\n";
	exit(0);
};

int main()
{
	int A[] = { -1,2,5,-6,1,2,-7 };
	const int n = 7;
	int B[n];
	int k;
	cout << "Input k:\n";
	cin >> k;
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	int size;
	//size = calculator1(A, n, k);
	//size = calculator2(A, n, k);
	//size = calculator3(A, n, k);
	for (int i = 0; i < size; ++i)
	{
		cout << A[i] << " ";
	}
	return 0;
}
