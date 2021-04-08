/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:46:12 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 09:45:26 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_lstclear_file(t_file **to_free)
{
	t_file	*next;

	while (*to_free)
	{
		next = (*to_free)->next;
		if ((*to_free)->cont)
			free((*to_free)->cont);
		free(*to_free);
		*to_free = next;
	}
}

void	ft_free_t_param(t_param *p)
{
	if (p->scene)
		free(p->scene);
	if (p->data)
		free(p->data);
	if (p->sprites)
		free(p->sprites);
	if (p)
		free(p);
}

void	ft_frees1(t_param *p)
{
	ft_clear_map_int(p->scene->map_int, p->scene->mapdim.y);
	ft_clear_map_int(p->scene->map_sln, p->scene->mapdim.y);
	ft_lstclear_sprite(&p->scene->sprite);
	ft_clear_sprtab(&p->data->sprtab);
	ft_clear_int_tab(&p->data->spr_order);
	ft_clear_double_tab(&p->data->spr_dist);
	ft_lstclear_one_coord(&p->scene->onescoord);
	ft_lstclear_file(&p->scene->file);
	ft_clear_textures(&p->scene->tf);
}

void	ft_frees2(t_param *p)
{
	if (p->data->north.tex)
		mlx_destroy_image(p->data->mlx_ptr, p->data->north.tex);
	if (p->data->south.tex)
		mlx_destroy_image(p->data->mlx_ptr, p->data->south.tex);
	if (p->data->east.tex)
		mlx_destroy_image(p->data->mlx_ptr, p->data->east.tex);
	if (p->data->west.tex)
		mlx_destroy_image(p->data->mlx_ptr, p->data->west.tex);
	if (p->data->sprite.tex)
		mlx_destroy_image(p->data->mlx_ptr, p->data->sprite.tex);
	if (p->data->win_ptr)
	{
		mlx_clear_window(p->data->mlx_ptr, p->data->win_ptr);
		ft_destroy_win(&p->data->mlx_ptr, &p->data->win_ptr);
		if (p->data->image.img_ptr)
			mlx_destroy_image(p->data->mlx_ptr, p->data->image.img_ptr);
	}
	if (p->data->mlx_ptr)
		mlx_destroy_display(p->data->mlx_ptr);
	if (p->data->mlx_ptr)
		free(p->data->mlx_ptr);
}
