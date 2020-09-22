segment .text
	global ft_strlen

ft_strlen:
	mov	rax,	0
	jmp	looplen

looplen:
	cmp	byte [rdi + rax],	0
	je	exit
	inc	rax
	jmp	looplen

exit:
	ret
