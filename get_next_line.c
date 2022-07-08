/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:17:04 by sphh              #+#    #+#             */
/*   Updated: 2022/07/08 00:20:09 by sphh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const	*s2);


	BUFFER_SIZE=16;

char	*get_next_line(int	fd)
{
	static char		*temp;
	char		*buf;
	static char	*rest;

	buf = calloc(sizeof(char) * BUFFER_SIZE + 1, 1);
	temp = "$";

	while (!ft_strchr(buf, '\n'))
	{
		temp = ft_strjoin(temp, buf);
		read(fd, buf, BUFFER_SIZE);
	}
	temp = ft_strjoin(temp, "\n");
	rest = buf;
	free(buf);
	return (temp);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("./file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

