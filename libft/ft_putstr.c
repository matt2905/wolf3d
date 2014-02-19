/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 12:22:50 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/05 19:23:32 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		write(1, "(null)", 7);
	else
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
}

int		ft_int_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		write(1, "(null)", 7);
	else
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
	return (1);
}
