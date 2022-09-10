/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:50:13 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/10 09:04:05 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	j;
	size_t	a;
	size_t	b;

	j = ft_strlen((char *)src);
	a = 0;
	b = ft_strlen((char *)dest);
	if (b <= size)
	{
		while (*(src + a) && (size > (a + b + 1)))
		{
			*(dest + b + a) = *(src + a);
			a++;
		}
		*(dest + b + a) = '\0';
		return (b + j);
	}
	return (size + j);
}
