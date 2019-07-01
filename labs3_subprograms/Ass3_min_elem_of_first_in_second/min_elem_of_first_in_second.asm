.586
public findElem1
public findElem2
public @findElem3@12
extern _mistake : proc
extern _my_out : proc
.model flat
.code
findElem1 proc c, A:dword, B:dword, n:dword
	local cur_min:dword
	mov cur_min, 2147483647
	mov ebx, A
	sub ebx, 4
	mov ecx, n
probeg_po_1:
	cmp ecx, 0
	je end_of_prog
	dec ecx
	add ebx, 4
	mov eax, [ebx]
	cmp eax, cur_min
	jge probeg_po_1
	mov edx, n
	mov esi, B
	sub esi, 4
probeg_po_2:
	cmp edx, 0
	je new_min
	dec edx
	add esi, 4
	cmp eax, [esi]
	je probeg_po_1
	jmp probeg_po_2
new_min:
	mov cur_min, eax
	jmp probeg_po_1
end_of_prog:
	cmp cur_min, 2147483647
	jne ok
	call _mistake
	ret
ok:
	mov eax, cur_min
	call _my_out
	ret
findElem1 endp

findElem2 proc stdcall, A:dword, B:dword, n:dword
	local cur_min:dword
	mov cur_min, 2147483647
	mov ebx, A
	sub ebx, 4
	mov ecx, n
probeg_po_1:
	cmp ecx, 0
	je end_of_prog
	dec ecx
	add ebx, 4
	mov eax, [ebx]
	cmp eax, cur_min
	jge probeg_po_1
	mov edx, n
	mov esi, B
	sub esi, 4
probeg_po_2:
	cmp edx, 0
	je new_min
	dec edx
	add esi, 4
	cmp eax, [esi]
	je probeg_po_1
	jmp probeg_po_2
new_min:
	mov cur_min, eax
	jmp probeg_po_1
end_of_prog:
	cmp cur_min, 2147483647
	jne ok
	call _mistake
	ret 12
ok:
	mov eax, cur_min
	call _my_out
	ret 12
findElem2 endp

@findElem3@12 proc
local cur_min:dword
local n:dword
local B:dword
	mov esp, ebp
	push esp
	mov n, ecx
	mov ebx, edx
	mov cur_min, 2147483647
	mov B, eax
	sub ebx, 4
probeg_po_1:
	cmp ecx, 0
	je end_of_prog
	dec ecx
	add ebx, 4
	mov eax, [ebx]
	cmp eax, cur_min
	jge probeg_po_1
	mov edx, n
	mov esi, B
	sub esi, 4
probeg_po_2:
	cmp edx, 0
	je new_min
	dec edx
	add esi, 4
	cmp eax, [esi]
	je probeg_po_1
	jmp probeg_po_2
new_min:
	mov cur_min, eax
	jmp probeg_po_1
end_of_prog:
	cmp cur_min, 2147483647
	jne ok
	call _mistake
	pop esp
	ret 4
ok:
	mov eax, cur_min
	call _my_out
	pop esp
	ret 4
@findElem3@12 endp
end