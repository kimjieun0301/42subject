/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:38:58 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/10 06:34:33 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			c;
	unsigned char	*str;

	c = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (str == 0)
		return (0);
	if ((start + len) <= ft_strlen((char *)s))
	{
		while (c < len)
		{
			str[c] = s[start + c];
			c++;
		}
	}
	else
	{
		while (start + c < ft_strlen((char *)s))
		{
			str[c] = s[start + c];
			c++;
		}
	}
	str[c] = '\0';
	return ((char *)str);
}
