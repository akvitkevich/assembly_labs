#include "pch.h"
#include <iostream>
using namespace std;
/*
В строке длиною не более 255 символов слова разделены хотя бы одним пробелом:
Найти все слова с одной гласной буквой (латинский алфавит).
*/

int main()
{
	setlocale(LC_ALL, ".1251");
	char vowels[] = "EYUIOAeyuioa"; //все гласные (12 штук)
	char stroka[256];
	cin.getline(stroka, 256, '\n');
	int cur_adress;
	char ans[256];
	__asm {
		lea ebx, stroka
		lea edx, ans
		dec ebx
	search_word:
		inc ebx
		mov al, [ebx]
		cmp al, ' '
		je search_word
		cmp al, '\0'
		je end_of_prog
		mov cur_adress, ebx
	beg:
		lea esi, vowels
		mov ecx, 12 ;всего гласных - 12
	cmp_with_vowels:
		cmp al, [esi]
		je one_vowel
		inc esi
		loop cmp_with_vowels
		inc ebx
		mov al, [ebx]
		cmp al, ' '
		je search_word
		cmp al, '\0'
		mov al, [ebx]
		cmp al, ' '
		je end_of_prog
		jmp beg
	one_vowel:
		inc ebx
		mov al, [ebx]
		cmp al, ' '
		je FOUND_WORD
		cmp al, '\0'
		je FOUND_WORD
		mov ecx, 12
		lea esi, vowels
	cmp_with_vowels_ :
		cmp al, [esi]
		jne ok
	find_next_word:
		cmp al, ' '
		je search_word
		cmp al, '\0'
		je found_word
		inc ebx
		mov al, [ebx]
		mov cur_adress, ebx
		jmp find_next_word
	ok:	
		inc esi
		loop cmp_with_vowels_
		jmp one_vowel
	FOUND_WORD:
		mov ebx, cur_adress
	create_word:
		mov al, [ebx]
		cmp al, ' '
		jne checker
		mov [edx], '\n'
		inc edx
		jmp search_word
	checker:
		cmp al, '\0'
		je end_of_prog
		mov [edx], al
		inc edx
		inc ebx
		jmp create_word
	end_of_prog:
		mov [edx], '\0'
	}
	cout << ans << endl;
	return 0;
}
