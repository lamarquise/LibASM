			global	ft_write
			extern	__errno_location
			section	.text

; int fd, const void *buf, size_t count
; rdi, rsi, rdx
; use syscall and the syscall code for write is 1

; can it really be this simple?
; do i need to / how would I deal with errno locations...?

; Our logic
; we make sure errno location set to 0. May be unncessary
; we call write
; we take the restult of write and put it in the errno location if
;  something went wrong.

ft_write:
			mov	rax, 1
			syscall
			cmp	rax, 0
			jl	error		; jump if less, as in < 0
			ret

error:
			neg		rax
			mov		r8, rax
			;push	rax
			;pop		r8
			call	__errno_location WRT ..plt	;wrt..pl avoids overflow in R_X86_64_PC32 relocation
			mov		[rax], r8
			mov 	rax, -1
			ret
