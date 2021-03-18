			global	ft_read
			extern	__errno_location
			section	.text

; rdi is fd, rsi is buf, rdx is read len
; there are all pre loaded so no need to mess with them.
; we neg rax because the return from a bad syscall is negative
; but the errnos are positive.

ft_read:
			mov		rax, 0x0
			syscall
			cmp		rax, 0x0
			jl		error
			ret

error:
			neg		rax
			push	rax
			pop		r8
			call	__errno_location WRT ..plt
			mov		[rax], r8
			mov		rax, -1
			ret
