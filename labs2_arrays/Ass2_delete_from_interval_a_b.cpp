#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	signed char A[] = {-127, -2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		cout << int(A[i]) << " ";
	}
	cout << endl;
	cout << "Введите границы интервала [a,b]: ";
	char a, b;
	int a1, b1;
	cin >> a1 >> b1;
	a = a1;
	b = b1;
	_asm {
		xor eax, eax
	beg:
		mov ecx, n
		sub ecx, eax
		mov ebx, -1
	checker:
		cmp ecx, 0
		je zeros
		dec ecx
		add ebx, 1
		mov dl, A[ebx]
		cmp dl, 0
		jg ok
		neg dl
	ok:
		cmp dl, a
		jl checker
		cmp dl, b
		jg checker
		inc eax
	deleter:
		mov edx, ebx
		add edx, 1
		mov dl, A[edx]
		mov A[ebx], dl
		add ebx, 1
		cmp ecx, 0
		je beg
		dec ecx
		jmp deleter
	zeros:
		add ebx, 1
		mov A[ebx], 0
		dec eax
		cmp eax, 0
		je myend 
		jmp zeros
	myend:
	}
	for (int i = 0; i < n; ++i)
	{
		cout << int(A[i])<< " ";
	}
	cout << endl;
}