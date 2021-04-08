/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_empty_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:17:55 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 09:10:15 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_valid_empty_line(t_param *p, char *line)
{
	int		i;

	i = 0;
	(void)p;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '\0' && (line[i] != ' ' || line[i] != '\t'))
		return (0);
	return (1);
}
