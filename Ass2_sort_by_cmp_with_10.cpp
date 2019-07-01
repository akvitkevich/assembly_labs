#include "pch.h"
#include <iostream>
using namespace std;

/*
Преобразовать целочисленную последовательность,
расположив сначала элементы <=10, затем остальные,
сохранив порядок.
*/

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
	_asm
	{
		xor esi, esi
		mov ecx, n
		dec ecx
		cmp ecx, 0
		je end_of_prog
	for1 :
		mov edx, ecx
	for2 :
		mov eax, A[esi]
		add esi, 4
		mov ebx, A[esi]
		cmp eax, 10
		jl ok
		cmp ebx, 10
		jle _swap
		ok :
		jmp _pr
	_swap :
		mov A[esi], eax
		sub esi, 4
		mov A[esi], ebx
		add esi, 4
	_pr :
		dec edx
		cmp edx, 0
		je _tr
		jmp for2
	_tr :
		xor esi, esi
		loop for1
	end_of_prog :
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}