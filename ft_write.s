			global	ft_write
			extern	__errno_location
			section	.text

; int fd, const void *buf, size_t count
; rdi, rsi, rdx
; syscall code for write is 1
; WRT ..pl avoids overflow in R_X86_64_PC32 relocation
; jl: jump if less, as in < 0

ft_write:
			mov	rax, 1
			syscall
			cmp	rax, 0
			jl	error
			ret

error:
			neg		rax
			mov		r8, rax
			;push	rax
			;pop		r8
			call	__errno_location WRT ..plt
			mov		[rax], r8
			mov 	rax, -1
			ret
