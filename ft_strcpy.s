segment .text
	global	ft_strcpy

ft_strcpy:
	mov	rcx, 	0
	cmp	rdi, 	0
	je	exit
	cmp	rsi,	0
	je	exit
	jmp	loopcpy

loopcpy:
	mov	dl,	[rsi + rcx]
	mov	[rdi + rcx],	dl
	cmp	byte [rsi + rcx],	0
	je	exit
	inc	rcx
	jmp	loopcpy

exit:
	ret
