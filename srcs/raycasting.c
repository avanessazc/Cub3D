/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2020/03/04 17:25:05 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** calculate ray position and direction
** and which box of the map we are in
*/

static void	ft_ray_postition(int x, t_data *data, t_scndescrip *scene)
{
	data->camerax = 2 * x / (double)scene->screen.x - 1;
	data->raydir.x = scene->pldir.x + scene->plane.x * data->camerax;
	data->raydir.y = scene->pldir.y + scene->plane.y * data->camerax;
	data->mapbox.x = (int)scene->pos.x;
	data->mapbox.y = (int)scene->pos.y;
	if (data->raydir.y == 0)
		data->deltadist.x = 0;
	else
		data->deltadist.x =
				(data->raydir.x == 0) ? 1 : fabs(1 / data->raydir.x);
	if (data->raydir.x == 0)
		data->deltadist.y = 0;
	else
		data->deltadist.y =
				(data->raydir.y == 0) ? 1 : fabs(1 / data->raydir.y);
}

/*
** 	calculate step and initial sizedist in x and y
*/

static void	ft_step(t_data *data, t_scndescrip *scene)
{
	if (data->raydir.x < 0)
	{
		data->step.x = -1;
		data->sizedist.x =
			(scene->pos.x - data->mapbox.x) * data->deltadist.x;
	}
	else
	{
		data->step.x = 1;
		data->sizedist.x =
			(data->mapbox.x + 1.0 - scene->pos.x) * data->deltadist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->sizedist.y =
			(scene->pos.y - data->mapbox.y) * data->deltadist.y;
	}
	else
	{
		data->step.y = 1;
		data->sizedist.y =
			(data->mapbox.y + 1.0 - scene->pos.y) * data->deltadist.y;
	}
}

/*
**	jump to next map square, OR in x-direction, OR in y-direction
**	and check if ray has hit a wall
*/

static void	ft_wallhit(t_data *data, t_scndescrip *scene)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sizedist.x < data->sizedist.y)
		{
			data->sizedist.x += data->deltadist.x;
			data->mapbox.x += data->step.x;
			data->side = 0;
		}
		else
		{
			data->sizedist.y += data->deltadist.y;
			data->mapbox.y += data->step.y;
			data->side = 1;
		}
		if (scene->map_int[data->mapbox.x][data->mapbox.y] == 1)
			hit = 1;
	}
}

static void	ft_distance_to_wall_dir(int x, t_data *data, t_scndescrip *scene)
{
	if (data->side == 0)
	{
		if (data->mapbox.x < scene->pos.x)
			data->walldir = 'N';
		else
			data->walldir = 'S';
		data->perpwalldist = (data->mapbox.x - scene->pos.x
							+ (1 - data->step.x) / 2) / data->raydir.x;
		data->wallx = scene->pos.y + data->perpwalldist * data->raydir.y;
	}
	else
	{
		if (data->mapbox.y < scene->pos.y)
			data->walldir = 'W';
		else
			data->walldir = 'E';
		data->perpwalldist = (data->mapbox.y - scene->pos.y
							+ (1 - data->step.y) / 2) / data->raydir.y;
		data->wallx = scene->pos.x + data->perpwalldist * data->raydir.x;
	}
	data->zbuffer[x] = data->perpwalldist;
}

void		raycasting(t_param *p)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < p->scene->screen.x)
	{
		ft_ray_postition(x, p->data, p->scene);
		ft_step(p->data, p->scene);
		ft_wallhit(p->data, p->scene);
		ft_distance_to_wall_dir(x, p->data, p->scene);
		ft_define_line(p->data, p->scene);
		select_texture_ns(p->data);
		select_texture_ew(p->data);
		p->data->wallx -= floor(p->data->wallx);
		p->data->textx = (p->data->wallx * (p->data->texture.sizeline / 4));
		if (p->data->side == 0 && p->data->raydir.x > 0)
			p->data->textx = (p->data->texture.sizeline / 4)
														- p->data->textx - 1;
		else if (p->data->side == 1 && p->data->raydir.y < 0)
			p->data->textx = (p->data->texture.sizeline / 4)
														- p->data->textx - 1;
		draw_ver_line(x, y, p);
		x++;
	}
}
