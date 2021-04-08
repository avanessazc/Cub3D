/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:58:01 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/25 09:53:53 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_clear_int_tab(int **to_free)
{
	if (*to_free)
		free(*to_free);
}

void	ft_clear_double_tab(double **to_free)
{
	if (*to_free)
		free(*to_free);
}

void	ft_lstclear_one_coord(t_onecoord **to_free)
{
	t_onecoord	*next;

	while (*to_free)
	{
		next = (*to_free)->next;
		free(*to_free);
		*to_free = next;
	}
}

void	ft_free_tex(void *mlx_ptr, t_text *texture)
{
	if (texture)
	{
		if (mlx_ptr)
			mlx_destroy_image(mlx_ptr, texture->tex);
		free(texture);
		texture = NULL;
	}
}

void	ft_destroy_win(void **mlx_ptr, void **win_ptr)
{
	if (*win_ptr)
		mlx_destroy_window(*mlx_ptr, *win_ptr);
}
