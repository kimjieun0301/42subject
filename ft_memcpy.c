/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:47:57 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/09 19:12:48 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t num)
{
	size_t		i;
	char		*tmp;
	const char	*s;

	i = 0;
	tmp = dst;
	s = src;
	if (!dst && !src)
		return (0);
	while (i < num)
	{
		tmp[i] = s[i];
		i++;
	}
	return (dst);
}
