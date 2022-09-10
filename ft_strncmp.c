/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:50:49 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/09 22:11:44 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	a;
	unsigned char	b;
	size_t			i;

	i = 0;
	while ((*s1 || *s2) && (i < n))
	{
		a = (unsigned char)*s1;
		b = (unsigned char)*s2;
		if (a != b)
		{
			return (a - b);
		}
		i++;
		s1++;
		s2++;
	}
	return (0);
}
