/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:22:58 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/25 13:39:13 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist	*ft_listnew(void)
{
	t_flist	*p_newlst;

	if (!(p_newlst = (t_flist *)malloc(sizeof(*p_newlst))))
		return (NULL);
	if (p_newlst != NULL)
	{
		p_newlst->length = 0;
		p_newlst->p_head = NULL;
	}
	return (p_newlst);
}
