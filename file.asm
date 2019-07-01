.486
public sort_cdecl
public sort_stdcall
;public @sort_fastcall@8
.model flat
.code

sort_cdecl proc c, A:dword, n:dword
		mov ecx, n
		dec ecx
		cmp ecx, 0
		je end_of_prog
	for1 :
		mov esi, A
		mov edx, ecx
	for2 :
		mov eax, [esi]
		add esi, 4
		mov ebx, [esi]
		cmp eax, 10
		jl ok
		cmp ebx, 10
		jle _swap
	ok :
		jmp _pr
	_swap :
		mov [esi], eax
		sub esi, 4
		mov [esi], ebx
		add esi, 4
	_pr :
		dec edx
		cmp edx, 0
		je _tr
		jmp for2
	_tr :
		loop for1
	end_of_prog :
		ret
sort_cdecl endp

sort_stdcall proc stdcall, A:dword, n:dword
		mov ecx, n
		dec ecx
		cmp ecx, 0
		je end_of_prog
	for1 :
		mov esi, A
		mov edx, ecx
	for2 :
		mov eax, [esi]
		add esi, 4
		mov ebx, [esi]
		cmp eax, 10
		jl ok
		cmp ebx, 10
		jle _swap
	ok :
		jmp _pr
	_swap :
		mov [esi], eax
		sub esi, 4
		mov [esi], ebx
		add esi, 4
	_pr :
		dec edx
		cmp edx, 0
		je _tr
		jmp for2
	_tr :
		loop for1
	end_of_prog :
		ret
sort_stdcall endp

@sort_fastcall@8 proc
	local A:dword
		mov A, edx
		dec ecx
		cmp ecx, 0
		je end_of_prog
	for1 :
		mov esi, A
		mov edx, ecx
	for2 :
		mov eax, [esi]
		add esi, 4
		mov ebx, [esi]
		cmp eax, 10
		jl ok
		cmp ebx, 10
		jle _swap
	ok :
		jmp _pr
	_swap :
		mov [esi], eax
		sub esi, 4
		mov [esi], ebx
		add esi, 4
	_pr :
		dec edx
		cmp edx, 0
		je _tr
		jmp for2
	_tr :
		loop for1
	end_of_prog :
		ret
@sort_fastcall@8 endp

end