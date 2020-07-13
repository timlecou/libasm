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

SRCS = ft_strlen.s ft_strcmp.s ft_write.s ft_read.s\
	   ft_strdup.s ft_strcpy.s

OBJ = $(SRCS:.s=.o)

%.o	: %.s
	nasm -f macho64 $< -o $@

CC = nasm

FLAGS = -f macho64

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f a.out

re: clean all

.PHONY: fclean, all
