section .text
global	ft_strcmp

ft_strcmp:
	xor	rax, rax ; set rax to 0
.loop:
	mov dl, [rsi+rax]
	mov r8b, [rdi+rax]
	cmp	byte [rsi+rax], 0 ;check if char equal 0
	je	.end
	cmp r8b, dl
	jne	.diff
	inc	rax
	jmp .loop

.diff:
	movzx rdx, dl
	movzx rax, r8b
	sub rax, rdx
	ret

.end:
	cmp r8b, dl
	jne .diff
	mov rax, 0
	ret