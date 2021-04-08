/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_closed_map_utils3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:37:28 by ayzapata          #+#    #+#             */
/*   Updated: 2020/03/12 14:38:15 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_going_rigth(t_param *p, int r, int c)
{
	if (can_go(p->scene, r, c + 1))
	{
		go_right_flag(p->scene);
		if (closed_map(p, r, c + 1))
			return (1);
		go_right_flag(p->scene);
	}
	return (0);
}

int		ft_going_down(t_param *p, int r, int c)
{
	if (can_go(p->scene, r + 1, c))
	{
		go_down_flag(p->scene);
		if (closed_map(p, r + 1, c))
			return (1);
		go_down_flag(p->scene);
	}
	return (0);
}

int		ft_going_left(t_param *p, int r, int c)
{
	if (can_go(p->scene, r, c - 1))
	{
		go_left_flag(p->scene);
		if (closed_map(p, r, c - 1))
			return (1);
		go_left_flag(p->scene);
	}
	return (0);
}

int		ft_going_up(t_param *p, int r, int c)
{
	if (can_go(p->scene, r - 1, c))
	{
		go_up_flag(p->scene);
		if (closed_map(p, r - 1, c))
			return (1);
		go_up_flag(p->scene);
	}
	return (0);
}
