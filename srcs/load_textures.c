/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 09:08:47 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		loading_textures(t_param *p)
{
	if (!(p->data->north.tex = mlx_xpm_file_to_image(p->data->mlx_ptr,
								p->scene->tf.no, &p->data->north.size.x,
												&p->data->north.size.y)))
		ft_errors(6, p);
	if (!(p->data->south.tex = mlx_xpm_file_to_image(p->data->mlx_ptr,
								p->scene->tf.so, &p->data->south.size.x,
												&p->data->south.size.y)))
		ft_errors(6, p);
	if (!(p->data->east.tex = mlx_xpm_file_to_image(p->data->mlx_ptr,
								p->scene->tf.ea, &p->data->east.size.x,
												&p->data->east.size.y)))
		ft_errors(6, p);
	if (!(p->data->west.tex = mlx_xpm_file_to_image(p->data->mlx_ptr,
								p->scene->tf.we, &p->data->west.size.x,
												&p->data->west.size.y)))
		ft_errors(6, p);
	if (!(p->data->sprite.tex = mlx_xpm_file_to_image(p->data->mlx_ptr,
								p->scene->tf.s, &p->data->sprite.size.x,
												&p->data->sprite.size.y)))
		ft_errors(6, p);
}

void		get_texture_pixels(t_param *p)
{
	if (!(p->data->north.pixels = (int*)mlx_get_data_addr(p->data->north.tex,
								&p->data->north.bpp, &p->data->north.sizeline,
												&p->data->north.endian)))
		ft_errors(6, p);
	if (!(p->data->south.pixels = (int*)mlx_get_data_addr(p->data->south.tex,
								&p->data->south.bpp, &p->data->south.sizeline,
												&p->data->south.endian)))
		ft_errors(6, p);
	if (!(p->data->east.pixels = (int*)mlx_get_data_addr(p->data->east.tex,
													&p->data->east.bpp,
													&p->data->east.sizeline,
												&p->data->east.endian)))
		ft_errors(6, p);
	if (!(p->data->west.pixels = (int*)mlx_get_data_addr(p->data->west.tex,
								&p->data->west.bpp, &p->data->west.sizeline,
												&p->data->west.endian)))
		ft_errors(6, p);
	if (!(p->data->sprite.pixels = (int*)mlx_get_data_addr(p->data->sprite.tex,
								&p->data->sprite.bpp, &p->data->sprite.sizeline,
												&p->data->sprite.endian)))
		ft_errors(6, p);
}
