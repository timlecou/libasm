/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:52:26 by timlecou          #+#    #+#             */
/*   Updated: 2020/07/12 12:01:56 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *s, int len);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
#endif
