/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_lines_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:26:12 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/31 14:37:00 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_lst_file_size(t_file *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	create_node_content(t_file **new, char *content, int len, int len_line)
{
	(*new)->cont = ft_strdup(content, len_line);
	(*new)->line_nbr = len + 1;
	(*new)->line_size = len_line;
	(*new)->nodes_nbr = len + 1;
	(*new)->next = NULL;
}

t_file	*ft_add_elem_file(t_param *p, char *content, int len, int len_line)
{
	t_file	*new;
	t_file	*tmp;

	len = ft_lst_file_size(p->scene->file);
	len_line = ft_strlen(content);
	new = (t_file*)malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	create_node_content(&new, content, len, len_line);
	if (!(p->scene->file))
		p->scene->file = new;
	else
	{
		tmp = p->scene->file;
		while ((p->scene->file)->next)
		{
			p->scene->file->nodes_nbr = len + 1;
			p->scene->file = (p->scene->file)->next;
		}
		p->scene->file->nodes_nbr = len + 1;
		(p->scene->file)->next = new;
		p->scene->file = tmp;
	}
	return (new);
}

int		check_empty_line(t_param *p, char *line)
{
	if (ft_valid_empty_line(p, line) == 0)
	{
		ft_lstclear_file(&p->scene->file);
		return (3);
	}
	return (1);
}

int		check_add_elem_file(t_param *p, char *line, int i)
{
	if (!(ft_add_elem_file(p, &line[i], 0, 0)))
	{
		ft_lstclear_file(&p->scene->file);
		return (-1);
	}
	return (1);
}
