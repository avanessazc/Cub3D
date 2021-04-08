/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_closed_map_utils4.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:37:28 by ayzapata          #+#    #+#             */
/*   Updated: 2020/03/12 14:38:15 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	go_up_flag(t_scndescrip *scene)
{
	scene->go_up = 1;
	scene->go_down = 0;
	scene->go_right = 0;
	scene->go_left = 0;
}

void	go_down_flag(t_scndescrip *scene)
{
	scene->go_up = 0;
	scene->go_down = 1;
	scene->go_right = 0;
	scene->go_left = 0;
}

void	go_right_flag(t_scndescrip *scene)
{
	scene->go_up = 0;
	scene->go_down = 0;
	scene->go_right = 1;
	scene->go_left = 0;
}

void	go_left_flag(t_scndescrip *scene)
{
	scene->go_up = 0;
	scene->go_down = 0;
	scene->go_right = 0;
	scene->go_left = 1;
}

int		can_go(t_scndescrip *scene, int r, int c)
{
	if (r >= 0 && c >= 0 && r < scene->mapdim.y && c < scene->mapdim.x
			&& scene->map_int[r][c] == 1)
		return (1);
	return (0);
}
