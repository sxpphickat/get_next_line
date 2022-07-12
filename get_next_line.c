/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:17:04 by sphh              #+#    #+#             */
/*   Updated: 2022/07/12 14:25:22 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

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
	char		*temp;
	int			eof;
	int			check;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buf = ft_calloc(sizeof(char) * BUFFER_SIZE + 1, 1);
	eof = 1;
	str = ft_strdup("");
	while (eof > 0)
	{
		check = eof;
		eof = read(fd, buf, BUFFER_SIZE);
		if (eof < check)
			buf = ft_substr(buf, 0, eof);
		if (!eof && !rest)
		{
			free(buf);
			if(str)
			{
				str = ft_strjoin(str, "\n");
				return(str);
			}
			free(str);
			return (NULL);
		}
		if (rest)
		{
			str = ft_strdup(rest);
			rest = NULL;
		}
		if (!str)
		{
			str = ft_strdup(buf);
		}
		else
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strjoin(temp, buf);
			free(temp);
		}
		if (ft_strchr(str, '\n'))
		{
			rest = ft_strchr(str, '\n');
			rest++;
			free(buf);
			temp = ft_strdup(str);
			str = ft_substr(temp, 0, ft_strlen_brkl(temp) + 1);
			return (str);
		}
	}
	if(str)
	{
		str = ft_strjoin(str, "\n");
		return(str);
	}
	return(NULL);
}



int	main(void)
{
	int	fd;
	// tinha uma variavel maldita nao usada aqui O-o 

	fd = open("./file.txt", O_RDWR);
	//write(fd, "minecraft\n", 10);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
