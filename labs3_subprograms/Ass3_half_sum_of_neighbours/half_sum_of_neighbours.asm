.486
PUBLIC halfSum_cdecl
PUBLIC halfSum_stdcall
PUBLIC @halfSum_fastcall@12
extern _noAns : proc
.model flat
.code


halfSum_cdecl proc c A : dword, n : dword, B : dword
	mov ebx, [esp + 8]
	mov ecx, [esp + 12]
	mov esi, [esp + 16]
	sub ecx, 2
	cmp ecx, 0
	jle mistake
	xor eax, eax
	xor edi, edi
check :
	xor edx, edx
	add edx, [ebx]
	add ebx, 8
	add edx, [ebx]
	sub ebx, 4
	shr edx, 1
	jc notEqual
	cmp[ebx], edx
	jne notEqual
	push ecx
	mov ecx, eax
	xor edi, edi
create_mas :
	cmp ecx, 0
	je addElem
	dec ecx
	cmp[esi][edi], edx
	je elemExists
	add edi, 4
	jmp create_mas
addElem :
	mov[esi][edi], edx
	inc eax
elemExists :
	pop ecx
notEqual :
	loop check
	cmp eax, 0
	je mistake
	ret
mistake :	
	call _noAns
	xor eax, eax
finish :
	ret
halfSum_cdecl endp


halfSum_stdcall proc stdcall, A:dword, n:dword, B:dword
	mov ebx, [esp + 8]
	mov ecx, [esp + 12]
	mov esi, [esp + 16]
	sub ecx, 2
	cmp ecx, 0
	jle mistake
	xor eax, eax
	xor edi, edi
check :
	xor edx, edx
	add edx, [ebx]
	add ebx, 8
	add edx, [ebx]
	sub ebx, 4
	shr edx, 1
	jc notEqual
	cmp[ebx], edx
	jne notEqual
	push ecx
	mov ecx, eax
	xor edi, edi
create_mas :
	cmp ecx, 0
	je addElem
	dec ecx
	cmp[esi][edi], edx
	je elemExists
	add edi, 4
	jmp create_mas
addElem :
	mov[esi][edi], edx
	inc eax
elemExists :
	pop ecx
notEqual :
	loop check
	cmp eax, 0
	je mistake
	ret
mistake :	
	call _noAns
	xor eax, eax
finish :
	ret 12
halfSum_stdcall endp


@halfSum_fastcall@12 proc
	push ebp
	mov ebp, esp
	mov ebx, edx
	sub ecx, 2
	cmp ecx, 0
	jle mistake
	xor esi, esi
	xor edi, edi
check :
	xor edx, edx
	add edx, [ebx]
	add ebx, 8
	add edx, [ebx]
	sub ebx, 4
	shr edx, 1
	jc notEqual
	cmp[ebx], edx
	jne notEqual
	push ecx
	mov ecx, esi
	xor edi, edi
create_mas :
	cmp ecx, 0
	je addElem
	dec ecx
	cmp[eax][edi], edx
	je elemExists
	add edi, 4
	jmp create_mas
addElem :
	mov[eax][edi], edx
	inc esi
elemExists :
	pop ecx
notEqual :
	loop check
	cmp esi, 0
	je mistake
	mov eax, esi
	pop ebp
	ret 4
mistake :	
	call _noAns
	xor eax, eax
finish :
	pop ebp
	ret 4
@halfSum_fastcall@12 endp

end