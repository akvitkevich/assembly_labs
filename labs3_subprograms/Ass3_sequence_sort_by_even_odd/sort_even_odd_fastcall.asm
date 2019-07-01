.486
PUBLIC @masSort_fastcall@8
.model flat
.code
@masSort_fastcall@8 proc
		mov esi, edx
		xor edx, edx
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
		mov ebx, [esi]
		push eax
		push ebx
		and eax, 1
		and ebx, 1
		cmp eax, ebx
		pop ebx
		pop eax
		jg _swap
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
@masSort_fastcall@8 endp
end