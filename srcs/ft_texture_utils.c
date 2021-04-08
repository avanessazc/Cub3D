/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 12:16:41 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_texture_util(char *line, int i, int j)
{
	while (j >= 0 && line[i + j] == ' ')
		j--;
	return (j);
}

int		ft_texture(char *line, char **texture, int i, int *set)
{
	int		len;
	int		j;

	len = 0;
	if (*texture != NULL)
		return (0);
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0')
		return (0);
	else
	{
		len = ft_strlen(&line[i]);
		if (len < 5)
			return (0);
		j = len - 1;
		j = ft_texture_util(line, i, j);
		*texture = ft_strdup(&line[i], j + 1);
		if (*texture == NULL)
			return (0);
	}
	if (ft_valid_format_file(*texture, ".xpm") == 0)
		return (0);
	*set = 1;
	return (1);
}
