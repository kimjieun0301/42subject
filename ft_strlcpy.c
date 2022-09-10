/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:41:03 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/09 22:11:21 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	count;
	size_t	num;

	num = 0;
	count = 0;
	while (*(src + count))
	{
		count++;
	}
	if (!size)
		return (count);
	while ((num + 1 < size) && *(src + num))
	{
		*(dest + num) = *(src + num);
		num++;
	}
	dest[num] = '\0';
	return (count);
}
