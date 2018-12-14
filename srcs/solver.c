/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:33:20 by thzimmer          #+#    #+#             */
/*   Updated: 2018/12/14 10:52:17 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** En cas d'erreur, free ce qui a ete lu
*/

t_coords	**ft_free_file(char *file)
{
	free(file);
	return (NULL);
}

/*
** Regarde dans la map si la position est bonne avant un placement.
*/

static int	ft_checkmap(t_coords **tet, int const pos, char **map, int maplen)
{
	int		i;
	int		j;
	int		brick;

	i = pos / maplen;
	j = pos % maplen;
	brick = -1;
	while (++brick < 4)
	{
		if ((j + tet[0][brick].x) < 0 || (j + tet[0][brick].x) >= maplen
			|| (i + tet[0][brick].y) >= maplen)
			return (0);
		if (map[i + tet[0][brick].y][j + tet[0][brick].x] != '.')
			return (0);
	}
	return (1);
}

/*
** Augmente la taille de la map.
*/

char		**ft_map_extend(char **map, int *maplen)
{
	int		i;
	char	**new;

	i = -1;
	while (++i < *maplen)
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	*maplen = *maplen + 1;
	if (!(new = ft_map_init(*maplen)))
		return (NULL);
	return (new);
}

/*
** Initialise une map de taille size * size et la rempli de '.'.
*/

char		**ft_map_init(int size)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = -1;
		while (++j < size)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

/*
** Ecris dans la map le tetrimino si le placement est possible.
*/

int			ft_findsolution(t_coords **tet, char **map, int maplen, char c)
{
	int		i;
	int		j;
	int		pos;
	int		brick;

	if (*tet == NULL)
		return (1);
	pos = -1;
	while (++pos < (maplen * maplen))
	{
		i = pos / maplen;
		j = pos % maplen;
		if (map[i][j] == '.' && (ft_checkmap(tet, pos, map, maplen)))
		{
			brick = -1;
			while (++brick < 4)
				map[i + tet[0][brick].y][j + tet[0][brick].x] = c;
			if ((ft_findsolution(tet + 1, map, maplen, c + 1)))
				return (1);
			while (--brick >= 0)
				map[i + tet[0][brick].y][j + tet[0][brick].x] = '.';
		}
	}
	return (0);
}
