section .text
global ft_strcpy

ft_strcpy:
	xor	rax, rax ; set rax to 0
.loop:
	mov dl, [rsi+rax]
	mov [rdi+rax], dl
	cmp	byte [rsi+rax], 0 ;check if char equal 0
	je	.end
	inc	rax
	jmp .loop

.end:
	mov rax, rdi
	ret