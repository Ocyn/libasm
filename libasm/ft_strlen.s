section	.text
global	ft_strlen

ft_strlen:
	xor	rax, rax ; set rax to 0
.loop:
	cmp	byte [rdi+rax], 0 ;check if char equal 0
	je	.end
	inc	rax
	jmp .loop

.end:
	ret
