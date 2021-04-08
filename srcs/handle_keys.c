/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2020/02/07 13:04:32 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		handle_key(int key, t_param *p)
{
	if (key == A_KEY)
		p->data->moves.left = 1;
	else if (key == W_KEY)
		p->data->moves.forward = 1;
	else if (key == D_KEY)
		p->data->moves.right = 1;
	else if (key == S_KEY)
		p->data->moves.stepback = 1;
	else if (key == LEFT_KEY)
		p->data->moves.turnleft = 1;
	else if (key == RIGHT_KEY)
		p->data->moves.turnright = 1;
	else if (key == ESC_KEY)
	{
		ft_frees1(p);
		ft_frees2(p);
		ft_free_t_param(p);
		exit(0);
	}
	return (0);
}

int		key_release(int key, t_param *p)
{
	if (key == A_KEY)
		p->data->moves.left = 0;
	else if (key == W_KEY)
		p->data->moves.forward = 0;
	else if (key == D_KEY)
		p->data->moves.right = 0;
	else if (key == S_KEY)
		p->data->moves.stepback = 0;
	else if (key == LEFT_KEY)
		p->data->moves.turnleft = 0;
	else if (key == RIGHT_KEY)
		p->data->moves.turnright = 0;
	return (0);
}

int		closeredx(t_param *p)
{
	ft_frees1(p);
	ft_frees2(p);
	ft_free_t_param(p);
	exit(0);
	return (0);
}
