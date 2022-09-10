/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:23:48 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/03 22:40:42 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset_c(char const a, char c)
{
	if (c != '\0')
	{
		if (a == c)
			return (1);
	}
	return (0);
}

static char	*f_strdup(char const *src, char c1)
{
	char	*c;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != '\0' && charset_c(src[len], c1) == 0)
		len++;
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (0);
	while (i < len)
	{
		c[i] = (char)src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static int	word_c(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && charset_c(str[i], c) == 1)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && charset_c(str[i], c) == 0)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	int			count;
	char const	**word;

	i = 0;
	j = 0;
	count = word_c(s, c);
	word = malloc(sizeof(char *) * (count + 1));
	if (!word)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && charset_c(s[i], c) == 1)
			i++;
		if (s[i] != '\0')
		{
			word[j] = (char const *)f_strdup(&s[i], c);
			j++;
		}
		while (s[i] != '\0' && charset_c(s[i], c) == 0)
			i++;
	}
	word[j] = 0;
	return ((char **)word);
}
