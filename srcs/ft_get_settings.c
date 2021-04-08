/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:48:13 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/31 10:01:34 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	getting_textures(t_param **p)
{
	ft_get_texture_no(*p);
	ft_get_texture_so(*p);
	ft_get_texture_ea(*p);
	ft_get_texture_we(*p);
	ft_get_texture_s(*p);
}

int		ft_get_settings(t_param *p, int r)
{
	getting_textures(&p);
	ft_get_resolution_r(p);
	ft_get_color_f(p);
	ft_get_color_c(p);
	if ((r = checked_settings_to_one(&p->scene->settings)) != 1)
		return (r);
	if ((r = ft_get_map_dimesion(p, NULL, 0)) != 1)
		return (r);
	ft_clear_part_of_list(p);
	if ((r = match_line_length(p, 0, NULL, NULL)) != 1)
	{
		ft_lstclear_file(&p->scene->file);
		return (r);
	}
	if ((r = ft_find_player_direction(p)) != 1)
		return (r);
	if ((r = ft_create_map_int(p, 0, 0, NULL)) != 1)
		return (r);
	ft_lstclear_file(&p->scene->file);
	if ((r = sprites_to_tab(p)) != 1)
		return (r);
	if (ft_find_closed_map(p) == 0)
		return (3);
	return (1);
}
