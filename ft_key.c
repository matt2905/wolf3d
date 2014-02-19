/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:42:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/18 12:42:50 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "wolf3d.h"

static void	ft_rotate_left(t_data *d)
{
	if (d->player.angle < 360 - 3)
		d->player.angle += 3;
	else
		d->player.angle = 0;
}

static void	ft_rotate_right(t_data *d)
{
	if (d->player.angle == 0)
		d->player.angle = 360;
	d->player.angle -= 3;
}

int			ft_key_press(int keycode, t_data *d)
{
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	if (keycode == 109 && d->minimap == 0)
	{
		d->minimap = 1;
		mlx_put_image_to_window(d->mlx, d->win, d->mini.img, 0, 0);
	}
	else if (keycode == 109 && d->minimap == 1)
	{
		d->minimap = 0;
		mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	}
	if (keycode == 65361 || keycode == 113)
		d->save[0] = 1;
	if (keycode == 65362 || keycode == 119)
		d->save[1] = 1;
	if (keycode == 65363 || keycode == 101)
		d->save[2] = 1;
	if (keycode == 65364 || keycode == 115)
		d->save[3] = 1;
	if (keycode == 100)
		d->save[4] = 1;
	if (keycode == 97)
		d->save[5] = 1;
	return (0);
}

int			ft_key_release(int keycode, t_data *d)
{
	if (keycode == 65361 || keycode == 113)
		d->save[0] = 0;
	if (keycode == 65362 || keycode == 119)
		d->save[1] = 0;
	if (keycode == 65363 || keycode == 101)
		d->save[2] = 0;
	if (keycode == 65364 || keycode == 115)
		d->save[3] = 0;
	if (keycode == 100)
		d->save[4] = 0;
	if (keycode == 97)
		d->save[5] = 0;
	return (0);
}

int			ft_loop_hook(t_data *d)
{
	int		i;
	int		ok;

	ok = 0;
	i = -1;
	while (++i != 6)
	{
		if (d->save[i] == 1)
			ok = 1;
	}
	if (d->save[0] == 1)
		ft_rotate_left(d);
	if (d->save[2] == 1)
		ft_rotate_right(d);
	if (d->save[1] == 1)
		ft_go_up(d);
	if (d->save[3] == 1)
		ft_go_down(d);
	if (d->save[4] == 1)
		ft_go_right(d);
	if (d->save[5] == 1)
		ft_go_left(d);
	if (ok == 1)
		ft_draw(d);
	return (0);
}
