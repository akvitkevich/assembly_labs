#include "pch.h"
#include <iostream>
using namespace std;

/*
1.  Для  строки длиною не более 255 символов выполнить следующие действия:
г) Заменить все одинаковые рядом стоящие символы одним
*/

int main()
{
	char stroka[256];
	cin.getline(stroka, 256, '\n');
	cout << stroka;
	int len = strlen(stroka);
	int elems_to_delete;
	_asm {
		lea ebx, stroka
		push ebx
		xor eax, eax
		xor edx, edx
	checker_:	
		mov ecx, len
		pop ebx
		dec ebx
	checker:
		mov al, [ebx]
		cmp al, 0
		je myEnd
		inc ebx
		cmp al, [ebx]
		je deleter_
		loop checker
		jmp myEnd
	deleter_:
		push ebx
		inc edx
		mov ecx, len
		sub ecx, edx
	deleter:
		inc ebx
		mov al, [ebx]
		dec ebx
		mov [ebx], al
		inc ebx
		loop deleter
		jmp checker_
	myEnd:
	}
	cout << endl << stroka << endl;
}