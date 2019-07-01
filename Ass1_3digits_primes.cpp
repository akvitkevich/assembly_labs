#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int a;
	_asm {
		mov ebx, 99
	beg:
		add ebx, 2
		cmp ebx, 999
		JE Mend
		mov eax, ebx
		mov si, 2
		cdq
		idiv si
		mov ecx, eax
	prost :
		mov eax, ebx
		cdq
		idiv ecx
		cmp edx, 0
		je finish
		cmp ecx, 2
		je finish2
		loop prost
	finish2 :
		mov a, ebx
	}
	cout << a << endl;
	_asm {
		jmp beg
		jmp Mend
	finish :
		jmp beg
	Mend :
	}
	return 0;
}