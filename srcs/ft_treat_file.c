/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:22:45 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 10:19:56 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int				ft_treat_file(char **av, t_param *p)
{
	int		fd;
	int		r;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_errors(-2, p));
	if ((r = ft_read_scene(fd, p, 0)) != 1)
	{
		if (close(fd) == -1)
			return (ft_errors(-4, p));
		return (ft_errors(r, p));
	}
	if (close(fd) == -1)
		return (ft_errors(-4, p));
	if ((r = ft_get_settings(p, 0)) != 1)
		return (ft_errors(r, p));
	return (1);
}
