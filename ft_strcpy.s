		global ft_strcpy
		section .text

; rdi is dst rsi is src
; al is the first 8 bit memory location

ft_strcpy:
		mov		rax, 0x0
		mov		rdx, 0x0
		cmp		rsi, 0x0
		jz		end
		jmp		loop

incr:
		mov		al, BYTE[rsi + rdx]
		mov		BYTE[rdi + rdx], al
		inc		rdx

loop:
		cmp		BYTE[rsi + rdx], 0x0
		jne		incr

end:
		mov		BYTE[rdi + rdx], 0x0
		mov		rax, rdi
		ret
