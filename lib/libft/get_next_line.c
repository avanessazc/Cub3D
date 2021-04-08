/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:02:39 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/03 09:08:36 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strdel(char **str, int ret)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}

static int		ft_get_line(char **line, char **dest)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*dest)[len] != '\0' && (*dest)[len] != '\n')
		len++;
	if ((*dest)[len] == '\n')
	{
		*line = ft_substr_gnl(*dest, 0, len);
		tmp = ft_strdup_gnl(&(*dest)[len + 1]);
		free(*dest);
		*dest = tmp;
		tmp = NULL;
	}
	else
	{
		*line = ft_strdup_gnl(*dest);
		return (ft_strdel(dest, 0));
	}
	return (1);
}

static int		ft_return_value(int r, char **dest, char **line)
{
	if (r < 0)
		return (ft_strdel(dest, -1));
	if (r == 0 && (*dest == NULL || dest == '\0'))
	{
		if (!(*line = (char *)malloc(sizeof(char))))
			return (0);
		*line[0] = '\0';
		return (ft_strdel(dest, 0));
	}
	return (ft_get_line(line, dest));
}

int				get_next_line(int fd, char **line, int flag)
{
	int				r;
	char			*buf;
	char			*tmp;
	static char		*dest;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || flag == 1)
		return (ft_strdel(&dest, -1));
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ft_strdel(&dest, -1));
	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (!(tmp = ft_strjoin_gnl(dest, buf, r)))
			return (ft_strdel(&dest, -1));
		ft_strdel(&dest, 0);
		dest = tmp;
		tmp = NULL;
		if (ft_strchr_gnl(dest, '\n') != -1)
			break ;
	}
	free(buf);
	return (ft_return_value(r, &dest, line));
}
