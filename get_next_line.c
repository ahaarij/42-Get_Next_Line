/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:45:00 by ahaarij           #+#    #+#             */
/*   Updated: 2023/12/29 09:41:17 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	line_end(char *str, size_t i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*string(char *s1)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1[i] == '\0')
		return (free(s1), NULL);
	i = line_end(s1, i);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) - i + 1));
	if (!str)
		return (free(str), NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if (!str[0])
		return (free(s1), free(str), NULL);
	free (s1);
	return (str);
}

char	*readline(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	i = line_end(str, i);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*freebuff(char *buffer1, char *buffer2)
{
	free (buffer1);
	free (buffer2);
	buffer2 = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*content;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && bytes != 0)
	{
		bytes = read(fd, content, BUFFER_SIZE);
		if (bytes == -1)
		{
			buffer = freebuff(content, buffer);
			return (NULL);
		}
		content[bytes] = '\0';
		buffer = ft_strjoin(buffer, content);
	}
	free (content);
	content = readline(buffer);
	buffer = string(buffer);
	return (content);
}
