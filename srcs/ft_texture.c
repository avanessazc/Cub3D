/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/30 12:16:22 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_get_texture_no(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont)
		{
			if (p->scene->file->cont[i] == 'N'
										&& p->scene->file->cont[i + 1] == 'O')
			{
				ft_texture(&p->scene->file->cont[i], &p->scene->tf.no, i + 2,
													&p->scene->settings.no);
				free(p->scene->file->cont);
				p->scene->file->cont = NULL;
			}
		}
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	p->scene->file = tmp;
	tmp = NULL;
}

void		ft_get_texture_so(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont)
		{
			if (p->scene->file->cont[i] == 'S'
										&& p->scene->file->cont[i + 1] == 'O')
			{
				ft_texture(&p->scene->file->cont[i], &p->scene->tf.so, i + 2,
													&p->scene->settings.so);
				free(p->scene->file->cont);
				p->scene->file->cont = NULL;
			}
		}
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	p->scene->file = tmp;
	tmp = NULL;
}

void		ft_get_texture_ea(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont)
		{
			if (p->scene->file->cont[i] == 'E'
										&& p->scene->file->cont[i + 1] == 'A')
			{
				ft_texture(&p->scene->file->cont[i], &p->scene->tf.ea, i + 2,
													&p->scene->settings.ea);
				free(p->scene->file->cont);
				p->scene->file->cont = NULL;
			}
		}
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	p->scene->file = tmp;
	tmp = NULL;
}

void		ft_get_texture_we(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont)
		{
			if (p->scene->file->cont[i] == 'W'
										&& p->scene->file->cont[i + 1] == 'E')
			{
				ft_texture(&p->scene->file->cont[i], &p->scene->tf.we, i + 2,
													&p->scene->settings.we);
				free(p->scene->file->cont);
				p->scene->file->cont = NULL;
			}
		}
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	p->scene->file = tmp;
	tmp = NULL;
}

void		ft_get_texture_s(t_param *p)
{
	t_file	*tmp;
	int		i;
	int		param_nbr;

	tmp = p->scene->file;
	param_nbr = 0;
	i = 0;
	while (param_nbr < N_PARAMETRES && p->scene->file)
	{
		if (p->scene->file->cont)
		{
			if (p->scene->file->cont[i] == 'S')
			{
				ft_texture(&p->scene->file->cont[i], &p->scene->tf.s, i + 1,
													&p->scene->settings.s);
				free(p->scene->file->cont);
				p->scene->file->cont = NULL;
			}
		}
		p->scene->file = p->scene->file->next;
		param_nbr++;
	}
	p->scene->file = tmp;
	tmp = NULL;
}
