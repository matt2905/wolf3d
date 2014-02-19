/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:43:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/19 17:59:41 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIDTH	1000
# define HEIGHT	1000
# define FOV	60

typedef struct	s_pos
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_pos;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_img;

typedef struct	s_player
{
	int			angle;
	float		x;
	float		y;
}				t_player;

typedef struct	s_map
{
	int			**tab;
	int			size_line;
	int			nb_line;
}				t_map;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		img;
	t_img		back;
	t_img		mini;
	t_map		map;
	int			save[6];
	int			minimap;
	float		x;
	float		y;
}				t_data;

int		**ft_read_file(char *filename, t_data *d);
void	ft_background(t_data *d);
void	ft_minimap(t_data *d);
void	ft_segment(t_data *d, t_pos pos);
void	ft_draw(t_data *d);
void	ft_cpy_img(t_data *d);
int		ft_get_color(t_data *d, int case_x, int case_y, float angle);
void	ft_go_up(t_data *d);
void	ft_go_down(t_data *d);
void	ft_go_left(t_data *d);
void	ft_go_right(t_data *d);
int		ft_key_press(int keycode, t_data *d);
int		ft_key_release(int keycode, t_data *d);
int		ft_loop_hook(t_data *d);

#endif
