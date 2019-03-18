/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:50:11 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/25 11:23:42 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_validfile(int argc, char **argv)
{
	int	fd2;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fillit file\n", 2);
		return (-2);
	}
	fd2 = open(argv[1], O_RDONLY);
	if ((ft_checkchar(fd2)) < 0)
	{
		close(fd2);
		return (ERROR);
	}
	close(fd2);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		e;
	t_flist	*p_list;
	t_block	*block;

	p_list = NULL;
	if ((e = ft_validfile(argc, argv)) < 0)
		return (e == -1 ? ft_printerror(ERROR) : -2);
	fd = open(argv[1], O_RDONLY);
	if ((ft_stock(fd, &p_list)) < 0)
	{
		ft_listdel(&p_list);
		close(fd);
		return (ft_printerror(ERROR));
	}
	block = p_list->p_head;
	ft_patern_creation(&p_list);
	e = ft_backtrack(&p_list);
	close(fd);
	ft_listdel(&p_list);
	return (e < 0 ? ft_printerror(ERROR) : 0);
}
