.486
PUBLIC sortMas
.model flat
.code
sortMas proc c A:dword, n:dword
		mov esi, [ebp+8]
		mov ecx, [ebp+12]
		cmp ecx, 2
		jg for1
		ret
	for1 :
		cmp ecx, 1
		je finish
		mov edx, ecx
		push esi
	for2 :
		mov eax, [esi]
		add esi, 4
		test eax, eax
		js signed
		jmp _pr
	signed:
		mov ebx, [esi]
		test ebx, ebx
		jns _swap
		jmp _pr
	_swap :
		mov [esi], eax
		sub esi, 4
		mov [esi], ebx
		add esi, 4
	_pr :
		dec edx
		cmp edx, 1
		je _tr
		jmp for2
	_tr :
		pop esi
		dec ecx
		jmp for1
	finish:
	ret 
sortMas endp
end