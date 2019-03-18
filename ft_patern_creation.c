/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piabdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:12:49 by piabdo            #+#    #+#             */
/*   Updated: 2019/01/25 10:53:39 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_positioning(int pattern[2][4], int pst_abs[2][4])
{
	int i;

	i = 1;
	pattern[0][0] = 0;
	pattern[1][0] = 0;
	while (i < 4)
	{
		pattern[0][i] = pst_abs[0][i] - pst_abs[0][i - 1];
		pattern[1][i] = pst_abs[1][i] - pst_abs[1][i - 1];
		i++;
	}
}

void			ft_pros(char tab[5][5], int pattern[2][4])
{
	int y;
	int x;
	int block;
	int pst_abs[2][4];

	y = 0;
	block = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == '#')
			{
				pst_abs[0][block] = x;
				pst_abs[1][block] = y;
				block++;
			}
			x++;
		}
		y++;
	}
	ft_positioning(pattern, pst_abs);
}

void			ft_patern_creation(t_flist **head)
{
	t_block *current;

	current = (*head)->p_head;
	if (current->p_next == NULL)
	{
		ft_pros(current->tab, current->pattern);
		return ;
	}
	while (1)
	{
		ft_pros(current->tab, current->pattern);
		if (current->p_next == NULL)
			break ;
		current = current->p_next;
	}
}
