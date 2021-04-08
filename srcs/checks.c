/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:40:59 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/31 14:41:15 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		checked_data(t_scndescrip *scene)
{
	if (scene->screen.x != -1 && scene->screen.y != -1
		&& scene->tf.no != NULL
		&& scene->tf.so != NULL
		&& scene->tf.we != NULL
		&& scene->tf.ea != NULL
		&& scene->tf.s != NULL
		&& scene->floor.red != -1
		&& scene->floor.green != -1
		&& scene->floor.blue != -1
		&& scene->ceiling.red != -1
		&& scene->ceiling.green != -1
		&& scene->ceiling.blue != -1)
		return (1);
	return (0);
}

int		checked_settings(t_set *settings)
{
	if (settings->r != -1 && settings->no != -1 && settings->so != -1
		&& settings->we != -1 && settings->ea != -1 && settings->s != -1
		&& settings->f != -1 && settings->c != -1)
		return (1);
	return (0);
}

int		checked_settings_to_one(t_set *settings)
{
	if (settings->r == 1 && settings->no == 1 && settings->so == 1
		&& settings->we == 1 && settings->ea == 1 && settings->s == 1
		&& settings->f == 1 && settings->c == 1)
		return (1);
	return (3);
}
