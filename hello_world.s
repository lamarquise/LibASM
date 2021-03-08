		section	.text
		global	hello_world

hello_world:
				mov		rax, 1	;Syscall #
				mov		rdi, 1	;set stdout to 1
				mov		rsi, message
				mov		rdx, message_len
				syscall
				ret

		section	.data

.data:
				message: db "Hello World!", 0xA
				message_len equ $-message
