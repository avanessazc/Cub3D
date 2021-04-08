/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprites_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/20 11:32:30 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		create_order_tab(t_param *p)
{
	if (p->data->spr_order)
		free(p->data->spr_order);
	p->data->spr_order = (int*)malloc(sizeof(int) * p->scene->sprnbr);
	if (!p->data->spr_order)
		ft_errors(-1, p);
	if (p->data->spr_dist)
		free(p->data->spr_dist);
	p->data->spr_dist = (double*)malloc(sizeof(double) * p->scene->sprnbr);
	if (!p->data->spr_dist)
		ft_errors(-1, p);
}

void		sprite_h(t_scndescrip *scene, t_sprvar *sprites)
{
	int		h;

	h = scene->screen.y;
	sprites->size.y = abs((int)(h / (sprites->transform.y)));
	sprites->drawstarty = -sprites->size.y / 2 + h / 2;
	if (sprites->drawstarty < 0)
		sprites->drawstarty = 0;
	sprites->drawendy = sprites->size.y / 2 + h / 2;
	if (sprites->drawendy >= h)
		sprites->drawendy = h - 1;
}

void		sprite_w(t_scndescrip *scene, t_sprvar *sprites)
{
	int		h;
	int		w;

	w = scene->screen.x;
	h = scene->screen.y;
	sprites->size.x = abs((int)(h / (sprites->transform.y)));
	sprites->drawstartx = -sprites->size.x / 2 + sprites->sprscreenx;
	if (sprites->drawstartx < 0)
		sprites->drawstartx = 0;
	sprites->drawendx = sprites->size.x / 2 + sprites->sprscreenx;
	if (sprites->drawendx >= w)
		sprites->drawendx = w - 1;
}
