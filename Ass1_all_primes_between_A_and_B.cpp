#include <iostream>
using namespace std;

int main()
{
	int a = -1, l, r;
	cin >> l >> r;
	l--;
	if (l < 1) l = 1;
	int f;
	cout << "all primes:\n";
	_asm {
		mov ebx, l
	beg :
		add ebx, 1
		cmp ebx, 3
		jle finish2
		cmp ebx, r
		JG Mend
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
	system("pause");
	return 0;
}