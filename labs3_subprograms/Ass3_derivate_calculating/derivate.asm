.586
public calculator1
public calculator2
public @calculator3@12
extern _k_is_greater_than_n : proc
.model flat
.code

calculator1 proc c, A:dword, n:dword, k:dword
	mov edx, n
	cmp k, edx
	jge mistake
	xor ecx, ecx
	mov ebx, A
	xor eax, eax
begin:	
	cmp ecx, k
	je finish
	inc ecx
	mov esi, A
proizv:
	cmp edx, 0
	je end_of_proizv
	dec edx
	push eax
	mov eax, [ebx]
	add ebx, 4
	imul eax, edx
	mov [esi], eax
	pop eax
	add esi, 4
	jmp proizv
end_of_proizv:
	inc eax
	mov edx, n
	sub edx, eax
	mov ebx, A
	cmp eax, k
	jle begin
finish:
	mov eax, n
	sub eax, k
	ret
mistake:
	call _k_is_greater_than_n
	xor eax, eax
	ret
calculator1 endp

calculator2 proc stdcall, A:dword, n:dword, k:dword
	mov edx, n
	cmp k, edx
	jge mistake
	xor ecx, ecx
	mov ebx, A
	xor eax, eax
begin:	
	cmp ecx, k
	je finish
	inc ecx
	mov esi, A
proizv:
	cmp edx, 0
	je end_of_proizv
	dec edx
	push eax
	mov eax, [ebx]
	add ebx, 4
	imul eax, edx
	mov [esi], eax
	pop eax
	add esi, 4
	jmp proizv
end_of_proizv:
	inc eax
	mov edx, n
	sub edx, eax
	mov ebx, A
	cmp eax, k
	jle begin
finish:
	mov eax, n
	sub eax, k
	ret 12
mistake:
	call _k_is_greater_than_n
	xor eax, eax
	ret 12
calculator2 endp

@calculator3@12 proc
local A:dword, n:dword, k:dword
	mov n, edx
	cmp k, edx
	jge mistake
	mov A, ecx
	mov k, eax
	mov edx, n
	xor ecx, ecx
	mov ebx, A
	xor eax, eax
begin:	
	cmp ecx, k
	je finish
	inc ecx
	mov esi, A
proizv:
	cmp edx, 0
	je end_of_proizv
	dec edx
	push eax
	mov eax, [ebx]
	add ebx, 4
	imul eax, edx
	mov [esi], eax
	pop eax
	add esi, 4
	jmp proizv
end_of_proizv:
	inc eax
	mov edx, n
	sub edx, eax
	mov ebx, A
	cmp eax, k
	jle begin
finish:
	mov eax, n
	sub eax, k
	ret 4
mistake:
	call _k_is_greater_than_n
	xor eax, eax
	ret 4
@calculator3@12 endp

end