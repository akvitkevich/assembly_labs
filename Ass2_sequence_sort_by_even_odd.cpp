#include "pch.h"
#include <iostream>
using namespace std;

/*
Преобразовать целочисленную последовательность,
расположив сначала четные элементы, затем нечетные,
сохранив порядок.
*/

int main()
{
	int A[] = { 1, 6, 7, 8, 9, 10, 2, 3, 4, 5 };
	//  int A[] = { 2,4,6,8,10,12,14,16,18,20 };
	//  int A[] = { 1,3,5,7,9,11,13,15,17,19 };
	const int n = 10;
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
	for1 :
		mov edx, ecx
	for2 :
		mov eax, A[esi]
		add esi, 4
		mov ebx, A[esi]
		push eax
		push ebx
		and eax, 1
		and ebx, 1
		cmp eax, ebx
		jg _swap
		jmp _pr
	_swap :
		xor eax, ebx
		xor ebx, eax
		xor eax, ebx
		pop ebx
		pop eax
		mov A[esi], eax
		sub esi, 4
		mov A[esi], ebx
		add esi, 4
	_pr:
		dec edx
		cmp edx, 0
		je _tr
		jmp for2
	_tr :
		xor esi, esi
		loop for1
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}