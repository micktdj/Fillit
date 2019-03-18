/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piabdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:18:15 by piabdo            #+#    #+#             */
/*   Updated: 2019/01/25 13:39:51 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_listdel(t_flist **p_list)
{
	t_block *p_temp;
	t_block *p_del;

	if (*p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del);
		}
		free(*p_list);
		*p_list = NULL;
	}
}
