/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:03:05 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 12:04:05 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_startgame(t_param *p)
{
	move(p);
	raycasting(p);
	drawsprites(p, 0);
	mlx_put_image_to_window(p->data->mlx_ptr,
					p->data->win_ptr, p->data->image.img_ptr, 0, 0);
	return (1);
}

int		create_image(t_param *p)
{
	if (p->scene->screen.x == 0 || p->scene->screen.y == 0)
	{
		return (ft_errors(3, p));
	}
	if (!(p->data->image.img_ptr = mlx_new_image(p->data->mlx_ptr,
									p->scene->screen.x, p->scene->screen.y)))
		return (ft_errors(7, p));
	if (!(p->data->image.pixels =
							(int*)mlx_get_data_addr(p->data->image.img_ptr,
							&(p->data->image.bpp), &(p->data->image.size_line),
							&(p->data->image.endian))))
		return (ft_errors(7, p));
	return (0);
}

int		create_window(t_param *p)
{
	if (!(p->data->win_ptr = mlx_new_window(p->data->mlx_ptr,
											p->scene->screen.x,
											p->scene->screen.y, "cub3D")))
		return (ft_errors(7, p));
	return (0);
}

int		ft_execute_game(t_param *p, char **av, int r)
{
	p->data->mlx_ptr = mlx_init();
	if (!p->data->mlx_ptr)
		return (ft_errors(7, p));
	if ((r = ft_treat_file(av, p)) != 1)
		return (ft_errors(r, p));
	loading_textures(p);
	ft_clear_textures(&p->scene->tf);
	get_texture_pixels(p);
	create_image(p);
	create_window(p);
	if (p->scene->save == 1)
	{
		raycasting(p);
		drawsprites(p, 0);
		ft_save_image_bmp(p);
	}
	else
	{
		mlx_hook(p->data->win_ptr, 2, 0, handle_key, (void *)p);
		mlx_key_hook(p->data->win_ptr, key_release, (void *)p);
		mlx_hook(p->data->win_ptr, 33, 1, closeredx, (void *)p);
		mlx_loop_hook(p->data->mlx_ptr, ft_startgame, (void *)p);
		mlx_loop(p->data->mlx_ptr);
	}
	return (1);
}

int		check_arg(t_param *p, int ac, char **av)
{
	int		fd;

	if (ac != 2 && ac != 3)
		return (ft_errors(1, p));
	if (ft_valid_format_file(av[1], ".cub") == 0)
		return (ft_errors(2, p));
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
		return (ft_errors(8, p));
	if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
		p->scene->save = 1;
	if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		return (ft_errors(-5, p));
	return (0);
}
