/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:58:01 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/31 10:05:02 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_clear_textures(t_textfiles *to_free)
{
	if ((*to_free).no)
	{
		free((*to_free).no);
		(*to_free).no = NULL;
	}
	if ((*to_free).so)
	{
		free((*to_free).so);
		(*to_free).so = NULL;
	}
	if ((*to_free).we)
	{
		free((*to_free).we);
		(*to_free).we = NULL;
	}
	if ((*to_free).ea)
	{
		free((*to_free).ea);
		(*to_free).ea = NULL;
	}
	if ((*to_free).s)
	{
		free((*to_free).s);
		(*to_free).s = NULL;
	}
}

int		ft_clear_map_int(int **to_free, double y)
{
	int	c;

	c = 0;
	if (to_free != NULL)
	{
		while (c < y)
		{
			free(to_free[c]);
			c++;
		}
		free(to_free);
		to_free = NULL;
	}
	return (0);
}

void	ft_clear_sprtab(t_spritab **to_free)
{
	if (*to_free)
		free(*to_free);
}

void	ft_lstclear_sprite(t_sprite **to_free)
{
	t_sprite	*next;

	while (*to_free)
	{
		next = (*to_free)->next;
		free(*to_free);
		*to_free = next;
	}
}

void	ft_clear_part_of_list(t_param *p)
{
	t_file	*next;
	int		param_nbr;

	param_nbr = 0;
	while (p->scene->file && param_nbr < N_PARAMETRES)
	{
		next = p->scene->file->next;
		if (p->scene->file->cont)
			free(p->scene->file->cont);
		free(p->scene->file);
		p->scene->file = next;
		param_nbr++;
	}
}
