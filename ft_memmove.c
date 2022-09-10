/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:14:40 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/09 19:33:48 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*str;
	size_t			i;

	tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	if ((!dst && !src))
		return (dst);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			tmp[i] = str[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			tmp[len - i - 1] = str[len - i - 1];
			i++;
		}
	}
	return (dst);
}
