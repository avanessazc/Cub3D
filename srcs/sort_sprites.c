/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 12:01:09 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		sprites_to_tab(t_param *p)
{
	int			i;
	t_sprite	*tmp;

	ini_move_keys(p->data);
	if (p->data->sprtab)
		free(p->data->sprtab);
	if (!(p->data->sprtab = malloc(sizeof(t_spritab) * p->scene->sprnbr)))
		return (-1);
	i = 0;
	while (i < p->scene->sprnbr || p->scene->sprite)
	{
		p->data->sprtab[i].x = p->scene->sprite->x;
		p->data->sprtab[i].y = p->scene->sprite->y;
		tmp = p->scene->sprite->next;
		if (p->scene->sprite)
			free(p->scene->sprite);
		p->scene->sprite = tmp;
		i++;
	}
	p->scene->sprite = NULL;
	return (1);
}

void	ft_swap_int(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_swap_db(double *a, double *b)
{
	double t;

	t = *a;
	*a = *b;
	*b = t;
}

void	sort_sprites(t_data *data, t_scndescrip *scene)
{
	int		i;

	i = 0;
	while (i < scene->sprnbr)
	{
		data->spr_order[i] = i;
		data->spr_dist[i] = ((scene->pos.x - data->sprtab[i].x)
									* (scene->pos.x - data->sprtab[i].x)
								+ (scene->pos.y - data->sprtab[i].y)
									* (scene->pos.y - data->sprtab[i].y));
		i++;
	}
	i = 0;
	while (i < scene->sprnbr - 1)
	{
		if (data->spr_dist[i + 1] > data->spr_dist[i])
		{
			ft_swap_db(&data->spr_dist[i], &data->spr_dist[i + 1]);
			ft_swap_int(&data->spr_order[i], &data->spr_order[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
