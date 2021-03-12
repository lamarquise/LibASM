			global	ft_read
			extern	__errno_location
			section	.text

ft_read:
			mov		rax, 0
			syscall
			cmp	rax, 0
			jl	error
			ret

error:
			neg	rax
			push	rax
			pop		r8
			;mov	r8, rax
			call	__errno_location WRT ..plt
			mov	[rax], r8
			mov	rax, -1
			ret
