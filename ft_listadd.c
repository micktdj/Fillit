/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:33:39 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/25 13:39:27 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block	*ft_listadd(t_flist **p_list)
{
	t_block	*p_nwblk;
	t_block	*tmp;

	if (!(p_nwblk = (t_block *)malloc(sizeof(*p_nwblk))))
		return (NULL);
	p_nwblk->p_next = NULL;
	if ((*p_list)->p_head == NULL)
	{
		(*p_list)->p_head = p_nwblk;
	}
	else
	{
		tmp = (*p_list)->p_head;
		while (tmp->p_next != NULL)
		{
			tmp = tmp->p_next;
		}
		tmp->p_next = p_nwblk;
	}
	(*p_list)->length++;
	return (p_nwblk);
}
