/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:56:25 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/25 13:35:58 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

# define BLOCK_SIZE 21
# define ERROR -1

typedef struct	s_countinfo
{
	int	p;
	int	h;
	int	n;
}				t_info;

typedef struct	s_block
{
	char			tab[5][5];
	int				pattern[2][4];
	int				map_y;
	int				map_x;
	int				blk;
	struct s_block	*p_next;
}				t_block;

typedef struct	s_flist
{
	size_t	length;
	t_block	*p_head;
}				t_flist;

t_block			*ft_listadd(t_flist **p_list);
void			ft_listdel(t_flist **p_list);
t_flist			*ft_listnew(void);
int				ft_place_or_remove(char **map, t_block **current, char c);
int				ft_checkchar(int fd);
int				ft_printerror(int e);
int				ft_stock(int fd, t_flist **p_list);
int				ft_connect(char *buf);
int				ft_backtrack(t_flist **head);
char			**ft_mapping(t_flist **head, char **map_created);
void			ft_print_map(char **map);
void			ft_patern_creation(t_flist **head);

#endif
