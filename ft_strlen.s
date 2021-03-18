			global	ft_strlen
			section .text

ft_strlen:
			mov		rax, 0x0
			jmp		loop
incr:
			inc		rax
loop:
			cmp		BYTE [rdi + rax], 0x0
			jne		incr
end:
			ret
