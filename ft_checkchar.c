/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:46:08 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/23 18:04:11 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_ishp(int c)
{
	if (c == '.' || c == '#')
		return (1);
	return (ERROR);
}

static int	ft_count(t_info *info, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			info->n++;
		if (str[i] == '.')
			info->p++;
		if (str[i] == '#')
			info->h++;
		i++;
	}
	if (info->p == 12 && info->h == 4 && info->n >= 4)
		return (0);
	return (ERROR);
}

static int	ft_verif(char *str)
{
	int		i;
	int		c;
	t_info	info;

	info = (t_info){0, 0, 0};
	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		while (ft_ishp(str[i]) == 1)
		{
			i++;
			c++;
		}
		if (str[i] == '\n' && (c == 4 || i == 20))
		{
			i++;
			c = 0;
		}
		else
			return (ERROR);
	}
	if (ft_count(&info, str) == ERROR || ft_connect(str) == ERROR)
		return (ERROR);
	return (0);
}

int			ft_checkchar(int fd)
{
	int		interrupt;
	char	buf[BLOCK_SIZE + 1];
	int		ret;

	interrupt = 0;
	ret = 1;
	while (ret > 0)
	{
		if ((ret = read(fd, buf, 21)) == -1)
			return (ERROR);
		buf[ret] = '\0';
		if (ft_strlen(buf) == 0 && interrupt == 0)
			return (ERROR);
		if (ft_ishp(buf[0]) == ERROR && buf[0] != '\0')
			return (ERROR);
		interrupt = 1;
		if (ret == 0 && buf[20] != '\0')
			return (ERROR);
		if (buf[0] == '\0')
			return (0);
		if (ft_verif(buf) == -1)
			return (ERROR);
	}
	return (0);
}
