			section .text
			global	ft_strlen

ft_strlen:
			mov		rax, 0
			jmp		loop
incr:
			inc		rax
loop:
			cmp		BYTE [rdi + rax], 0
			jne		incr
end:
			ret
