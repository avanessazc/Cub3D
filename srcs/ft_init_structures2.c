/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structures2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:14:28 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 10:28:31 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_ini_struc_data(t_data *data)
{
	data->sprtab = NULL;
	data->spr_order = NULL;
	data->spr_dist = NULL;
	data->north.tex = NULL;
	data->south.tex = NULL;
	data->east.tex = NULL;
	data->west.tex = NULL;
	data->sprite.tex = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->image.img_ptr = NULL;
	data->image.pixels = NULL;
}

void		ft_ini_struc_sprite(t_sprvar *sprites)
{
	sprites->sprite.x = 0;
	sprites->sprite.y = 0;
	sprites->invdet = 0;
	sprites->transform.x = 0;
	sprites->transform.y = 0;
	sprites->sprscreenx = 0;
	sprites->size.x = 0;
	sprites->size.y = 0;
	sprites->drawstarty = 0;
	sprites->drawendy = 0;
	sprites->drawstartx = 0;
	sprites->drawendx = 0;
	sprites->tex_x = 0;
	sprites->tex_y = 0;
	sprites->x = 0;
	sprites->y = 0;
	sprites->d = 0;
}
