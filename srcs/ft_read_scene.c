/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:18:51 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 10:32:26 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	end_of_reading(int fd, t_param *p, int ret, char **line)
{
	int		r;

	r = 1;
	if (ret == -1)
	{
		if (*line)
			free(*line);
		get_next_line(fd, line, 1);
		return (-3);
	}
	if ((r = ft_get_file_lines(p, *line)) != 1)
	{
		if (*line)
			free(*line);
		get_next_line(fd, line, 1);
		return (r);
	}
	if (*line)
		free(*line);
	return (r);
}

int			ft_read_scene(int fd, t_param *p, int ret)
{
	char	*line;
	int		r;

	while ((ret = get_next_line(fd, &line, 0)) > 0)
	{
		if (line[0] == '\0' && p->scene->settings.sm == 0)
		{
			free(line);
			continue;
		}
		if (p->scene->settings.sm == 0 && ft_valid_empty_line(p, line) == 1)
		{
			free(line);
			continue;
		}
		if ((r = ft_get_file_lines(p, line)) != 1)
		{
			free(line);
			get_next_line(fd, &line, 1);
			return (r);
		}
		free(line);
	}
	r = end_of_reading(fd, p, ret, &line);
	return (r);
}
