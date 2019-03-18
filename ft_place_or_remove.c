/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_or_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piabdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:18:25 by piabdo            #+#    #+#             */
/*   Updated: 2019/01/25 13:22:38 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_t_is_placable(char **map, t_block **current)
{
	int			y;
	int			x;
	int			pst_count;

	y = (*current)->map_y;
	x = (*current)->map_x;
	pst_count = 1;
	while (pst_count <= 4)
	{
		if (x >= 0 && y >= 0 && map[y] != NULL && map[y][x] != '\0'
				&& map[y][x] == '.')
		{
			x = x + (*current)->pattern[0][pst_count];
			y = y + (*current)->pattern[1][pst_count];
			pst_count++;
		}
		else
			return (-1);
	}
	return (0);
}

int				ft_place_or_remove(char **map, t_block **current, char c)
{
	int			y;
	int			x;
	char		letter;
	int			pst_count;

	if (c == '#')
		if (ft_t_is_placable(map, current) == -1)
			return (0);
	y = (*current)->map_y;
	x = (*current)->map_x;
	pst_count = 1;
	letter = 'A' + (*current)->blk;
	while (pst_count <= 4)
	{
		if (c == '#')
			map[y][x] = letter;
		else
			map[y][x] = '.';
		x = x + (*current)->pattern[0][pst_count];
		y = y + (*current)->pattern[1][pst_count];
		pst_count++;
	}
	return (1);
}
