.486
PUBLIC _masSort_stdcall@8
.model flat
.code
_masSort_stdcall@8 proc 
		mov esi, [ebp+12]
		mov ecx, [ebp+8]
		cmp ecx, 2
		jg for1
		ret 8
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
	ret 8
_masSort_stdcall@8 endp
end