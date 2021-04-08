/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_diagonals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:15:03 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 15:18:06 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check1(t_param *p, int i, int j)
{
	if (((j - 1) >= 0 && (j - 1) < p->scene->mapdim.x)
				&& ((i - 1) >= 0 && (i - 1) < p->scene->mapdim.y))
	{
		if (p->scene->map_int[i - 1][j - 1] == 1)
		{
			if ((p->scene->map_int[i][j - 1] == 0
										|| p->scene->map_int[i][i - 1] == 2)
				&& (p->scene->map_int[i - 1][j] == 0
										|| p->scene->map_int[i - 1][j] == 2))
			{
				return (0);
			}
		}
	}
	return (1);
}

static int	check2(t_param *p, int i, int j)
{
	if (((j - 1) >= 0 && (j - 1) < p->scene->mapdim.x)
				&& ((i + 1) >= 0 && (i + 1) < p->scene->mapdim.y))
	{
		if (p->scene->map_int[i + 1][j - 1] == 1)
		{
			if ((p->scene->map_int[i][j - 1] == 0
										|| p->scene->map_int[i][j - 1] == 2)
				&& (p->scene->map_int[i + 1][j] == 0
										|| p->scene->map_int[i + 1][j] == 2))
			{
				return (0);
			}
		}
	}
	return (1);
}

/*
**	ft_check_diagonals
**	This function checks that there is not a diagonal of 1s.
*/

int			ft_check_diagonals(t_param *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < p->scene->mapdim.y)
	{
		j = 0;
		while (j < p->scene->mapdim.x)
		{
			if (p->scene->map_sln[i][j] == 1)
			{
				if (check1(p, i, j) == 0)
					return (0);
				if (check2(p, i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
