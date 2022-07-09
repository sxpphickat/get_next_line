/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:17:04 by sphh              #+#    #+#             */
/*   Updated: 2022/07/09 12:15:49 by sphh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const	*s2);
char	*ft_strdup(const char	*s1);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
size_t	ft_strlen_brkl(const char *s);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t       count, size_t   size);
int	ft_find_eof(const char *s, int   n);

//BUFFER_SIZE=42;

char	*get_next_line(int	fd)
{
	static char	*rest;
	char		*buf;
	char		*str;

	if (BUFFER_SIZE <= 0)
		return (0);
	buf = ft_calloc(sizeof(char) * BUFFER_SIZE + 1, 1);
	read(fd, buf, BUFFER_SIZE);
	str = ft_strdup(buf);
	while (!ft_strchr(buf, '\n') && !ft_find_eof(buf, BUFFER_SIZE))
	{
		read(fd, buf, BUFFER_SIZE);
		str = ft_strjoin(str, buf);
	}
	if (rest)
		str = ft_strjoin(rest, str);
	str = ft_substr(str, 0, ft_strlen_brkl(str) + 1);
	rest = ft_strchr(buf, '\n');
	rest++;
	return (str);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("./file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

