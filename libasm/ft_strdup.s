section .text
global ft_strdup
extern malloc
extern __errno_location
extern ft_strlen
extern ft_strcpy

ft_strdup:
	xor rax, rax
	call ft_strlen
	push rdi ; save string in stack
	mov rdi, rax ; copy strlen return in rdi (1st argument)
	inc rdi
	call malloc
	cmp rax, 0
	je .error
	jmp .cpy
	
.cpy:
	mov rdi, rax
	pop rsi ; restore string from stack to rdi
	call ft_strcpy
	jmp .end

.error:
	; errno already set by malloc
	mov rax, 0
	ret

.end:
	ret