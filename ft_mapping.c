/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piabdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:26:21 by piabdo            #+#    #+#             */
/*   Updated: 2019/01/25 12:45:39 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_mysqrt(int nb)
{
	int		i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

static char	**ft_creat_map(int map_size)
{
	int		i;
	int		j;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (map_size + 1))))
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		j = 0;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (map_size + 1))))
		{
			free(tab);
			return (NULL);
		}
		while (j < map_size)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char		**ft_mapping(t_flist **head, char **map_created)
{
	int		map_size;
	char	**map;
	int		i;

	i = 0;
	map_size = 0;
	if (map_created != NULL)
	{
		while (map_created[0][map_size])
			map_size++;
		map_size++;
		while (map_created[i])
		{
			free(map_created[i]);
			i++;
		}
		free(map_created);
	}
	else
		map_size = ft_mysqrt((*head)->length * 4);
	if ((map = ft_creat_map(map_size)) == NULL)
		return (NULL);
	return (map);
}
