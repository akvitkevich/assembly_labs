#include "pch.h"
#include <iostream>
using namespace std;

/*
Вычислить число значащих разрядов в двоичной записи натурального числа
*/

int main()
{
	setlocale(LC_ALL, ".1251");
	int num;
	cin >> num;
	int cnt;
	_asm {
		mov  eax, num
		xor ebx, ebx
	shift:
		shr  eax, 1
		adc  ebx, 0
		cmp eax, 0
		je finish
		jmp shift
	finish:
		mov cnt, ebx
	}
	cout << cnt << endl;
}