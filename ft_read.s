segment .text
	global	_ft_read

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc		exit_error
	jmp		exit

exit_error:
	mov		rax, -1
	ret

exit:
	ret
