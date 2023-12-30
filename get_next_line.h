/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:10:45 by ahaarij           #+#    #+#             */
/*   Updated: 2023/12/22 17:22:16 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	line_end(char *str, size_t i);
char	*string(char *s1);
char	*readline(char *str);
char	*freebuff(char *buffer1, char *buffer2);
char	*get_next_line(int fd);

#endif