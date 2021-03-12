		global	ft_strcmp
		section	.text

; rdi and rsi are the Arguments
; rdx is counter
; rax is value of dif and the return
; rcx is a tmp var
; for some reason rdx doesn't want to increment or gets reset or somethign
; but r8 is perfectly fine...

ft_strcmp:
			mov	rax, 0x0
			mov	rdx, 6
			mov	rcx, 0x0
			mov r8, 0
			mov	dl, 0x0
			jmp	loop

compar:
			mov	dl, BYTE[rdi + r8]
			cmp	dl, BYTE[rsi + r8]
			jne	end
			inc	r8

loop:
			cmp	BYTE[rdi + r8], 0x0
			je	end
			cmp BYTE[rsi + r8], 0x0
			je	end
			jmp	compar

end:
			mov	dl, 0x0			; This line is crucial to the math, i think dl is in rax
			movzx	rax, BYTE[rdi + r8]
			movzx	rcx, BYTE[rsi + r8]
			sub rax, rcx
			;mov rax, r8
			ret
