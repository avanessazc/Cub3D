/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structures1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:14:28 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 10:28:23 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_init_settings(t_set *settings)
{
	settings->r = -1;
	settings->no = -1;
	settings->so = -1;
	settings->ea = -1;
	settings->we = -1;
	settings->s = -1;
	settings->f = -1;
	settings->c = -1;
	settings->sm = 0;
	settings->el = 0;
}

void		ft_init_textfiles_struct(t_textfiles *texture)
{
	texture->no = NULL;
	texture->so = NULL;
	texture->we = NULL;
	texture->ea = NULL;
	texture->s = NULL;
}

void		ft_init_color_struct(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
}

void		ft_ini_struc_scene(t_scndescrip *scene)
{
	scene->screen.x = -1;
	scene->screen.y = -1;
	ft_init_textfiles_struct(&scene->tf);
	ft_init_color_struct(&scene->floor);
	ft_init_color_struct(&scene->ceiling);
	ft_init_settings(&scene->settings);
	scene->file = NULL;
	scene->map_int = NULL;
	scene->map_sln = NULL;
	scene->onescoord = NULL;
	scene->sprite = NULL;
	scene->onescoord = NULL;
	scene->dir = '0';
	scene->sprnbr = 0;
	scene->save = 0;
	scene->mapdim.x = 0;
	scene->mapdim.y = 0;
	scene->pos.x = -1;
	scene->pos.y = -1;
}
