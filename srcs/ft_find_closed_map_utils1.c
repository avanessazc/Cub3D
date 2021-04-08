/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_closed_map_utils1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:37:28 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/31 10:17:23 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_onecoord	*add_one_coord(t_param *p, int n, int i, int j)
{
	t_onecoord	*new;
	t_onecoord	*tmp;

	if (!(new = (t_onecoord*)malloc(sizeof(t_onecoord))))
	{
		return (NULL);
	}
	new->x = i;
	new->y = j;
	new->index = n;
	new->next = NULL;
	if (!(p->scene->onescoord))
		p->scene->onescoord = new;
	else
	{
		tmp = p->scene->onescoord;
		while (p->scene->onescoord->next)
			p->scene->onescoord = p->scene->onescoord->next;
		p->scene->onescoord->next = new;
		p->scene->onescoord = tmp;
	}
	return (new);
}

int			count_ones(t_param *p)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (i < p->scene->mapdim.y)
	{
		j = 0;
		while (j < p->scene->mapdim.x)
		{
			if (p->scene->map_sln[i][j] == 1)
			{
				n++;
				if (!(add_one_coord(p, n, i, j)))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (n);
}

int			ft_int_tab_to_zeros(t_param *p)
{
	int		i;
	int		j;

	if (!(p->scene->map_sln = (int**)malloc(sizeof(int*)
											* (p->scene->mapdim.y))))
		return (0);
	i = 0;
	while (i < p->scene->mapdim.y)
	{
		if (!(p->scene->map_sln[i] = (int*)malloc(sizeof(int)
											* (p->scene->mapdim.x))))
			return (0);
		j = 0;
		while (j < p->scene->mapdim.x)
		{
			p->scene->map_sln[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

/*
**	check_around_player	:	This function goes through onecoord chain
**	looking for an 1 up, down, rigth and left of the player.
**	If there is not an 1 up, down, rigth and left, it means that the
**	player is not surrounded by 1s.
*/

int			check_around_player(t_scndescrip *scene, int i, int j)
{
	t_onecoord		*tmp;

	scene->one_north = 0;
	scene->one_south = 0;
	scene->one_east = 0;
	scene->one_west = 0;
	tmp = scene->onescoord;
	while (tmp)
	{
		if (i > tmp->x && j == tmp->y)
			scene->one_north++;
		if (i < tmp->x && j == tmp->y)
			scene->one_south++;
		if (i == tmp->x && j < tmp->y)
			scene->one_east++;
		if (i == tmp->x && j > tmp->y)
			scene->one_west++;
		tmp = tmp->next;
	}
	if (scene->one_north == 0 || scene->one_south == 0
				|| scene->one_east == 0 || scene->one_west == 0)
		return (0);
	return (1);
}

int			closed_map(t_param *p, int r, int c)
{
	if ((r == p->scene->rf) && (c == p->scene->cf))
	{
		p->scene->map_sln[r][c] = 1;
		if (count_ones(p) == -1)
			return (ft_clear_map_int(p->scene->map_sln, p->scene->mapdim.y));
		if (check_around_player(p->scene, (int)(p->scene->pos.x - 0.5),
											(int)(p->scene->pos.y - 0.5)))
			return (1);
		return (0);
	}
	if (r >= 0 && c >= 0 && r < p->scene->mapdim.y && c < p->scene->mapdim.x
			&& p->scene->map_sln[r][c] == 0 && p->scene->map_int[r][c] == 1)
	{
		p->scene->map_sln[r][c] = 1;
		if (p->scene->go_down == 1)
			return (ft_search_down(p, r, c));
		if (p->scene->go_up == 1)
			return (ft_search_up(p, r, c));
		if (p->scene->go_right == 1)
			return (ft_search_right(p, r, c));
		if (p->scene->go_left == 1)
			return (ft_search_left(p, r, c));
		p->scene->map_sln[r][c] = 0;
	}
	return (0);
}
