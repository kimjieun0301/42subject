/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:01:29 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/10 08:30:50 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*str;
	int				count;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (*s1 == 0)
		return ((char *)s1);
	if (s1 == 0 || set == 0)
		return (0);
	count = ft_strlen((char *)s1);
	while (*(s1 + j) && ft_strchr(set, *(s1 + j)))
		j++;
	while (*(s1 + count - 1 - i) && ft_strchr(set,
			*(s1 + count - 1 - i)) && (count - 1) > j)
		i++;
	str = (unsigned char *)malloc(sizeof(unsigned char) * (count + 1 - i - j));
	if (str == 0)
		return (0);
	ft_strlcpy((char *)str, (char *)(s1 + j), count + 1 - i - j);
	return ((char *)str);
}
