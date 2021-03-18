		global	ft_strcmp
		section	.text

; rdi and rsi are the Arguments
; rax is value of dif and the return
; rcx is a tmp var
; r8 works as a counter but rdx acts up
; dl works as comparison var but have to zero it out at start of end otherwise
; affects rax value, al works just fine

ft_strcmp:
			mov	rax, 0x0
			mov	rcx, 0x0
			mov r8, 0x0
			mov	al, 0x0
			jmp	loop

compar:
			mov	al, BYTE[rdi + r8]
			cmp	al, BYTE[rsi + r8]
			jne	end
			inc	r8

loop:
			cmp	BYTE[rdi + r8], 0x0
			je	end
			cmp BYTE[rsi + r8], 0x0
			je	end
			jmp	compar

end:
			movzx	rax, BYTE[rdi + r8]
			movzx	rcx, BYTE[rsi + r8]
			sub		rax, rcx
			ret
