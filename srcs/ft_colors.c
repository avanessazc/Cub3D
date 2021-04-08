/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 12:12:09 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_colors(char *line, t_color *color, int i, int *set)
{
	int		ck;

	ck = 0;
	i = color_init_checks(line, i, color);
	if (i == -1)
		return (0);
	if (ft_strchr("0123456789", line[i]) == 1)
	{
		color->red = ft_atoi(&line[i]);
		i = advance(&line[i]) + i;
		ck = check(&line[i]);
		if (ck == -1)
			return (0);
		i = green_color(line, i, &color, ck);
		ck = check(&line[i]);
		if (ck == -1)
			return (0);
		i = blue_color(line, i, &color, ck);
		if (line[i] != '\0' && (line[i] != ' ' || line[i] != '\t'))
			return (0);
	}
	if (check_color(color) == 0)
		return (0);
	*set = 1;
	return (1);
}

void		ft_get_color_f(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont != NULL)
		{
			if (p->scene->file->cont[i] == 'F')
			{
				ft_colors(&p->scene->file->cont[i], &p->scene->floor, i + 1,
												&p->scene->settings.f);
				free(p->scene->file->cont);
				p->scene->file->cont = NULL;
			}
		}
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	p->scene->file = tmp;
	tmp = NULL;
}

void		ft_get_color_c(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont != NULL)
		{
			if (p->scene->file->cont[i] == 'C')
			{
				ft_colors(&p->scene->file->cont[i], &p->scene->ceiling, i + 1,
												&p->scene->settings.c);
				free(p->scene->file->cont);
				p->scene->file->cont = NULL;
			}
		}
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	p->scene->file = tmp;
	tmp = NULL;
}
