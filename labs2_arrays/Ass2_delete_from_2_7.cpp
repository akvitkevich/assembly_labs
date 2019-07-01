#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	short A[] = { -127, -2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const int n = 10;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	_asm {
		xor eax, eax
	beg :
		mov ecx, n
		sub ecx, eax
		mov ebx, -2
	checker :
		cmp ecx, 0
		je zeros
		dec ecx
		add ebx, 2
		mov dx, A[ebx]
		cmp dx, 2
		jl checker
		cmp dx, 7
		jg checker
		inc eax
	deleter :
		mov edx, ebx
		add edx, 2
		mov dx, A[edx]
		mov A[ebx], dx
		add ebx, 2
		cmp ecx, 0
		je beg
		dec ecx
		jmp deleter
	zeros :
		add ebx, 2
		mov A[ebx], 0
		dec eax
		cmp eax, 0
		je myend
		jmp zeros
	myend :
	}
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}