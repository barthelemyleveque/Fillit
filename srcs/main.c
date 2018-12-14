/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:20:14 by thzimmer          #+#    #+#             */
/*   Updated: 2018/12/14 10:49:10 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Crée un tableau de structure contenant les coordonées des 4 prochains
** '#' dans le fichier en partant du début d'un bloc (donné par index).
*/

t_coords		*ft_coords_pos(char const *file, int index, int corr)
{
	int			j;
	int			k;
	int			line;
	t_coords	*pos;

	k = 0;
	line = 1;
	j = 19 + index--;
	if (!(pos = (t_coords *)malloc(sizeof(t_coords) * 4)))
		return (NULL);
	while (++index < j)
	{
		if (file[index] == '\n')
			line++;
		if (file[index] == '#')
		{
			pos[k].x = (index - corr) % 5;
			pos[k++].y = line;
		}
	}
	return (pos);
}

/*
** Ecris dans "tetris" les coordonnées relatives des briques en fonction de la
** première brique rencontrée (brique la plus en haut la plus à gauche).
*/

void			ft_getcoords(t_coords *pos, t_coords **tetris, int cycle)
{
	int			i;

	if (!(tetris[cycle] = (t_coords *)malloc(sizeof(t_coords) * 4)))
		return ;
	tetris[cycle][0].x = 0;
	tetris[cycle][0].y = 0;
	i = 0;
	while (++i < 4)
	{
		tetris[cycle][i].x = pos[i].x - pos[0].x;
		tetris[cycle][i].y = pos[i].y - pos[0].y;
	}
	free(pos);
}

/*
** Affichage des erreurs et explications génériques en cas de mauvais nombre
** d'arguments.
*/

static int		ft_error(int errorcode)
{
	if (errorcode == 1)
		ft_putendl("error");
	if (errorcode == 2)
	{
		ft_putstr("\n    \033[31;1mAn error occured, please check your");
		ft_putstr(" input again.\033[0m\n\nusage :  ");
		ft_putstr("\033[32;1muser@local\033[0m:\033[36;1m~/fillit\033[0m$");
		ft_putstr(" ./fillit </path/to/file>\n\n");
		ft_putstr("\tTetriminos in file are separated by a \\n.\n\n\t\t\033");
		ft_putstr("[30;1m    #\t\t\033[34;1m  #\t\033[33;1m# #\n\t\033[36;");
		ft_putstr("1m # # # #  \033[30;1m  # # #    \033[34;1m # # #    \033[");
		ft_putstr("33;1m # #\n\n\t\t \033[32;1m# #  \033[35;1m   #   \033[3");
		ft_putstr("1;1m   # #\n\t\033[32;1m       # #  \033[35;1m   # # #  ");
		ft_putstr("  \033[31;1m  # #\n\n\t\t\033[37;1m_____________________\n");
		ft_putstr("\n\t\033[37;1m  . . . .     . \033[33;1m# # \033[37;1m.   ");
		ft_putstr("  . . . .\n\t  . \033[35;1m# # #\033[37;1m     . \033[33;1");
		ft_putstr("m# # \033[37;1m.     . . . .\n\t  . . \033[35;1m#\033[37;1");
		ft_putstr("m .     . . . .     . . .   \033[0m\033[31;1m<- no dot!\n");
		ft_putstr("\033[37;1m\t  . . . .     . . . .     \033[36;1m# # # #\n ");
		ft_putstr("\n\033[32;1m\t  \xE2\x9C\x93 Valid     \xE2\x9C\x93 Valid ");
		ft_putstr("\033[31;1m    × Error\033[0m\n");
	}
	return (0);
}

/*
** Vérification de l'input et initialisation des coordonées et de la map.
** La variable blocks représente le nombre de tétriminos en entrée.
*/

static t_coords	**ft_coords_init(char const *path, char ***map, int *maplen)
{
	int			blocks;
	t_coords	**tet;

	if (!(tet = ft_file_getvalid(path, &blocks)))
		return (0);
	*maplen = ft_sqrt_next(blocks * 4);
	if (!(map[0] = ft_map_init(*maplen)))
		return (0);
	return (tet);
}

/*
** Vérification et affectation des coordonnées dans "tetris", récursivité puis
** affichage de la solution et libération de la mémoire. Affiche usage si pas
** ou trop d'arguments.
*/

int				main(int argc, char **argv)
{
	t_coords	**tetris;
	char		**map;
	int			maplen;
	int			i;

	if (argc == 2)
	{
		if (!(tetris = ft_coords_init(argv[1], &map, &maplen)))
			return (ft_error(1));
		while (!(ft_findsolution(tetris, map, maplen, 'A')))
			if (!(map = ft_map_extend(map, &maplen)))
				return (ft_error(1));
		i = 0;
		while (map[i])
			ft_putendl(map[i++]);
		while (--i >= 0)
			free(map[i]);
		free(map);
		i = 0;
		while (tetris[i] != NULL)
			free(tetris[i++]);
		free(tetris);
		return (0);
	}
	return (ft_error(2));
}
