/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:33:15 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/31 10:02:20 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			match_line_length(t_param *p, int i, char *new_cont, t_file *tmp)
{
	tmp = p->scene->file;
	while (p->scene->file)
	{
		if (p->scene->file->line_size < p->scene->mapdim.x)
		{
			if (!(new_cont = (char*)malloc(sizeof(char)
											* (p->scene->mapdim.x + 1))))
				return (-1);
			i = 0;
			while (p->scene->file->cont[i] != '\0')
			{
				new_cont[i] = p->scene->file->cont[i];
				i++;
			}
			while (i < p->scene->mapdim.x)
				new_cont[i++] = '0';
			new_cont[i] = '\0';
			free(p->scene->file->cont);
			p->scene->file->cont = new_cont;
		}
		p->scene->file = p->scene->file->next;
	}
	p->scene->file = tmp;
	return (1);
}

t_sprite	*add_sprite_coord(t_param *p, int spr_tx, int i, int j)
{
	t_sprite	*new;
	t_sprite	*tmp;

	if (!(new = (t_sprite*)malloc(sizeof(t_sprite))))
	{
		return (NULL);
	}
	new->x = i;
	new->y = j;
	new->tx = spr_tx;
	new->next = NULL;
	if (!(p->scene->sprite))
		p->scene->sprite = new;
	else
	{
		tmp = p->scene->sprite;
		while ((p->scene->sprite)->next)
			p->scene->sprite = (p->scene->sprite)->next;
		(p->scene->sprite)->next = new;
		p->scene->sprite = tmp;
	}
	return (new);
}

int			converte_to_int(char c, t_param *p, int i, int j)
{
	if (c == '0' || c == ' ')
		return (0);
	if (c == '1')
		return (1);
	if (c == '2')
	{
		if (!(add_sprite_coord(p, 2, i, j)))
		{
			ft_lstclear_sprite(&p->scene->sprite);
			return (-1);
		}
		p->scene->sprnbr++;
		return (2);
	}
	if (ft_strchr("NSEW", c) == 1)
	{
		set_pos_dir_initial(p->scene, i, j, c);
		set_plane_initial(p->scene, c);
		return (0);
	}
	return (0);
}

int			ft_create_map_int(t_param *p, int i, int j, t_file *tmp)
{
	int		t;

	t = p->scene->mapdim.y;
	tmp = p->scene->file;
	if (!(p->scene->map_int = (int**)malloc(sizeof(int*) * t)))
		return (-1);
	while (p->scene->file)
	{
		if (!(p->scene->map_int[i] = (int*)malloc(sizeof(int)
													* (p->scene->mapdim.x))))
			return (-1);
		j = 0;
		while (p->scene->file->cont[j] != '\0')
		{
			if ((t = converte_to_int(p->scene->file->cont[j], p, i, j)) == -1)
				return (-1);
			p->scene->map_int[i][j] = t;
			j++;
		}
		i++;
		p->scene->file = p->scene->file->next;
	}
	p->scene->file = tmp;
	return (1);
}
