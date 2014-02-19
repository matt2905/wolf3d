/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:53:54 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/19 17:36:58 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "wolf3d.h"

static int	ft_expose(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	if (d->minimap == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->mini.img, 0, 0);
	return (0);
}

static void	ft_init_player(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d->map.nb_line)
	{
		j = -1;
		while (++j < d->map.size_line)
		{
			if (d->map.tab[i][j] == 0)
			{
				d->player.x = (j + 0.25) * (WIDTH / d->map.size_line);
				d->player.y = (i + 0.25) * (HEIGHT / d->map.nb_line);
				d->player.angle = 0;
				return ;
			}
		}
	}
	ft_putendl_fd("Error: No case available to position the player", 2);
	exit(EXIT_FAILURE);
}

static int	ft_check_env(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ && environ[i])
	{
		if (!ft_strncmp(environ[i], "DISPLAY=", 8) && environ[i][8] == '\0')
				return (-1);
		if (!ft_strncmp(environ[i], "PATH=", 5) && environ[i][5] == '\0')
			return (-1);
		i++;
	}
	if (i != 0)
		return (1);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_data	d;

	if (argc == 1)
		return (ft_int_putstr("Please, give me a map\n"));
	if (ft_check_env() == -1)
		return (ft_int_putstr("An environ viariable important is missing\n"));
	d.map.tab = ft_read_file(argv[1], &d);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "Wolf3D");
	d.img.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	d.img.data = mlx_get_data_addr(d.img.img,
			&d.img.bpp, &d.img.sizeline, &d.img.endian);
	d.minimap = 0;
	ft_background(&d);
	ft_minimap(&d);
	ft_init_player(&d);
	ft_draw(&d);
	mlx_expose_hook(d.win, ft_expose, &d);
	mlx_hook(d.win, 2, 1, &ft_key_press, &d);
	mlx_hook(d.win, 3, 2, &ft_key_release, &d);
	mlx_loop_hook(d.mlx, &ft_loop_hook, &d);
	mlx_loop(d.mlx);
	return (0);
}
