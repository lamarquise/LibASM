		section	.text
		global	ft_strcmp

; rdi and rsi
; rdx is counter
; rax is value of dif and the return
; why r8, would something else work?

; New Logic:
; we set everything, counters and such to 0
; we compare until diference
; we make rax the dif.


ft_strcmp:
			mov	rax, 0
			mov	rdx, 0
			mov	r8, 0
			jmp	loop

cmp:
			mov	rax, [rdi + rdx]	; if use byte before, it gets upset
			mov r8, [rsi + rdx]		; "missmaching operand size"
			sub	rax, r8
		;	cmp	rax, r8
			jne	end
			inc	rdx

loop:
			cmp	byte [rdi + rdx], 0
			je	end
			cmp byte [rsi + rdx], 0
			je	end
			jmp	cmp

end:
			;mov	rax, [rdi + rdx]	; if use byte before, it gets upset
			;mov r8, [rsi + rdx]		; "missmaching operand size
			;sub r8, rax
			ret

