/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:43:02 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/17 15:14:21 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "wolf3d.h"

int			ft_get_color(t_data *d, int case_x, int case_y, float angle)
{
	static int	save;
	float		prev_x;
	float		prev_y;

	prev_x = d->x - cos(angle * 3.14 / 180) * 0.1;
	prev_y = d->y + sin(angle * 3.14 / 180) * 0.1;
	if (((int)d->x / case_x != (int)prev_x / case_x)
			&& (int)d->y / case_y != (int)prev_y / case_y)
		return (save);
	if ((int)d->x / case_x > (int)prev_x / case_x)
		return (save = 0xFF7C00);
	if ((int)d->x / case_x < (int)prev_x / case_x)
		return (save = 0xB22601);
	if ((int)d->y / case_y > (int)prev_y / case_y)
		return (save = 0xFFEE07);
	if ((int)d->y / case_y < (int)prev_y / case_y)
		return (save = 0xFFA786);
	return (save = 0xFFFFFF);
}

void		ft_cpy_img(t_data *d)
{
	int		i;

	i = -1;
	while (++i < HEIGHT * d->img.sizeline)
		d->img.data[i] = d->back.data[i];
}

static void	ft_fill_back(t_data *d)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = mlx_get_color_value(d->mlx, 0x0000FF);
	while (i <= HEIGHT / 2 * d->back.sizeline)
	{
		d->back.data[i] = (tmp & 0xFF);
		d->back.data[i + 1] = (tmp & 0xFF00) / 256;
		d->back.data[i + 2] = (tmp & 0xFF0000) / 65536;
		i += 4;
	}
	tmp = mlx_get_color_value(d->mlx, 0x40EE40);
	while (i <= HEIGHT * d->back.sizeline)
	{
		d->back.data[i] = (tmp & 0xFF);
		d->back.data[i + 1] = (tmp & 0xFF00) / 256;
		d->back.data[i + 2] = (tmp & 0xFF0000) / 65536;
		i += 4;
	}
}

void		ft_background(t_data *d)
{
	int		bpp;
	int		sizeline;
	int		endian;

	d->back.img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->back.data = mlx_get_data_addr(d->back.img, &bpp, &sizeline, &endian);
	d->back.bpp = bpp;
	d->back.sizeline = sizeline;
	d->back.endian = endian;
	ft_fill_back(d);
}
