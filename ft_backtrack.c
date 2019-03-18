/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piabdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:25:57 by piabdo            #+#    #+#             */
/*   Updated: 2019/01/24 15:20:29 by piabdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_resolve(char **map, t_block *current, int length, int *blk)
{
	int			*y;
	int			*x;

	y = &(current->map_y);
	x = &(current->map_x);
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (ft_place_or_remove(map, &current, '#'))
			{
				if (current->p_next == NULL)
					return (1);
				if (ft_resolve(map, current->p_next, length, blk))
					return (1);
				ft_place_or_remove(map, &current, '.');
			}
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int				ft_backtrack(t_flist **head)
{
	char		**map;
	t_block		*current;
	int			blk;
	int			length;

	if ((map = ft_mapping(head, NULL)) == NULL)
		return (ft_printerror(ERROR));
	current = (*head)->p_head;
	current->map_y = 0;
	current->map_x = 0;
	blk = 0;
	length = (*head)->length;
	while (!(ft_resolve(map, current, length, &blk)))
	{
		if ((map = ft_mapping(head, map)) == NULL)
			return (ft_printerror(ERROR));
	}
	ft_print_map(map);
	return (0);
}
