
global	ft_strlen

.error:
	ret


ft_strlen:
	xor	rax, rax ; set rax to 0
	test	rdi, rdi ; check if string is not empty
	jz	.error
	.loop:
		cmp	[rdi+rax], 0 ;check if char equal 0
		inc	rax
		je	.end
		jump .loop
	.end
		ret
	
