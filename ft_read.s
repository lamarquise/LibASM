			section	.code
			global	ft_read

; do i need to/how would I deal with errno locations...?

ft_read:
			mov		rax, 0
			syscall
			ret
