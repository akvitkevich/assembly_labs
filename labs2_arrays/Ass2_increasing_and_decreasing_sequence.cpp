#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	//int A[] = { 1, 1, 2, 2, 3, 5, 7, 11, 12, 12};
	//int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int A[] = { 1, 1, 1, 1, 1, 2, 3, 4, 5, 6 };
	//int A[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	//int A[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int A[] = { 10, 9, 9, 9, 9, 9, 9, 9, 9, 10 };
	//int A[] = { 10, 9, 9, 9, 9, 9, 9, 9, 9, 10 };
	int A[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	const int n = 10;
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	_asm {
		mov ecx, n
		dec ecx
		xor eax, eax
		mov ebx, dword ptr A[eax]
		add eax, 4
		mov edx, dword ptr A[eax]
		cmp ebx, edx
		jl vozrastaet
		jg ubyvaet
	ravno:
		cmp ecx, 1
		je myEnd
		dec ecx
		mov ebx, dword ptr A[eax]
		add eax, 4
		mov edx, dword ptr A[eax]
		cmp ebx, edx
		jl vozrastaet
		jg ubyvaet
		jmp ravno
	vozrastaet:
		cmp ecx, 1
		je good1
		dec ecx
		mov ebx, dword ptr A[eax]
		add eax, 4
		mov edx, dword ptr A[eax]
		cmp ebx, edx
		jle vozrastaet
		jmp nikakaya
	good1:
	}
	cout << "Последовательность возрастает.\n";
	return 0;
	_asm {
	ubyvaet:
		cmp ecx, 1
		je good2
		dec ecx
		mov ebx, dword ptr A[eax]
		add eax, 4
		mov edx, dword ptr A[eax]
		cmp ebx, edx
		jge ubyvaet
		jmp nikakaya
	good2 :
	}
	cout << "Последовательность убывает.\n";
	return 0;
	_asm{
	myEnd:
	}
	cout << "Последовательность из одних и тех же элементов.\n";
	return 0;
	_asm {
	nikakaya:
	}
	cout << "Последовательность не является ни возрастающей, ни убывающей!\n";
}