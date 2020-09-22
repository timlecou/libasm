segment .text
	global ft_strcmp

ft_strcmp:
	mov	rax,	0
	cmp	rdi,	0
	je	exit
	cmp	rsi,	0
	je	exit
	jmp	loopcmp

loopcmp:
	mov	al,	byte [rdi]
	mov	bl,	byte [rsi]
	cmp	al,	0
	je	exit
	cmp	bl,	0
	je	exit
	cmp	al,	bl
	jne	exit
	inc	rdi
	inc	rsi
	jmp	loopcmp

exit:
	movzx	rax,	al
	movzx	rbx,	bl
	sub	rax,	rbx
	ret
