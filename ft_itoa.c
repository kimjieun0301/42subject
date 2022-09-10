/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:24:08 by jkim3             #+#    #+#             */
/*   Updated: 2022/09/10 05:44:22 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*change_char(int i, long long num, long long j)
{
	char	*c;
	int		k;

	k = 0;
	c = malloc(sizeof(char) * (i + 2));
	if (!c)
		return (0);
	if (num < 0)
	{
		c[0] = '-';
		num *= -1;
		k = 1;
	}
	while (i--)
	{
		j /= 10;
		*(c + k) = (num / j) + 48;
		num %= j;
		k++;
	}
	if (k == 0)
		c[k++] = 48;
	c[k] = '\0';
	return (c);
	free (c);
}

char	*ft_itoa(int n)
{
	char		*c;
	int			i;
	long long	j;
	long long	num;

	i = 0;
	j = 1;
	num = (long long)n;
	while (n != 0)
	{
		n /= 10;
		i++;
		j *= 10;
	}
	c = malloc(sizeof(char) * (i + 2));
	if (!c)
		return (0);
	else
		c = change_char(i, num, j);
	return (c);
}
