#include "pch.h"
#include <iostream>

using namespace std;


void __fastcall printMin(int min, int n)
{
	cout << "Минимум - " << min << " #" << n << endl;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	int A[] = { 1, 5, 13, 4, 5, 6, 4, 100, 5, 9, 4, 6, 8, 11, 14, 0, 10, 5, 2, 0 };
	const int n = 20;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	_asm {
		mov ecx, n
		sub ecx, 2; т.к.первый и последний элемент не надо проверять
		xor eax, eax
		lea ebx, A
		add ebx, 4
	check :
		inc eax
		mov edx, [ebx]
		sub ebx, 4
		cmp edx, [ebx]
		jl loc_min
		add ebx, 8
		jmp m
	loc_min:
		add ebx, 8
		cmp edx, [ebx]
		jl printElem
	m:
		loop check
		jmp konec
	printElem:
		push ecx
		push edx
		push eax
		mov ecx, edx
		mov edx, eax
		call printMin
		pop eax
		pop edx
		pop ecx
		jmp m
	konec:
	}
	return 0;
}