#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	
	setlocale(LC_ALL, ".1251");
	int a;
	cin >> a;
	_asm {
		mov eax, a
		cmp eax, 0
		je automorph
		mov bx, 10
		mov ecx, 1
	findPowOfTen: ;получаем число 10^n, где n - кол-во цифр числа
		cdq
		idiv bx
		imul ecx, bx
		cmp eax, 0
		jne findPowOfTen
	checker: ;делим 'a'^2 на 10^'n'. если остаток равен 'a', то число - автоморфное
		mov eax, a
		imul eax
		div ecx
		mov eax, a
		cmp eax, edx
		jne notAutomorph
	automorph:
	} 
	cout << "Число " << a << " является автоморфным!\n";
	return 0;
	_asm
	{
	notAutomorph:
	}
	cout << "Число " << a << " не является автоморфным!\n";
	return 0;
}