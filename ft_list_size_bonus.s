		global	ft_list_size
		section	.text

; rax will be the number of elements in the list to return
; rdi is the pointer to the list
; rdi + 8 is the pointer to the next elem, because the first
; var in the struct is void, which is 8 bytes

ft_list_size:
				mov	rax, 0x0

count:
				cmp	rdi, 0x0
				jz	end
				inc rax

step:
				mov	rdi, [rdi + 8]
				jmp	count

end:
				ret
