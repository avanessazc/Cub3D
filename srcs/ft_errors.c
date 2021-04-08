/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 10:20:05 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	error1(int err)
{
	if (err == -7)
		ft_putstr_fd("Error\nCreate() file '.bmp' failed\n", 1);
	if (err == -6)
		ft_putstr_fd("Error\nWrite() failed\n", 1);
	if (err == -5)
		ft_putstr_fd("Error\nInvalid second argument\n", 1);
	if (err == -4)
		ft_putstr_fd("Error\nClose() failed\n", 1);
	if (err == -3)
		ft_putstr_fd("Error\nRead() failed\n", 1);
	if (err == -2)
		ft_putstr_fd("Error\nOpen() failed\n", 1);
	if (err == -1)
		ft_putstr_fd("Error\nMalloc() failed\n", 1);
	return (0);
}

static int	error2(int err)
{
	if (err == 1)
		ft_putstr_fd("Error\nCheck arguments\n", 1);
	if (err == 2)
		ft_putstr_fd("Error\nFile does not have the right format: .cub\n", 1);
	if (err == 3)
		ft_putstr_fd("Error\nScene File Error\n", 1);
	if (err == 6)
		ft_putstr_fd("Error\nTexture file\n", 1);
	if (err == 7)
		ft_putstr_fd("Error\nMinilibx failed\n", 1);
	if (err == 8)
		ft_putstr_fd("Error\nIt is not a file\n", 1);
	return (0);
}

int			ft_errors(int err, t_param *p)
{
	ft_frees1(p);
	ft_frees2(p);
	ft_free_t_param(p);
	error1(err);
	error2(err);
	exit(0);
	return (0);
}
