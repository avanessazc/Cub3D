/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2020/03/04 17:25:21 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		drawsprites(t_param *p, int i)
{
	create_order_tab(p);
	sort_sprites(p->data, p->scene);
	while (i < p->scene->sprnbr)
	{
		p->sprites->sprite.x = ((p->data->sprtab[p->data->spr_order[i]].x + 0.5)
										- p->scene->pos.x);
		p->sprites->sprite.y = (p->data->sprtab[p->data->spr_order[i]].y + 0.5)
										- p->scene->pos.y;
		p->sprites->invdet = 1.0 / (p->scene->plane.x * p->scene->pldir.y
									- p->scene->pldir.x * p->scene->plane.y);
		p->sprites->transform.x = p->sprites->invdet
								* (p->scene->pldir.y * p->sprites->sprite.x
									- p->scene->pldir.x * p->sprites->sprite.y);
		p->sprites->transform.y = p->sprites->invdet
								* (-p->scene->plane.y * p->sprites->sprite.x
									+ p->scene->plane.x * p->sprites->sprite.y);
		p->sprites->sprscreenx = (int)((p->scene->screen.x / 2)
				* (1 + p->sprites->transform.x / p->sprites->transform.y));
		sprite_h(p->scene, p->sprites);
		sprite_w(p->scene, p->sprites);
		p->sprites->x = p->sprites->drawstartx;
		sprite_lines(p->data, p->scene, p->sprites, p->scene->screen.y);
		i++;
	}
	return (0);
}
