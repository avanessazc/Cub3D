/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2020/03/04 17:25:34 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_forward_stepback(t_data *data, t_scndescrip *scene, float speed)
{
	if (data->moves.forward == 1)
	{
		if (scene->map_int[(int)(scene->pos.x + scene->pldir.x * speed)]
													[(int)scene->pos.y] == 0)
			scene->pos.x += scene->pldir.x * speed * 0.5;
		if (scene->map_int[(int)scene->pos.x]
					[(int)(scene->pos.y + scene->pldir.y * speed)] == 0)
			scene->pos.y += scene->pldir.y * speed * 0.5;
	}
	else
	{
		if (scene->map_int[(int)(scene->pos.x - scene->pldir.x * speed)]
													[(int)scene->pos.y] == 0)
			scene->pos.x -= scene->pldir.x * speed * 0.5;
		if (scene->map_int[(int)scene->pos.x]
					[(int)(scene->pos.y - scene->pldir.y * speed)] == 0)
			scene->pos.y -= scene->pldir.y * speed * 0.5;
	}
}

static void	ft_right_left(t_data *data, t_scndescrip *scene, float speed)
{
	if (data->moves.right == 1)
	{
		if (scene->map_int[(int)(scene->pos.x)]
						[(int)(scene->pos.y - scene->pldir.x * speed)] == 0)
			scene->pos.y -= scene->pldir.x * speed * 0.5;
		if (scene->map_int[(int)(scene->pos.x + scene->pldir.y * speed)]
						[(int)(scene->pos.y)] == 0)
			scene->pos.x += scene->pldir.y * speed * 0.5;
	}
	else
	{
		if (scene->map_int[(int)(scene->pos.x)]
						[(int)(scene->pos.y + scene->pldir.x * speed)] == 0)
			scene->pos.y += scene->pldir.x * speed * 0.5;
		if (scene->map_int[(int)(scene->pos.x - scene->pldir.y * speed)]
						[(int)(scene->pos.y)] == 0)
			scene->pos.x -= scene->pldir.y * speed * 0.5;
	}
}

static void	ft_turnright(t_scndescrip *scene, double rotspeed)
{
	double	olddir;
	double	oldplane;

	olddir = scene->pldir.x;
	scene->pldir.x = scene->pldir.x * cos(-rotspeed)
										- scene->pldir.y * sin(-rotspeed);
	scene->pldir.y = olddir * sin(-rotspeed)
										+ scene->pldir.y * cos(-rotspeed);
	oldplane = scene->plane.x;
	scene->plane.x = scene->plane.x * cos(-rotspeed)
										- scene->plane.y * sin(-rotspeed);
	scene->plane.y = oldplane * sin(-rotspeed)
										+ scene->plane.y * cos(-rotspeed);
}

/*
** both camera direction and camera plane must be rotated
*/

static void	ft_turnleft(t_scndescrip *scene, double rotspeed)
{
	double	olddir;
	double	oldplane;

	olddir = scene->pldir.x;
	scene->pldir.x = scene->pldir.x * cos(rotspeed)
										- scene->pldir.y * sin(rotspeed);
	scene->pldir.y = olddir * sin(rotspeed)
										+ scene->pldir.y * cos(rotspeed);
	oldplane = scene->plane.x;
	scene->plane.x = scene->plane.x * cos(rotspeed)
										- scene->plane.y * sin(rotspeed);
	scene->plane.y = oldplane * sin(rotspeed)
										+ scene->plane.y * cos(rotspeed);
}

int			move(t_param *p)
{
	double	rotspeed;
	float	speed;

	rotspeed = ROTSPEED;
	speed = SPEED;
	if (p->data->moves.forward == 1 || p->data->moves.stepback == 1)
		ft_forward_stepback(p->data, p->scene, speed);
	else if (p->data->moves.right == 1 || p->data->moves.left == 1)
		ft_right_left(p->data, p->scene, speed);
	else if (p->data->moves.turnleft == 1)
		ft_turnleft(p->scene, rotspeed);
	else if (p->data->moves.turnright == 1)
		ft_turnright(p->scene, rotspeed);
	return (0);
}
