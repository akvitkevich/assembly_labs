#include "pch.h"
#include <iostream>

using namespace std;

/*
В строке длиною не более 255 символов слова разделены хотя бы одним пробелом.
Найти слово, содержащее максимальное количество повторений заданного символа.
*/

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, ".1251");
	char str[256];
	char w[256];
	cout << "Введите строку:\n";
	cin.getline(str, 256, '\n');
	cout << str;
	char c;
	cout << "\nВведите символ:\n";
	cin >> c;
	int len = strlen(str) + 1;
	int max;
	_asm {
		lea ebx, w
		mov al, c
		lea esi, str
		dec esi
		xor ebx, ebx
		mov ecx, len
		xor edx, edx
	findword :
		cmp ebx, edx
		jge ok1
		mov ebx, edx
		pop edi
	ok1 :
		dec ecx
		cmp ecx, 0
		je myEnd
		xor edx, edx
		inc esi
		cmp[esi], 32
		je findWord
		push esi
	countLetter :
		cmp[esi], 32
		je findword
		cmp[esi], 0
		je myEnd
		cmp[esi], al
		jne notEqual
		inc edx
	notEqual :
		inc esi
		dec ecx
		jmp countLetter
	myEnd :
		cmp ebx, edx
		jge ok2
		mov ebx, edx
		pop edi
	ok2 :
		mov max, ebx
		cmp ebx, 0
		je mistake
		lea ebx, w
	word_create :
		cmp[edi], 0
		je finish
		cmp[edi], 32
		je finish
		mov eax, [edi]
		mov[ebx], eax
		inc edi
		inc ebx
		jmp word_create
	finish :
		mov[ebx], 0
	}
	cout << "Символ " << c << " встречается " << max << " раз в слове: " << w << endl;
	return 0;
	_asm {
	mistake:
	}
	cout << "Данного символа нет в строке!\n";
	return 0;
}