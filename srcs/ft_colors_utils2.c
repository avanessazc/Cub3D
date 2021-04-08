/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/24 11:24:53 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		valid_content_color(t_color *color)
{
	if (color->red != -1 && color->green != -1 && color->blue != -1)
	{
		return (0);
	}
	return (1);
}

int		check_color(t_color *color)
{
	if (color->red > 255 || color->green > 255 || color->blue > 255)
	{
		return (0);
	}
	if (color->red == -1 || color->green == -1 || color->blue == -1)
	{
		return (0);
	}
	return (1);
}

int		green_color(char *line, int i, t_color **color, int ck)
{
	i = ck + i;
	if (ft_strchr("0123456789", line[i]) == 1)
	{
		(*color)->green = ft_atoi(&line[i]);
		i = advance(&line[i]) + i;
	}
	return (i);
}

int		blue_color(char *line, int i, t_color **color, int ck)
{
	i = ck + i;
	if (ft_strchr("0123456789", line[i]) == 1)
	{
		(*color)->blue = ft_atoi(&line[i]);
		i = advance(&line[i]) + i;
	}
	i = ft_isspace(&line[i], 0) + i;
	return (i);
}

int		color_init_checks(char *line, int i, t_color *color)
{
	if ((valid_content_color(color) == 0))
		return (-1);
	i = ft_isspace(&line[i], 0) + i;
	if (ft_isnum(&line[i]) == -1)
		return (-1);
	return (i);
}
