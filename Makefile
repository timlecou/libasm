# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timlecou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 22:31:51 by timlecou          #+#    #+#              #
#    Updated: 2020/07/12 12:07:58 by timlecou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_read.s ft_write.s ft_strdup.s

OBJS = $(SRCS:.s=.o)

.s.o : $(SRCS)
	nasm -f elf64 $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)


clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	rm a.out

re : fclean all

test : all
	gcc main.c $(NAME)
	./a.out
