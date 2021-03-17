		global	ft_list_push_front
		extern	malloc
		section	.text

; rdi is **begin_list and rsi is *data

ft_list_push_front:
				cmp		rdi, 0x0
				jz		end
				cmp		rsi, 0x0
				jz		end
				push	rdi
				push	rsi

allocate:
				mov		rdi, 16		; the size of the malloc is 16 cuz 2 var
				call	malloc WRT ..plt
				cmp		rax, 0x0
				jz		end

fill:
				pop		rsi
				pop		rdi
				mov		[rax], rsi
				mov		r8, [rdi]	; brackets cuz its a double pointer
				mov		[rax + 8], r8
				mov		[rdi], rax

end:
				ret
