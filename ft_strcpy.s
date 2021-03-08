		section .text
		global ft_strcpy

; rdi is dst rsi is src
; al is the first 8 bit memory location

ft_strcpy:
		mov		rdx, 0
		cmp		rsi, 0
		jz		end
		jmp		loop
incr:
		mov		al, byte [rsi + rdx]	; does it work if i don't use al?
		mov		byte [rdi + rdx], al
		inc		rdx
loop:
		cmp		byte [rsi + rdx], 0
		jne		incr
end:
		mov		rax, rdi
		ret
