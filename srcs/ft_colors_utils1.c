/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 12:05:24 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		advance(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && ft_strchr("0123456789", line[i]) == 1)
		i++;
	return (i);
}

int		ft_isspace(char *line, int i)
{
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

int		check_comma(char *line)
{
	int		i;

	i = 0;
	if (line[i] != '\0' && line[i] != ',')
	{
		return (-1);
	}
	if (line[i] == ',')
		i++;
	return (i);
}

int		ft_isnum(char *line)
{
	int		i;

	i = 0;
	if (line[i] != '\0' && ft_strchr("0123456789", line[i]) != 1)
	{
		return (-1);
	}
	return (i);
}

int		check(char *line)
{
	int		i;
	int		ck_comma;

	i = 0;
	i = ft_isspace(&line[i], 0) + i;
	ck_comma = check_comma(&line[i]);
	if (ck_comma == -1)
		return (-1);
	i = ck_comma + i;
	i = ft_isspace(&line[i], 0) + i;
	if (ft_isnum(&line[i]) == -1)
		return (-1);
	return (i);
}
