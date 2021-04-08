/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2020/03/09 17:21:07 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_define_line(t_data *data, t_scndescrip *scene)
{
	data->lineheight = (int)(scene->screen.y / data->perpwalldist);
	data->drawstart = -data->lineheight / 2 + scene->screen.y / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + scene->screen.y / 2;
	if (data->drawend >= scene->screen.y)
		data->drawend = scene->screen.y - 1;
}

void	select_texture_ns(t_data *data)
{
	if (data->walldir == 'N')
	{
		data->texture.pixels = data->north.pixels;
		data->texture.size.y = data->north.size.y;
		data->texture.size.x = data->north.size.x;
		data->texture.bpp = data->north.bpp;
		data->texture.sizeline = data->north.sizeline;
		data->texture.endian = data->north.endian;
	}
	if (data->walldir == 'S')
	{
		data->texture.pixels = data->south.pixels;
		data->texture.size.y = data->south.size.y;
		data->texture.size.x = data->south.size.x;
		data->texture.bpp = data->south.bpp;
		data->texture.sizeline = data->south.sizeline;
		data->texture.endian = data->south.endian;
	}
}

void	select_texture_ew(t_data *data)
{
	if (data->walldir == 'E')
	{
		data->texture.pixels = data->east.pixels;
		data->texture.size.y = data->east.size.y;
		data->texture.size.x = data->east.size.x;
		data->texture.bpp = data->east.bpp;
		data->texture.sizeline = data->east.sizeline;
		data->texture.endian = data->east.endian;
	}
	if (data->walldir == 'W')
	{
		data->texture.pixels = data->west.pixels;
		data->texture.size.y = data->west.size.y;
		data->texture.size.x = data->west.size.x;
		data->texture.bpp = data->west.bpp;
		data->texture.sizeline = data->west.sizeline;
		data->texture.endian = data->west.endian;
	}
}

/*
**	n = 1	:	ceiling
**	n = 2	:	floor
*/

void	image_pixel(t_param *p, int x, int y, int n)
{
	if (n == 1)
	{
		p->data->image.pixels[x + y * p->data->image.size_line / 4] =
				ft_create_rgb_color(p->scene->ceiling.red,
									p->scene->ceiling.green,
									p->scene->ceiling.blue);
	}
	if (n == 2)
	{
		p->data->image.pixels[x + y * p->data->image.size_line / 4] =
				ft_create_rgb_color(p->scene->floor.red,
									p->scene->floor.green,
									p->scene->floor.blue);
	}
}

void	draw_ver_line(int x, int y, t_param *p)
{
	double	step;
	double	textpos;

	step = 1.0 * p->data->texture.size.y / p->data->lineheight;
	textpos = (p->data->drawstart - p->scene->screen.y / 2
											+ p->data->lineheight / 2) * step;
	while (y < p->data->drawstart)
	{
		image_pixel(p, x, y, 1);
		y++;
	}
	while (y < p->data->drawend)
	{
		p->data->image.pixels[x + y * p->data->image.size_line / 4] =
							p->data->texture.pixels[p->data->textx
							+ (int)textpos * p->data->texture.sizeline / 4];
		textpos += step;
		y++;
	}
	while (y < p->scene->screen.y)
	{
		image_pixel(p, x, y, 2);
		y++;
	}
}
