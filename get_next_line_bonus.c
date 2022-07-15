/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:17:04 by sphh              #+#    #+#             */
/*   Updated: 2022/07/15 13:53:59 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rest(char	*temp)
{
	char	*rest;

	if (*temp == '\0')
		return (NULL);
	if (!ft_strchr(temp, '\n'))
		rest = ft_strdup("\0");
	else
		rest = ft_strdup(ft_strchr(temp, '\n') + 1);
	return (rest);
}

char	*ft_line(int fd, char *str)
{
	char	*buffer;
	int		eof;

	eof = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!str)
		str = ft_strdup("\0");
	while (!ft_strchr(str, '\n') && eof > 0 && fd >= 0)
	{
		eof = read (fd, buffer, BUFFER_SIZE);
		buffer[eof] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_cute(char	*cute)
{
	int		len;
	char	*cutted;

	len = 0;
	if (!cute)
		return (NULL);
	if (cute[0] == '\0')
	{
		free(cute);
		return (NULL);
	}
	while (cute[len] && cute[len] != '\n')
		len++;
	if (cute[len] == '\n')
		len++;
	cutted = ft_substr(cute, 0, len);
	free(cute);
	return (cutted);
}


char	*get_next_line(int fd)
{
	static char	*rest[4096] = {0};
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = ft_line(fd, rest[fd]);
	if (!rest[fd])
		return(NULL);
	str = ft_cute(rest[fd]);
	rest[fd] = ft_rest(rest[fd]);
	return (str);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	// tinha uma variavel maldita nao usada aqui O-o
	fd = open("./file.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	close(fd);
}*/
