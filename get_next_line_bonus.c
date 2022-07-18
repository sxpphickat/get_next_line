/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:46 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/18 16:26:49 by vipereir         ###   ########.fr       */
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
	int		count;

	count = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!str)
		str = ft_strdup("\0");
	while (!(ft_strchr(str, '\n')) && count > 0)
	{
		count = read (fd, buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[count] = '\0';
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
	static char	*rest[4096];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_line(fd, rest[fd]);
	if (!str)
		return (NULL);
	rest[fd] = ft_rest(str);
	str = ft_cute(str);
	return (str);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd;
	int	fd2;
	// tinha uma variavel maldita nao usada aqui O-o
	fd = open("./file.txt", O_RDWR);
	fd2 = open("./file2.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	//printf("%s", get_next_line(fd));
	close(fd);
	close(fd2);
}*/
