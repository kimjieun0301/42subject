/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:38:34 by jkim3             #+#    #+#             */
/*   Updated: 2022/12/21 19:59:44 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	frenul(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

static char	*malloc_save(void)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char));
	if (!ptr)
		return (0);
	ptr[0] = '\0';
	return (ptr);
}

static char	*l_read(int fd, char *buf, char *save)
{
	int		num;
	char	*ptr;

	while (1)
	{
		num = read(fd, buf, BUFFER_SIZE);
		if (num == -1)
			return (0);
		else if (num == 0)
			break ;
		buf[num] = '\0';
		if (!save)
			save = malloc_save();
		if (save)
		{
			ptr = save;
			save = ft_strjoin(ptr, buf);
		}
		if (!save)
			return (0);
		frenul(ptr);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save);
}

static char	*l_save(char *line)
{
	int		i;
	char	*save;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (!line[i])
		return (0);
	save = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!save)
		return (0);
	if (!save[0])
	{
		frenul(save);
		return (0);
	}
	line[i + 1] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	line = l_read(fd, buf, save);
	frenul(buf);
	if (!line)
		return (NULL);
	save = l_save(line);
	return (line);
}
