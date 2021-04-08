/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pos_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/25 13:31:50 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		set_pos_dir_initial(t_scndescrip *scene, int i, int j, char c)
{
	scene->pos.x = i + 0.5;
	scene->pos.y = j + 0.5;
	if (c == 'N')
	{
		scene->pldir.x = -1;
		scene->pldir.y = 0;
	}
	if (c == 'S')
	{
		scene->pldir.x = 1;
		scene->pldir.y = 0;
	}
	if (c == 'E')
	{
		scene->pldir.x = 0;
		scene->pldir.y = 1;
	}
	if (c == 'W')
	{
		scene->pldir.x = 0;
		scene->pldir.y = -1;
	}
}

void		set_plane_initial(t_scndescrip *scene, char c)
{
	if (c == 'N')
	{
		scene->plane.x = 0;
		scene->plane.y = 0.66;
	}
	if (c == 'S')
	{
		scene->plane.x = 0;
		scene->plane.y = -0.66;
	}
	if (c == 'E')
	{
		scene->plane.x = 0.66;
		scene->plane.y = 0;
	}
	if (c == 'W')
	{
		scene->plane.x = -0.66;
		scene->plane.y = 0;
	}
}

void		ini_move_keys(t_data *data)
{
	data->moves.forward = 0;
	data->moves.stepback = 0;
	data->moves.turnright = 0;
	data->moves.turnleft = 0;
	data->moves.right = 0;
	data->moves.left = 0;
}
