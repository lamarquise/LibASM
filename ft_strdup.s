			global	ft_strdup
			extern	malloc
			extern	ft_strcpy
			section .text

; so what do we want. we want to go through rdi and copy it to rax which has been malloced
; returns a char* takes a char*, so s1 is rdi and ret is rax
; we need to count the len of rdi
; then allocate that many bytes
; then fill it with the correct bytes
; then return them in rax

; What are the inputs for Malloc?
;	I'm guessing rax for the mem location and rdi for the number

ft_strdup:
			mov rax, 0x0
			mov	r8, 0x0
			cmp	BYTE[rdi], 0x0
			je	end
	; could have a special function here that allocates an empty string.

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
			cmp		rax, 0
			je		end

fill:		; at this point rax is the new string location and has been allocated
			pop		rsi
			mov		rdi, rax
			call	ft_strcpy		; rdi is dst and rsi is src

end:
			ret









