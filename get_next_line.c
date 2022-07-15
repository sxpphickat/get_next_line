/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:17:04 by sphh              #+#    #+#             */
/*   Updated: 2022/07/15 11:08:37 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const	*s2);
char	*ft_strdup(const char	*s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const	*s, unsigned int start, size_t len);



char	*ft_rest(char *temp)
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
	while(!ft_strchr(str, '\n') && eof > 0)
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

char	*get_next_line(int	fd)
{
	static char	*rest;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	str = ft_line(fd, rest);
	rest = ft_rest(str);
	str = ft_cute(str);
	return (str);
}

/*
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
}*/
