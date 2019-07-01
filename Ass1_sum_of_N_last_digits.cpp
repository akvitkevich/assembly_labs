#include "pch.h"
#include <iostream>

using namespace std;
/*
 Для двух натуральных чисел n, m 
 получить сумму m последних цифр числа n
*/

int main()
{
	setlocale(LC_ALL, ".1251");
	int n, m;
	cout << "Введите число N: ";
	cin >> n;
	cout << "Введите число M: ";
	cin>> m;
	int sum;
	_asm {
		mov eax, n
		mov ecx, m
		mov ebx, 0
		mov esi, 10
	summa:
		cdq
		div esi
		add ebx, edx
		dec ecx
		cmp ecx, 0
		jne summa
		mov sum, ebx
	}
	cout << "Сумма последних " << m << " цифр числа " << n << ":\n" << sum;
}