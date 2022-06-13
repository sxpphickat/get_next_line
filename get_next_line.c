/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:09:32 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/13 15:52:49 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	void	*buf[42];
	static	int		i;
	static	char	*temp;

	temp = 
	read(fd, buf, BUFFER_SIZE);
	while ((char)buf[i] != '\n' && buf[i])
		i++;

	return ((char *)buf + i);
}


#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("../../fck.txt", O_RDONLY);
	printf("%i\n", fd);
	printf("-------------\n");
	printf("%s\n", get_next_line(fd));
	printf("-------------\n");
	printf("%s\n", get_next_line(fd));
	printf("-------------\n");
	printf("%s\n", get_next_line(fd));
	printf("-------------\n");
	printf("%s\n", get_next_line(fd));
	get_next_line(fd);
}
