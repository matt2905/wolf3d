/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 10:40:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/19 17:56:07 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "wolf3d.h"

void	ft_pixel_put_to_image(t_data *d, int color)
{
	int		x;
	int		y;

	if (color == 0xFFFFFF)
		return ;
	x = (int)d->x * d->img.bpp / 8;
	y = (int)d->y * d->img.sizeline;
	d->img.data[x + y] = (color & 0xFF);
	d->img.data[x + y + 1] = (color & 0xFF00) / 256;
	d->img.data[x + y + 2] = (color & 0xFF0000) / 65536;
}

void	ft_put_wall(t_data *d, double angle, int color, int i)
{
	float		dist;
	float		size;

	dist = pow(d->x - d->player.x, 2) + pow(d->y - d->player.y, 2);
	dist = sqrt(dist);
	size = HEIGHT / dist * 25 / cos((d->player.angle - angle) * 3.14 / 180);
	if (size >= HEIGHT)
		size = HEIGHT;
	d->x = (float)i;
	d->y = (HEIGHT - size) / 2;
	while (d->y <= (HEIGHT + size) / 2)
	{
		ft_pixel_put_to_image(d, color);
		d->y++;
	}
}

void	ft_find_intersection(t_data *d, int case_x, int case_y, float angle)
{
	int		x;
	int		y;

	x = (int)d->x / case_x;
	y = (int)d->y / case_y;
	while (x >= 0 && x < d->map.size_line && y >= 0 && y < d->map.nb_line
			&& d->map.tab[y][x] == 0)
	{
		d->x += cos(angle * 3.14 / 180) * 2;
		d->y -= sin(angle * 3.14 / 180) * 2;
		x = (int)d->x / case_x;
		y = (int)d->y / case_y;
	}
	while (x >= 0 && x < d->map.size_line && y >= 0 && y < d->map.nb_line
			&& d->map.tab[y][x])
	{
		d->x -= cos(angle * 3.14 / 180) * 0.1 * 0.1;
		d->y += sin(angle * 3.14 / 180) * 0.1 * 0.1;
		x = (int)d->x / case_x;
		y = (int)d->y / case_y;
	}
}

void	ft_raycasting(t_data *d)
{
	int		case_x;
	int		case_y;
	float	angle;
	int		color;
	int		i;

	i = 0;
	case_x = WIDTH / d->map.size_line;
	case_y = HEIGHT / d->map.nb_line;
	angle = d->player.angle + (FOV / 2) + 360;
	while (angle >= (d->player.angle - (FOV / 2) + 360))
	{
		d->x = d->player.x;
		d->y = d->player.y;
		ft_find_intersection(d, case_x, case_y, angle);
		d->x += cos(angle * 3.14 / 180) * 0.1;
		d->y -= sin(angle * 3.14 / 180) * 0.1;
		color = ft_get_color(d, case_x, case_y, angle);
		ft_put_wall(d, angle, color, i);
		angle -= (float)FOV / (float)WIDTH;
		i++;
	}
}

void	ft_draw(t_data *d)
{
	ft_cpy_img(d);
	ft_raycasting(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	if (d->minimap == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->mini.img, 0, 0);
}
