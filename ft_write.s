			section	.code
			global	ft_write

; int fd, const void *buf, size_t count
; rdi, rsi, rdx
; use syscall and the syscall code for write is 1

; can it really be this simple?

; do i need to / how would I deal with errno locations...?

ft_write:
			mov		rax, 1
			syscall
			ret
