/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sphh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:48:37 by sphh              #+#    #+#             */
/*   Updated: 2022/07/12 14:26:59 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
char	*ft_strdup(const char	*s1);

void    ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] )
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen_brkl(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\n' && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const	*s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char	*s1)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char *)malloc(sizeof(*string) * (ft_strlen(s1) + 1));
	if (string == NULL)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(len * sizeof(*str) + 1);
	if (str == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str[i] = '\0';
		return (str);
	}
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void    *ft_calloc(size_t       count, size_t   size)
{
        void    *vp;

        if (size == 0 || count == 0)
        {
                count = 1;
                size = count;
        }
        vp = malloc(count * size);
        if (vp == NULL)
                return (NULL);
        ft_bzero(vp, count * size);
        return (vp);
}

void    ft_bzero(void *s, size_t n)
{
        size_t  i;
        char    *tempchar;

        i = 0;
        tempchar = (char *)s;
        while (i < n)
        {
                tempchar[i] = '\0';
                i++;
        }
}
