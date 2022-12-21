/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:38:43 by jkim3             #+#    #+#             */
/*   Updated: 2022/12/21 19:54:25 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	count = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == 0)
		return (0);
	while (*s1)
	{
		*(str + i) = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		*(str + i) = *s2;
		s2++;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

static void	ftft_substr(char const *s, unsigned int \
start, size_t c, unsigned char *str)
{
	str[c] = s[start + c];
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			c;
	size_t			n;
	unsigned char	*str;

	c = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (str == 0)
		return (0);
	n = ft_strlen((char *)s);
	if ((start + len) <= n)
	{
		while (c < len)
			ftft_substr(s, start, c++, str);
	}
	else
	{
		while (start + c < n)
			ftft_substr(s, start, c++, str);
	}
	str[c] = '\0';
	return ((char *)str);
}
