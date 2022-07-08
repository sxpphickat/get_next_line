/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:17:04 by sphh              #+#    #+#             */
/*   Updated: 2022/07/08 16:21:16 by vipereir         ###   ########.fr       */
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


	BUFFER_SIZE=4;

char	*get_next_line(int	fd)
{
	static char	*rest;
	char		*buf;
	char		*str;

	buf = calloc(sizeof(char) * BUFFER_SIZE + 1, 1);
	read(fd, buf, BUFFER_SIZE);
	str = ft_strdup(buf);

	while (!ft_strchr(buf, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
		str = ft_strjoin(str, buf);
	}
	str = ft_substr(str, 0, ft_strlen_brkl(str));
	str = ft_strjoin(str, "\n");
	rest = ft_strchr(buf, '\n');
	return (str);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("./file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

