			global	ft_strdup
			extern	malloc
			extern	ft_strcpy
			section .text

; src is rdi and ret is rax

ft_strdup:
			mov rax, 0x0
			mov	r8, 0x0
			cmp rdi, 0x0
			je	end
			cmp	BYTE[rdi], 0x0
			jz	empty

count:
			cmp BYTE[rdi + r8], 0x0
			je	allocate
			inc	r8
			jmp	count

allocate:
			inc		r8
			push	rdi
			mov		rdi, r8
			call	malloc WRT ..plt
			cmp		rax, 0x0
			je		end

fill:
			pop		rsi
			mov		rdi, rax
			call	ft_strcpy		; rdi is dst and rsi is src
			jmp		end

empty:
			mov		rdi, 0x1
			call	malloc WRT ..plt
			cmp		rax, 0x0
			jz		end
			mov		BYTE[rax], 0x0

end:
			ret
