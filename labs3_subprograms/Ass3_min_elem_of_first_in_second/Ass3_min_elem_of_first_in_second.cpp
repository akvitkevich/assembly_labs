#include "pch.h"
#include <iostream>
using namespace std;

extern "C" void my_out(int a)
{
	cout << "answer: " << a << endl;
}
extern "C" void mistake()
{
	cout << ": there is no element!\n";
}

extern "C" void __cdecl findElem1(int*, int*, int);
extern "C" void __stdcall findElem2(int*, int*, int);
extern "C" void __fastcall findElem3(int, int*, int*);


int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //[1..10]
	int B[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11 }; //[1..6]&&[7..11]
//	int B[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //[1..10]
	const int n = 10;
	cout << "cdecl ";
	findElem1(A, B, n);
	cout << "\nstdcall ";
	findElem2(A, B, n);
	cout << "\nfastcall ";
	findElem3(n, A, B);
}
