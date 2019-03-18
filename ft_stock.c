/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:43:47 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/23 19:17:46 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_copy_line(t_block **p_block, char *buf, int y)
{
	int b;
	int x;

	x = 0;
	b = 0;
	while (buf[b] != '\n')
	{
		(*p_block)->tab[y][x] = buf[b];
		b++;
		x++;
	}
	(*p_block)->tab[y][4] = '\0';
}

static void	ft_deletelastone(t_flist **p_list)
{
	t_block *tmp;
	t_block *ptmp;

	if ((*p_list)->length == 1)
		return ;
	if (*p_list != NULL)
	{
		tmp = (*p_list)->p_head;
		ptmp = (*p_list)->p_head;
		while (tmp->p_next != NULL)
		{
			ptmp = tmp;
			tmp = tmp->p_next;
		}
		ptmp->p_next = NULL;
		free(tmp);
		(*p_list)->length--;
	}
}

static void	ft_cpy(int fd, t_flist ***p_list, t_block **p_block, int blknb)
{
	int		ret;
	int		y;
	char	buf[6];

	y = 0;
	while ((ret = read(fd, buf, 5)) > 0)
	{
		buf[ret] = '\0';
		ft_copy_line(p_block, buf, y++);
		if (y == 4)
		{
			y = 0;
			blknb++;
			(*p_block)->tab[4][0] = '\0';
			(*p_block)->p_next = ft_listadd(*p_list);
			(*p_block) = (*p_block)->p_next;
			(*p_block)->blk = blknb;
			ret = read(fd, buf, 1);
		}
	}
}

int			ft_stock(int fd, t_flist **p_list)
{
	t_block *p_block;
	int		blknb;

	p_block = NULL;
	blknb = 0;
	(*p_list) = ft_listnew();
	if (p_list == NULL)
		return (ft_printerror(ERROR));
	p_block = ft_listadd(p_list);
	p_block->blk = blknb;
	ft_cpy(fd, &p_list, &p_block, blknb);
	ft_deletelastone(p_list);
	return (0);
}
