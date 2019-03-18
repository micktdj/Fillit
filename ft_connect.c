/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:06:48 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/22 17:52:14 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_connect(char *buf)
{
	int	j;
	int	connect;

	j = 0;
	connect = 0;
	while (buf[j] != '\0')
	{
		if (buf[j] == '#')
		{
			if (j > 0 && buf[j - 1] == '#')
				connect++;
			if (j < 18 && buf[j + 1] == '#')
				connect++;
			if (j > 4 && buf[j - 5] == '#')
				connect++;
			if (j < 15 && buf[j + 5] == '#')
				connect++;
		}
		j++;
	}
	if (connect == 6 || connect == 8)
		return (0);
	return (-1);
}
