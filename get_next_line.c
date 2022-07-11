/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:17:04 by sphh              #+#    #+#             */
/*   Updated: 2022/07/11 18:37:18 by vipereir         ###   ########.fr       */
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
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t       count, size_t   size);

char	*get_next_line(int	fd)
{
	static char	*rest;
	char		*buf;
	char		*str;
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buf = ft_calloc(sizeof(char) * BUFFER_SIZE + 1, 1);
	eof = 1;
	while (eof)
	{
		eof = read(fd, buf, BUFFER_SIZE);
		if (!eof && !rest)
			return (NULL);
		if (rest)
		{
			str = ft_strdup(rest);
			rest = NULL;
		}
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			rest = ft_strchr(str, '\n');
			rest++;
			free(buf);
			return (ft_substr(str, 0, ft_strlen_brkl(str) + 1));
		}
	}
	return(NULL);
}

/*
int	main(void)
{
	int	fd;
	char	*str;

	fd = open("./file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
