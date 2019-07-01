#include "pch.h"
#include <iostream>

using namespace std;

/*
	Сократить дробь z/n если возможно
*/

int main()
{
	int z, n;
	cin >> z;
	cin >> n;
	cout << z << "/" << n << " -> ";
	_asm {
		mov eax, z
		mov ebx, n
		start:
		CDQ
		idiv ebx
		cmp edx, 0
		je finish
		mov eax, ebx
		mov ebx, edx
		jmp start
	finish: ; в EBX хранится НОД по алгоритму Евклида
		mov eax, z
		CDQ
		idiv ebx
		mov z, eax
		mov eax, n
		CDQ
		idiv ebx
		mov n, eax
	}
	cout << z << "/" << n << endl;
}