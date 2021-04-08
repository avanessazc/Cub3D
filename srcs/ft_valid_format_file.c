/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_format_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:51:58 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/24 12:08:30 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_valid_format_file(char *str, char *format)
{
	int		len;

	len = ft_strlen(str);
	if (len < 5)
	{
		return (0);
	}
	if ((ft_memcmp(&str[len - 4], format, 4)) != 0)
	{
		return (0);
	}
	return (1);
}
