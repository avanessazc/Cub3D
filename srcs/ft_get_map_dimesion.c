/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_dimesion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:20:35 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 11:26:36 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_get_map_dimesion(t_param *p, t_file *tmp, int param_nbr)
{
	tmp = p->scene->file;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	if (p->scene->file)
	{
		p->scene->mapdim.y = p->scene->file->nodes_nbr - N_PARAMETRES;
		if ((p->scene->mapdim.y) < 3)
			return (3);
	}
	else
		return (3);
	p->scene->mapdim.x = p->scene->file->line_size;
	while (p->scene->file)
	{
		if (p->scene->file->line_size > p->scene->mapdim.x)
			p->scene->mapdim.x = p->scene->file->line_size;
		p->scene->file = p->scene->file->next;
	}
	p->scene->file = tmp;
	tmp = NULL;
	return (1);
}
