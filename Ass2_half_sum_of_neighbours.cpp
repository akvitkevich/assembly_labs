#include "pch.h"
#include <iostream>

using namespace std;

/*
 В  последовательности из N элементов (1<=N<=100) выбрать без повторений те элементы,
 которые равны полусумме соседних элементов.
*/

int main()
{
	int A[] = { 1, 5, 13, 4, 5, 6, 4, 2, 5, 9, 4, 6, 8, 11, 14, 0, 10, 5, 2, 0};
	const int n = 20;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	int *B = new int[n];
	int k;
	_asm {
		mov ecx, n
		sub ecx, 2 ;т.к. первый и последний элемент не надо проверять
		xor eax, eax
		lea ebx, A
		mov esi, B
		xor edi, edi
	check:
		xor edx, edx
		add edx, [ebx]
		add ebx, 8
		add edx, [ebx]
		sub ebx, 4
		shr edx, 1
		cmp [ebx], edx
		jne notEqual
		push ecx
		mov ecx, eax
		xor edi, edi
	create_mas:
		cmp ecx, 0	
		je addElem
		dec ecx
		cmp [esi][edi], edx
		je elemExists
		add edi, 4
		jmp create_mas
	addElem:
		mov [esi][edi], edx
		inc eax
	elemExists:
		pop ecx
	notEqual:
		loop check
		mov k, eax
	}
	for (int i = 0; i < k; ++i)
	{
		cout << B[i] << " ";
	}
}