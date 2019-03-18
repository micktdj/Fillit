/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:22:57 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/18 20:56:20 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nextn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_modifstock(char *str)
{
	int		i;
	int		y;
	char	*dest;

	i = ft_nextn(str) + 1;
	y = ft_strlen(str);
	if (i == y + 1)
	{
		free(str);
		return (NULL);
	}
	dest = ft_strsub(str, i, ft_strlen(str) - i);
	ft_strdel(&str);
	return (dest);
}

int		ft_locate(const char *s, int c)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

int		ft_join(int ret, char **stock, char *buff)
{
	char *tmp;

	if (ret == 0)
	{
		ft_strdel(stock);
		return (1);
	}
	tmp = ft_strjoin(*stock, buff);
	ft_strdel(stock);
	*stock = tmp;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *stock;
	int			ret;
	char		buff[BUFF_SIZE + 1];

	if (fd < 0)
		return (-1);
	if (!stock)
		stock = ft_strdup("");
	while (ft_locate((char *)stock, '\n') == 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[ret] = '\0';
		if (ret == 0 && stock[0] != '\0')
			break ;
		if ((ft_join(ret, &stock, buff)) == 1)
			return (0);
	}
	*line = ft_strndup(stock, ft_nextn(stock));
	stock = ft_modifstock(stock);
	return (1);
}
