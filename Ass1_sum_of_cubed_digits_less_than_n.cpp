#include "pch.h"
#include <iostream>
using namespace std;

/*
Находит все числа, меньшие N,
сумма кубов цифр которого равна этому числу
*/

int main()
{
	setlocale(LC_ALL, ".1251");
	int n;
	cin >> n;
	int cur = -1;
	int k;
	_asm {
		mov esi, 0
	beg:
		cmp esi, n
		mov k, esi
		jge konchina
		add esi, 1
		mov eax, esi
		mov ecx, 0
	m: 
		mov di, 10
		cdq
		div di
		cmp eax, 0
		je endik
		mov edi, eax
		mov eax, edx
		mov ebx, edx
		mul ebx
		mul ebx
		add ecx, eax
		mov eax, edi
		jmp m
	endik:
		mov eax, edx
		mov ebx, edx
		mul ebx
		mul ebx
		add ecx, eax
		jmp checker
	checker:
		cmp esi, ecx
		jne beg
		mov cur, esi
	}
	cout << cur << endl;
	_asm {
		mov esi, cur
		jmp beg
	konchita:
	}
	return 0;
}