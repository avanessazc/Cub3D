/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_closed_map_utils2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:37:28 by ayzapata          #+#    #+#             */
/*   Updated: 2020/03/12 14:38:15 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_search_down(t_param *p, int r, int c)
{
	if (ft_going_rigth(p, r, c))
		return (1);
	if (ft_going_down(p, r, c))
		return (1);
	if (ft_going_left(p, r, c))
		return (1);
	p->scene->map_sln[r][c] = 0;
	if (ft_going_up(p, r, c))
		return (1);
	return (0);
}

int		ft_search_up(t_param *p, int r, int c)
{
	if (ft_going_left(p, r, c))
		return (1);
	if (ft_going_up(p, r, c))
		return (1);
	if (ft_going_rigth(p, r, c))
		return (1);
	p->scene->map_sln[r][c] = 0;
	if (ft_going_down(p, r, c))
		return (1);
	return (0);
}

int		ft_search_right(t_param *p, int r, int c)
{
	if (ft_going_up(p, r, c))
		return (1);
	if (ft_going_rigth(p, r, c))
		return (1);
	if (ft_going_down(p, r, c))
		return (1);
	p->scene->map_sln[r][c] = 0;
	if (ft_going_left(p, r, c))
		return (1);
	return (0);
}

int		ft_search_left(t_param *p, int r, int c)
{
	if (ft_going_down(p, r, c))
		return (1);
	if (ft_going_left(p, r, c))
		return (1);
	if (ft_going_up(p, r, c))
		return (1);
	if (ft_going_rigth(p, r, c))
		return (1);
	return (0);
}
