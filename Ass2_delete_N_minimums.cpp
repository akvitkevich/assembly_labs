#include "pch.h"
#include <iostream>

using namespace std;
/*
Найти в последовательности N наименьших элементов,
удалить их и подтянуть последовательность к началу, в конце добавить нули.
*/

int main()
{
	setlocale(LC_ALL, ".1251");
	int A[] = { -10, 1, 4, -2 , 5, 5, -6, 6, -2, 7, 3, 8, -9, -1, 0, 9, 2, 0, 0, 7};
	int min;
	const int k = 20;
	for (int i = 0; i < k; ++i)
	{
		cout << A[i] << " | ";
	}
	cout << "\nКоличество элементов: " << k << endl;
	cout << "Введите кол-во удаляемых минимальных элементов: ";
	int n;
	cin >> n;
	_asm {
		mov edi, n
		cmp edi, k
		jg mistake
		cmp edi, 0
		je endOfProg
		mov edi, -1
	beg:
		add edi, 1
		cmp edi, n
		je konec
		mov ecx, k
		sub ecx, edi
		xor ebx, ebx
		xor eax, eax
		mov edx, 2147483647
		sub ebx, 4
		mov esi, 0
	finder:
		test ecx, ecx
		je endik
		dec ecx
		add ebx, 4
		cmp edx, A[ebx]
		jle finder
		mov edx, A[ebx]
		mov esi, ebx; в ESI храним адрес минимума
		jmp finder
	endik :
		mov min, edx
		mov ecx, esi
	deleter :
		mov eax, k
		imul eax, 4
		cmp ecx, eax
		jge finish
		add esi, 4
		mov ebx, A[esi]
		sub esi, 4
		mov A[esi], ebx
		mov esi, ecx
		add ecx, 4
		jmp deleter	
	finish :
		jmp beg
	konec :
		mov eax, k
		mov ecx, n
		sub eax, ecx
		imul eax, 4
	zeros :
		mov A[eax], 0
		add eax, 4
		loop zeros
	endOfProg:
	}
	for (int i = 0; i < k; ++i)
	{
		cout << A[i] << " | ";
	}
	return 0;
	_asm {
		mistake:
	}
	cout << "Невозможно удалить больше элементов, чем их есть в массиве!\n";
	return 0;
}