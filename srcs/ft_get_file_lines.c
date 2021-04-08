/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:26:12 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/31 14:36:57 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_map_line(t_param *p, char *line, int i)
{
	int		t;

	t = i;
	while (ft_strchr("012NSWE ", line[t]) == 1 && line[t] != '\0')
		t++;
	if (line[t] == '\0')
	{
		p->scene->settings.sm = 1;
		return (check_add_elem_file(p, line, 0));
	}
	else
	{
		ft_lstclear_file(&p->scene->file);
		return (3);
	}
	return (1);
}

int		get_parameter(t_param *p, char *line, int i, int *set)
{
	*set = 0;
	return (check_add_elem_file(p, line, i));
}

int		beginning_of_the_map(t_param *p, char *line, int i)
{
	if (checked_settings(&p->scene->settings) == 1)
		return (check_map_line(p, line, i));
	else
		return (check_empty_line(p, line));
}

int		check_settings(t_param *p, char *line, int i)
{
	if (line[i] == 'R' && p->scene->settings.r == -1)
		return (get_parameter(p, line, i, &p->scene->settings.r));
	else if (line[i] == 'N' && line[i + 1] == 'O'
											&& p->scene->settings.no == -1)
		return (get_parameter(p, line, i, &p->scene->settings.no));
	else if (line[i] == 'S' && line[i + 1] == 'O'
											&& p->scene->settings.so == -1)
		return (get_parameter(p, line, i, &p->scene->settings.so));
	else if (line[i] == 'E' && line[i + 1] == 'A'
											&& p->scene->settings.ea == -1)
		return (get_parameter(p, line, i, &p->scene->settings.ea));
	else if (line[i] == 'W' && line[i + 1] == 'E'
											&& p->scene->settings.we == -1)
		return (get_parameter(p, line, i, &p->scene->settings.we));
	else if (line[i] == 'S' && p->scene->settings.s == -1)
		return (get_parameter(p, line, i, &p->scene->settings.s));
	else if (line[i] == 'F' && p->scene->settings.f == -1)
		return (get_parameter(p, line, i, &p->scene->settings.f));
	else if (line[i] == 'C' && p->scene->settings.c == -1)
		return (get_parameter(p, line, i, &p->scene->settings.c));
	else if (ft_strchr("012", line[i]) == 1)
		return (beginning_of_the_map(p, line, i));
	else
		return (check_empty_line(p, line));
}

int		ft_get_file_lines(t_param *p, char *line)
{
	int		i;

	i = ft_isspace(line, 0);
	if (line[0] == '\0' && p->scene->settings.sm == 1)
		p->scene->settings.el = 1;
	else if (p->scene->settings.sm == 1 && ft_valid_empty_line(p, line) == 1)
		p->scene->settings.el = 1;
	else if (p->scene->settings.sm == 0)
		return (check_settings(p, line, i));
	else if (p->scene->settings.sm == 1 && p->scene->settings.el == 0)
		return (check_map_line(p, line, i));
	else if (p->scene->settings.sm == 1 && p->scene->settings.el == 1)
		return (check_empty_line(p, line));
	return (1);
}
