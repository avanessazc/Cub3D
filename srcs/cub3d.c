/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:50:31 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 10:20:24 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	t_param			*param;

	param = (t_param*)malloc(sizeof(t_param));
	if (!param)
		return (0);
	param->scene = (t_scndescrip*)malloc(sizeof(t_scndescrip));
	if (!param->scene)
		return (0);
	param->data = (t_data*)malloc(sizeof(t_data));
	if (!param->data)
		return (0);
	param->sprites = (t_sprvar*)malloc(sizeof(t_sprvar));
	if (!param->sprites)
		return (0);
	ft_ini_struc_scene(param->scene);
	ft_ini_struc_data(param->data);
	ft_ini_struc_sprite(param->sprites);
	check_arg(param, ac, av);
	ft_execute_game(param, av, 0);
	ft_frees1(param);
	ft_frees2(param);
	ft_free_t_param(param);
	return (0);
}
