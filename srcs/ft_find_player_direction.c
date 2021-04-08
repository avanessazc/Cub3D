/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player_direction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:35:50 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 11:36:10 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_find_player_direction(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		d;

	i = 0;
	d = 0;
	tmp = p->scene->file;
	while (p->scene->file)
	{
		i = 0;
		while (p->scene->file->cont[i])
		{
			if (ft_strchr("NSEW", p->scene->file->cont[i]) == 1)
				d++;
			i++;
		}
		p->scene->file = p->scene->file->next;
	}
	p->scene->file = tmp;
	if (d != 1)
		return (3);
	return (1);
}
