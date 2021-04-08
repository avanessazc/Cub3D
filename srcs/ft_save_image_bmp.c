/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_image_bmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/01/28 13:29:21 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Referenced from: https://itnext.io/bits-to-bitmaps-a-simple-walkthrough
** -of-bmp-image-format-765dc6857393
**	HEADERFILESIZE		54 bytes
**	FileType			2 bytes
**	FileSize			4 bytes
**	Reserved			2 bytes
**	Reserved			2 bytes
**	PixelDataOffset		4 bytes
**	HeaderSize			4 bytes
**	ImageWidth			4 bytes
**	ImageHeight			4 bytes
**	Planes				2 bytes
**	BitsPerPixel		2 bytes
**	Compression			4 bytes
**	ImageSize			4 bytes
**	XpixelsPerMeter		4 bytes
**	YpixelsPerMeter		4 bytes
**	TotalColors			4 bytes
**	ImportantColors		4 bytes
*/

/*
**	w = p->scene->screen.x
**	h = p->scene->screen.y
*/

static void		create_header(int fd, int pad, t_param *p)
{
	unsigned char	headerfile[54];
	int				bmpsize;

	bmpsize = 54 + (3 * (p->scene->screen.x + pad) * p->scene->screen.y);
	ft_bzero(headerfile, 54);
	headerfile[0] = (unsigned char)('B');
	headerfile[1] = (unsigned char)('M');
	headerfile[2] = (unsigned char)bmpsize;
	headerfile[3] = (unsigned char)(bmpsize >> 8);
	headerfile[4] = (unsigned char)(bmpsize >> 16);
	headerfile[5] = (unsigned char)(bmpsize >> 24);
	headerfile[10] = (unsigned char)(54);
	headerfile[14] = (unsigned char)(40);
	headerfile[18] = (unsigned char)p->scene->screen.x;
	headerfile[19] = (unsigned char)(p->scene->screen.x >> 8);
	headerfile[20] = (unsigned char)(p->scene->screen.x >> 16);
	headerfile[21] = (unsigned char)(p->scene->screen.x >> 24);
	headerfile[22] = (unsigned char)p->scene->screen.y;
	headerfile[23] = (unsigned char)(p->scene->screen.y >> 8);
	headerfile[24] = (unsigned char)(p->scene->screen.y >> 16);
	headerfile[25] = (unsigned char)(p->scene->screen.y >> 24);
	headerfile[26] = (unsigned char)(1);
	headerfile[28] = (unsigned char)(24);
	if ((write(fd, headerfile, 54) < 0))
		ft_errors(-1, p);
}

static void		creating_image_msg(int y, t_param *p)
{
	float		pct;
	static int	c;

	pct = ((float)1 - ((float)y / (float)p->scene->screen.y)) * (float)100;
	if ((int)pct == 30 && c == 0)
	{
		c++;
		ft_putstr_fd("Processing pixels - 30%\n", 1);
	}
	else if ((int)pct == 50 && c == 1)
	{
		c++;
		ft_putstr_fd("Processing pixels - 50%\n", 1);
	}
	else if ((int)pct == 70 && c == 2)
	{
		c++;
		ft_putstr_fd("Processing pixels - 70%\n", 1);
	}
	else if ((int)pct == 90 && c == 3)
	{
		c++;
		ft_putstr_fd("Processing pixels - 90%\n", 1);
	}
}

static int		copy_pixels(t_param *p, int fd, int pad)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = p->scene->screen.y - 1;
	ft_bzero(zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < p->scene->screen.x)
		{
			pixel = p->data->image.pixels[x + y * p->data->image.size_line / 4];
			if (write(fd, &pixel, 3) < 0)
				return (ft_errors(-6, p));
			x++;
		}
		if (pad > 0 && write(fd, &zero, pad) < 0)
			return (ft_errors(-6, p));
		creating_image_msg(y, p);
		y--;
	}
	return (0);
}

int				ft_save_image_bmp(t_param *p)
{
	int pad;
	int fd;

	pad = (4 - ((int)p->scene->screen.x * 3) % 4) % 4;
	ft_putstr_fd("Processing....\n", 1);
	if ((fd = open("save.bmp", O_WRONLY | O_CREAT, 0777
													| O_TRUNC | O_APPEND)) < 0)
		return (ft_errors(-7, p));
	create_header(fd, pad, p);
	ft_putstr_fd("Header created!\n", 1);
	ft_putstr_fd("Processing pixels....\n", 1);
	copy_pixels(p, fd, pad);
	if (close(fd) == -1)
		return (ft_errors(-4, p));
	ft_putstr_fd("Processing pixel - 100%\n", 1);
	ft_putstr_fd("Image .bmp saved!\n", 1);
	ft_frees1(p);
	ft_frees2(p);
	ft_free_t_param(p);
	exit(0);
	return (0);
}
