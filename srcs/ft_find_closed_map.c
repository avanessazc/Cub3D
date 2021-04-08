/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_closed_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:37:28 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/21 10:18:14 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	flag(t_param **p, int i, int left)
{
	(*p)->scene->rf = i;
	(*p)->scene->cf = left;
	go_down_flag((*p)->scene);
}

static int	check_closed_map(t_param *p, int i, int j, int left)
{
	while ((check_around_player(p->scene, i, j) == 0))
	{
		while (left >= 0 && left < j)
		{
			if (p->scene->map_int[i][left] == 1
										&& p->scene->map_int[i + 1][left] == 1)
			{
				flag(&p, i, left);
				if (closed_map(p, i + 1, left) == 1)
				{
					if (count_ones(p) == -1)
						return (0);
					break ;
				}
			}
			left--;
		}
		if (left < 0)
			break ;
	}
	if (count_ones(p) == -1)
		return (0);
	if ((check_around_player(p->scene, i, j) == 0))
		return (0);
	return (1);
}

int			ft_find_closed_map(t_param *p)
{
	int		i;
	int		j;
	int		left;

	i = (int)(p->scene->pos.x - 0.5);
	j = (int)(p->scene->pos.y - 0.5);
	left = j - 1;
	if (ft_int_tab_to_zeros(p) == 0)
		return (0);
	if (check_closed_map(p, i, j, left) == 0)
		return (0);
	if (ft_check_diagonals(p) == 0)
		return (0);
	return (1);
}
