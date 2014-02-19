/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 12:46:23 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/18 12:39:52 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

void	ft_go_right(t_data *d)
{
	float	case_x;
	float	case_y;
	float	new_x;
	float	new_y;
	float	angle;

	case_x = WIDTH / d->map.size_line;
	case_y = HEIGHT / d->map.nb_line;
	angle = (d->player.angle - 90.00) * 3.14 / 180.00;
	new_x = d->player.x + cos(angle) * case_x / 15.00;
	new_y = d->player.y - sin(angle) * case_y / 15.00;
	case_x = new_x / case_x;
	case_y = new_y / case_y;
	if (case_x >= 0 && case_x < d->map.size_line
			&& case_y >= 0 && case_y < d->map.nb_line
			&& d->map.tab[(int)case_y][(int)case_x] == 0)
	{
		d->player.x = new_x;
		d->player.y = new_y;
	}
}

void	ft_go_up(t_data *d)
{
	float	case_x;
	float	case_y;
	float	new_x;
	float	new_y;
	float	angle;

	case_x = WIDTH / d->map.size_line;
	case_y = HEIGHT / d->map.nb_line;
	angle = d->player.angle * 3.14 / 180.00;
	new_x = d->player.x + cos(angle) * case_x / 15.00;
	new_y = d->player.y - sin(angle) * case_y / 15.00;
	case_x = new_x / case_x;
	case_y = new_y / case_y;
	if (case_x >= 0 && case_x < d->map.size_line
			&& case_y >= 0 && case_y < d->map.nb_line
			&& d->map.tab[(int)case_y][(int)case_x] == 0)
	{
		d->player.x = new_x;
		d->player.y = new_y;
	}
}

void	ft_go_left(t_data *d)
{
	float	case_x;
	float	case_y;
	float	new_x;
	float	new_y;
	float	angle;

	case_x = WIDTH / d->map.size_line;
	case_y = HEIGHT / d->map.nb_line;
	angle = (d->player.angle + 90.00) * 3.14 / 180.00;
	new_x = d->player.x + cos(angle) * case_x / 15.00;
	new_y = d->player.y - sin(angle) * case_y / 15.00;
	case_x = new_x / case_x;
	case_y = new_y / case_y;
	if (case_x >= 0 && case_x < d->map.size_line
			&& case_y >= 0 && case_y < d->map.nb_line
			&& d->map.tab[(int)case_y][(int)case_x] == 0)
	{
		d->player.x = new_x;
		d->player.y = new_y;
	}
}

void	ft_go_down(t_data *d)
{
	float	case_x;
	float	case_y;
	float	new_x;
	float	new_y;
	float	angle;

	case_x = WIDTH / d->map.size_line;
	case_y = HEIGHT / d->map.nb_line;
	angle = d->player.angle * 3.14 / 180.00;
	new_x = d->player.x - cos(angle) * case_x / 15.00;
	new_y = d->player.y + sin(angle) * case_y / 15.00;
	case_x = new_x / case_x;
	case_y = new_y / case_y;
	if (case_x >= 0 && case_x < d->map.size_line
			&& case_y >= 0 && case_y < d->map.nb_line
			&& d->map.tab[(int)case_y][(int)case_x] == 0)
	{
		d->player.x = new_x;
		d->player.y = new_y;
	}
}
