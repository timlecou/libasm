section .text
	global	ft_strdup
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

ft_strdup:
	cmp	rdi,	0
	je	exit
	call	ft_strlen
	inc	rax
	push	rdi
	mov	rdi,	rax
	call	malloc
	cmp	rax,	0
	je	exit
	mov	rdi,	rax
	pop	rsi
	call	ft_strcpy
	jmp	exit

exit:
	ret
