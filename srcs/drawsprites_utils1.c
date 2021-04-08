/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprites_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/20 11:32:30 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	define_pixels(t_data *data, t_sprvar *sprites)
{
	if ((data->sprite.pixels[sprites->tex_x
			+ sprites->tex_y * data->sprite.sizeline / 4])
		&& data->sprite.pixels[sprites->tex_x
			+ sprites->tex_y * data->sprite.sizeline / 4] != 0x000000)
	{
		data->image.pixels[(sprites->x + sprites->y
								* data->image.size_line / 4)] =
			data->sprite.pixels[sprites->tex_x
				+ sprites->tex_y * data->sprite.sizeline / 4];
	}
}

static void	sprites_tex_x(t_data *data, t_sprvar *sprites)
{
	sprites->tex_x = (int)(256 * (sprites->x - (-sprites->size.x / 2
		+ sprites->sprscreenx)) * data->sprite.size.x / sprites->size.x) / 256;
	sprites->y = sprites->drawstarty;
}

static void	sprites_tex_y(t_data *data, t_sprvar *sprites, int h)
{
	sprites->d = sprites->y * 256 - h * 128 + sprites->size.y * 128;
	sprites->tex_y = ((sprites->d * data->sprite.size.y)
					/ sprites->size.y) / 256;
}

void		sprite_lines(t_data *data, t_scndescrip *scene,
												t_sprvar *sprites, int h)
{
	int		a;

	a = sizeof(data->sprite.pixels);
	while (sprites->x < sprites->drawendx)
	{
		sprites_tex_x(data, sprites);
		if (sprites->transform.y > 0 && sprites->x > 0
			&& sprites->x < scene->screen.x
			&& sprites->transform.y < (float)data->zbuffer[sprites->x])
		{
			while (sprites->y < sprites->drawendy)
			{
				sprites_tex_y(data, sprites, h);
				if ((sprites->tex_x + sprites->tex_y
									* data->sprite.sizeline / 4) > a)
				{
					if ((data->image.pixels[(sprites->x + sprites->y
											* data->image.size_line / 4)]))
						define_pixels(data, sprites);
				}
				sprites->y++;
			}
		}
		sprites->x++;
	}
}
