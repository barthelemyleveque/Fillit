/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:38:18 by thzimmer          #+#    #+#             */
/*   Updated: 2018/12/14 10:39:18 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"

typedef struct	s_coords
{
	char		x;
	char		y;
}				t_coords;

int				ft_sqrt_next(int nb);
t_coords		**ft_file_getvalid(char const *path, int *block);
t_coords		*ft_coords_pos(char const *file, int index, int corr);
void			ft_getcoords(t_coords *pos, t_coords **tetris, int cycle);
char			**ft_map_init(int size);
char			**ft_map_extend(char **map, int *maplen);
int				ft_findsolution(t_coords **tet, char **map, int maplen, char c);
t_coords		**ft_free_file(char *file);

#endif
