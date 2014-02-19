/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:15:10 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/19 18:18:50 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <get_next_line.h>
#include "wolf3d.h"

static int	ft_get_number(char *line)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (!(ft_isdigit(*line)) && *line != '-'
			&& *line != '+' && *line != '\0')
		line++;
	while (*line == '-' || *line == '+')
	{
		if (*line == '-')
			sign *= -1;
		line++;
	}
	while (ft_isdigit(*line))
	{
		result = result * 10 + *line - '0';
		line++;
	}
	return (result * sign);
}

static int	ft_pos(char *line)
{
	int		i;

	i = 0;
	while (!(ft_isdigit(line[i])) && line[i] != '\0')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == '-' || line[i] == '+' || ft_isdigit(line[i]))
			i++;
	return (i);
}

static int	ft_nbrX(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*line)
	{
		if (*line == '-' || *line == '+' || ft_isdigit(*line))
		{
			while (*line == '-' || *line == '+' || ft_isdigit(*line))
				line++;
			i++;
		}
		else
			line++;
	}
	return (i);
}

static int	*ft_get_nbr(char *line, t_data *d)
{
	int		i;
	int		j;
	int		*tab;

	i = 0;
	j = 0;
	tab = NULL;
	i = ft_nbrX(line);
	tab = (int *)malloc(sizeof(int) * (i + 1));
	d->map.size_line = i;
	i = 0;
	while (i <= d->map.size_line)
	{
		tab[i] = ft_get_number(line);
		line += ft_pos(line);
		i++;
	}
	return (tab);
}

int			**ft_read_file(char *filename, t_data *d)
{
	char	*line;
	int		fd;
	int		k;

	k = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
		k++;
	close(fd);
	d->map.nb_line = k;
	if (k == 0)
		return (NULL);
	if ((d->map.tab = (int **)malloc(sizeof(int *) * (k + 1))) == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	k = 0;
	while (get_next_line(fd, &line) && line)
		d->map.tab[k++] = ft_get_nbr(line, d);
	d->map.tab[k] = NULL;
	return (d->map.tab);
}
