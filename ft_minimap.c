/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 20:10:22 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/15 21:13:26 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"

static void	ft_right(t_data *d, int x, int y)
{
	t_pos	pos;

	pos.x1 = x * 5;
	pos.y1 = y * 5;
	pos.x2 = (x + 1) * 5;
	pos.y2 = y * 5;
	ft_segment(d, pos);
}

static void	ft_down(t_data *d, int x, int y)
{
	t_pos	pos;

	pos.x1 = x * 5;
	pos.y1 = y * 5;
	pos.x2 = x * 5;
	pos.y2 = (y + 1) * 5;
	ft_segment(d, pos);
}

void		ft_minimap(t_data *d)
{
	int		x;
	int		y;
	int		h;
	int		w;

	w = 5 * d->map.size_line;
	h = 5 * d->map.nb_line;
	d->mini.img = mlx_new_image(d->mlx, w, h);
	d->mini.data = mlx_get_data_addr(d->mini.img, &d->mini.bpp,
			&d->mini.sizeline, &d->mini.endian);
	y = -1;
	while (++y < d->map.nb_line)
	{
		x = -1;
		while (++x < d->map.size_line)
		{
			if (d->map.tab[y][x] == 1 && d->map.tab[y][x + 1] == 1)
				ft_right(d, x, y);
			if (y < d->map.nb_line - 1)
			{
				if (d->map.tab[y][x] == 1 && d->map.tab[y + 1][x] == 1)
					ft_down(d, x, y);
			}
		}
	}
}
