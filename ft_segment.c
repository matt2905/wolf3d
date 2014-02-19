/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 12:58:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/15 20:37:17 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"

static void	ft_drawYrev(t_data *d, t_pos pos)
{
	int					x;
	int					y;
	int					i;
	int					j;
	unsigned int		c;

	c = mlx_get_color_value(d->mlx, 0xFFFFFF);
	y = pos.y1;
	while (y >= pos.y2)
	{
		x = pos.x1 + ((pos.x2 - pos.x1) * (y - pos.y1)) / (pos.y2 - pos.y1);
		i = y * d->mini.sizeline;
		j = x * d->mini.bpp / 8;
		d->mini.data[i + j] = c;
		d->mini.data[i + j + 1] = c;
		d->mini.data[i + j + 2] = c;
		y--;
	}
}

static void	ft_drawY(t_data *d, t_pos pos)
{
	int					x;
	int					y;
	int					i;
	int					j;
	unsigned int		c;

	c = mlx_get_color_value(d->mlx, 0xFFFFFF);
	if (pos.y2 < pos.y1)
		ft_drawYrev(d, pos);
	y = pos.y1;
	while (y <= pos.y2)
	{
		x = pos.x1 + ((pos.x2 - pos.x1) * (y - pos.y1)) / (pos.y2 - pos.y1);
		i = y * d->mini.sizeline;
		j = x * d->mini.bpp / 8;
		d->mini.data[i + j] = c;
		d->mini.data[i + j + 1] = c;
		d->mini.data[i + j + 2] = c;
		y++;
	}
}

static void	ft_drawXrev(t_data *d, t_pos pos)
{
	int					x;
	int					y;
	int					i;
	int					j;
	unsigned int		c;

	c = mlx_get_color_value(d->mlx, 0xFFFFFF);
	x = pos.x1;
	while (x >= pos.x2)
	{
		y = pos.y1 + ((pos.y2 - pos.y1) * (x - pos.x1)) / (pos.x2 - pos.x1);
		i = y * d->mini.sizeline;
		j = x * d->mini.bpp / 8;
		d->mini.data[i + j] = c;
		d->mini.data[i + j + 1] = c;
		d->mini.data[i + j + 2] = c;
		x--;
	}
}

static void	ft_drawX(t_data *d, t_pos pos)
{
	int					x;
	int					y;
	int					i;
	int					j;
	unsigned int		c;

	c = mlx_get_color_value(d->mlx, 0xFFFFFF);
	if (pos.x2 < pos.x1)
		ft_drawXrev(d, pos);
	x = pos.x1;
	while (x <= pos.x2)
	{
		y = pos.y1 + ((pos.y2 - pos.y1) * (x - pos.x1)) / (pos.x2 - pos.x1);
		i = y * d->mini.sizeline;
		j = x * d->mini.bpp / 8;
		d->mini.data[i + j] = c;
		d->mini.data[i + j + 1] = c;
		d->mini.data[i + j + 2] = c;
		x++;
	}
}

void		ft_segment(t_data *d, t_pos pos)
{
	int		i;
	int		j;

	i = pos.x2 - pos.x1;
	j = pos.y2 - pos.y1;
	if (i < 0)
		i *= -1;
	if (j < 0)
		j *= -1;
	if (i == j && i == 0)
		return ;
	else if (j == 0 || i >= j)
		ft_drawX(d, pos);
	else if (i == 0 || i <= j)
		ft_drawY(d, pos);
}
