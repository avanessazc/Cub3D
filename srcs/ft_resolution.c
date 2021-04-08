/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 12:08:59 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	getting_resolution(int *resol, int i, char *line)
{
	*resol = ft_atoi(&line[i]) < 0 ? 0 : ft_atoi(&line[i]);
	i = advance(&line[i]) + i;
	return (i);
}

/*
**	This function checkes if the resolution has been already read
**	There cannot be 2 or more lines with resolution in the file map
*/

static int	valid_content_resolution(t_param *p)
{
	if (p->scene->screen.x != -1 && p->scene->screen.y != -1)
		return (0);
	return (1);
}

/*
**	t	:	it is a counter. When t = 0, it means that the read value,
**			the first one, is assigned to x, and t = 1, the read value,
**			the second one, es assigned to y.
*/

static int	parsing_resolution(char *line, t_param *p, int i, int t)
{
	if ((valid_content_resolution(p)) == 0)
		return (0);
	while (line[i] != '\0')
	{
		i = ft_isspace(line, i);
		if (ft_strchr("0123456789", line[i]) == 1 && t == 0)
		{
			i = getting_resolution(&p->scene->screen.x, i, line);
		}
		else if (ft_strchr("0123456789", line[i]) == 1 && t == 1)
		{
			i = getting_resolution(&p->scene->screen.y, i, line);
		}
		else
		{
			if (line[i] == '\0'
					&& (p->scene->screen.x != -1 && p->scene->screen.y != -1))
				break ;
			else
				return (0);
		}
		t++;
	}
	return (1);
}

int			ft_resolution(char *line, t_param *p, int i, int t)
{
	int		sizex;
	int		sizey;

	sizex = 0;
	sizey = 0;
	if ((parsing_resolution(line, p, i, t)) == 0)
		return (0);
	if (p->scene->screen.x < 1 || p->scene->screen.y < 1)
		return (0);
	mlx_get_screen_size(p->data->mlx_ptr, &sizex, &sizey);
	if (p->scene->screen.x > sizex)
		p->scene->screen.x = sizex;
	if (p->scene->screen.y > sizey)
		p->scene->screen.y = sizey;
	p->scene->settings.r = 1;
	return (1);
}

void		ft_get_resolution_r(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont)
		{
			if (p->scene->file->cont[i] == 'R')
			{
				ft_resolution(&p->scene->file->cont[i], p, i + 1, 0);
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
