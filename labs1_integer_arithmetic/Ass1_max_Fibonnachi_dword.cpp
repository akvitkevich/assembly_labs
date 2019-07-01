/*
Числа  Фибоначчи  вычисляются  по  формулам:  F[i]=F[i-1]+F[i-2], причем F[0]=F[1]=1;
а)  найти  максимальное  число  Фибоначчи,  которое  умещается  в двойное слово
*/
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int ans;
	_asm {
		mov ebx, 1
		mov eax, 1
	m2:	
		mov ecx, eax
		add eax, ebx
		jo m1
		mov ebx, ecx
		jmp m2
	m1: 
		mov ans, ecx 
	}
	cout << ans << endl;
}