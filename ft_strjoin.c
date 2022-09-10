/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:08:30 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/10 06:36:52 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
