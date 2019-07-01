.586
public Sort_cdecl
public Sort_stdcall
public @Sort_fastcall@12
extern _mistake : proc
.model flat
.code


Sort_cdecl proc c, A:dword, n:dword, k:dword
local min:dword, adress:dword
	mov edi, k
	cmp edi, n
	jg mistake
	je konec
	mov edi, -1
beg:
	mov min, -2147483648
	add edi, 1
	cmp edi, k
	je konec
	mov ecx, n
	sub ecx, edi
	mov ebx, A
	xor eax, eax
	sub ebx, 4
	mov esi, 0
finder:
	test ecx, ecx
	je endik
	dec ecx
	add ebx, 4
	mov edx, [ebx]
	cmp edx, min
	jle finder
	mov min, edx
	mov adress, ebx; в ESI храним адрес минимума
	jmp finder
endik :
	mov eax, n
	imul eax, 4
	add eax, A;теперь в A - конец массива
	mov ecx, adress
deleter :
	cmp ecx, eax
	jge finish
	add ecx, 4
	mov ebx, [ecx]
	sub ecx, 4
	mov [ecx], ebx
	add ecx, 4
	jmp deleter	
finish :
	jmp beg
konec :
	mov eax, n
	mov ecx, k
	sub eax, ecx
	imul eax, 4
	add eax, A
zeros :
	push ecx
	xor ecx, ecx
	mov [eax], ecx
	pop ecx
	add eax, 4
	loop zeros
endOfProg:
	ret
mistake:
	call _mistake
	ret
Sort_cdecl endp


Sort_stdcall proc stdcall, A:dword, n:dword, k:dword
local min:dword, adress:dword
	mov edi, k
	cmp edi, n
	jg mistake
	je konec
	mov edi, -1
beg:
	mov min, -2147483648
	add edi, 1
	cmp edi, k
	je konec
	mov ecx, n
	sub ecx, edi
	mov ebx, A
	xor eax, eax
	sub ebx, 4
	mov esi, 0
finder:
	test ecx, ecx
	je endik
	dec ecx
	add ebx, 4
	mov edx, [ebx]
	cmp edx, min
	jle finder
	mov min, edx
	mov adress, ebx; в ESI храним адрес минимума
	jmp finder
endik :
	mov eax, n
	imul eax, 4
	add eax, A;теперь в A - конец массива
	mov ecx, adress
deleter :
	cmp ecx, eax
	jge finish
	add ecx, 4
	mov ebx, [ecx]
	sub ecx, 4
	mov [ecx], ebx
	add ecx, 4
	jmp deleter	
finish :
	jmp beg
konec :
	mov eax, n
	mov ecx, k
	sub eax, ecx
	imul eax, 4
	add eax, A
zeros :
	push ecx
	xor ecx, ecx
	mov [eax], ecx
	pop ecx
	add eax, 4
	loop zeros
endOfProg:
	ret 12
mistake:
	call _mistake
	ret 12
Sort_stdcall endp



@Sort_fastcall@12 proc
local min:dword, adress:dword, A:dword, n:dword, k:dword
	mov A, ecx
	mov k, edx
	mov n, eax
	mov edi, k
	cmp edi, n
	jg mistake
	je konec
	mov edi, -1
beg:
	mov min, -2147483648
	add edi, 1
	cmp edi, k
	je konec
	mov ecx, n
	sub ecx, edi
	mov ebx, A
	xor eax, eax
	sub ebx, 4
	mov esi, 0
finder:
	test ecx, ecx
	je endik
	dec ecx
	add ebx, 4
	mov edx, [ebx]
	cmp edx, min
	jle finder
	mov min, edx
	mov adress, ebx; в ESI храним адрес минимума
	jmp finder
endik :
	mov eax, n
	imul eax, 4
	add eax, A;теперь в A - конец массива
	mov ecx, adress
deleter :
	cmp ecx, eax
	jge finish
	add ecx, 4
	mov ebx, [ecx]
	sub ecx, 4
	mov [ecx], ebx
	add ecx, 4
	jmp deleter	
finish :
	jmp beg
konec :
	mov eax, n
	mov ecx, k
	sub eax, ecx
	imul eax, 4
	add eax, A
zeros :
	push ecx
	xor ecx, ecx
	mov [eax], ecx
	pop ecx
	add eax, 4
	loop zeros
endOfProg:
	ret 4
mistake:
	call _mistake
	ret 4
@Sort_fastcall@12 endp

end