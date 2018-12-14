/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:34:34 by thzimmer          #+#    #+#             */
/*   Updated: 2018/12/11 16:45:23 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
** Lis le fichier et le renvoie sous la forme d'une chaine de caractères.
*/

static char		*ft_file_read(char const *path)
{
	int		fd;
	int		rd;
	char	buff[513];
	char	*file;
	char	*tmp;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	if (!(file = (char *)malloc(sizeof(char))))
		return (NULL);
	file[0] = '\0';
	while ((rd = read(fd, buff, 512)) > 0)
	{
		buff[rd] = '\0';
		if (!(tmp = ft_strjoin(file, buff)))
			return (NULL);
		ft_strdel(&file);
		file = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (rd < 0 || file[0] == '\0')
		return (NULL);
	if (close(fd) != -1)
		return (file);
	return (NULL);
}

/*
** Fonction auxiliaire de ft_file_checkblock. Reprends l'index de la lecture et
** vérifie chaque ligne en faisant avancer la lecture dans ft_file_checkblock.
*/

static int		ft_file_checkline(char const *file, int *i)
{
	int		count;
	int		lines;

	lines = 0;
	while (file[*i])
	{
		count = 0;
		while (file[*i] != '\n' && file[*i])
		{
			if ((file[*i] != '.' && file[*i] != '#') || count == 4)
				return (0);
			*i = *i + 1;
			count++;
		}
		if ((file[*i] == '\n' || *i == (int)ft_strlen(file)) && count == 4)
		{
			*i = *i + 1;
			lines++;
		}
		else
			return (0);
		if (lines == 4 && (*i == (int)ft_strlen(file) || file[*i] == '\n'))
			return (1);
	}
	return (0);
}

/*
** Appelle checkline et vérifie que le nombre de blocs du fichier est valides.
** Note : Prends le parametre int i pour respecter la norme (25 lignes).
*/

static int		ft_file_checkblock(char const *file, int *block, int i)
{
	int		count;
	int		j;

	i = 0;
	*block = 0;
	while (file[i])
	{
		count = 0;
		j = i - 1;
		while (++j < i + 19)
			if (file[j] == '#')
				count++;
		if (count != 4)
			return (0);
		if (!(ft_file_checkline(file, &i)) || *block > 26)
			return (0);
		*block = *block + 1;
		if (file[i] == '\n')
			i++;
	}
	if (file[i - 2] == '\n')
		return (0);
	if (*block < 27)
		return (1);
	return (0);
}

/*
** Vérifie que le tetriminos désigné par les coordonées est valide.
*/

static int		ft_checktetri(t_coords *pos)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (pos[i].y == pos[j].y + 1 && pos[i].x == pos[j].x)
				count++;
			if (pos[i].y == pos[j].y - 1 && pos[i].x == pos[j].x)
				count++;
			if (pos[i].x == pos[j].x + 1 && pos[i].y == pos[j].y)
				count++;
			if (pos[i].x == pos[j].x - 1 && pos[i].y == pos[j].y)
				count++;
		}
	}
	if (count >= 6)
		return (1);
	return (0);
}

/*
** Vérifie que le fichier fourni est valide et retourne un tableau de structures
** contenant les coordonnées absolues de tous les '#' des tetriminos.
*/

t_coords		**ft_file_getvalid(char const *path, int *block)
{
	int			i;
	int			cycle;
	char		*file;
	t_coords	*pos;
	t_coords	**tetris;

	i = 0;
	if (!(file = ft_file_read(path)) || !(ft_file_checkblock(file, block, i))
		|| !(tetris = (t_coords **)malloc(sizeof(t_coords *) * (*block + 1))))
		return (ft_free_file(file));
	tetris[*block] = NULL;
	cycle = -1;
	while (file[i])
	{
		if (!(pos = ft_coords_pos(file, i, cycle++)) || !(ft_checktetri(pos)))
			return (NULL);
		ft_getcoords(pos, tetris, cycle);
		cycle == *block - 1 ? ft_strdel(&file) : 0;
		if (cycle == *block - 1)
			return (tetris);
		i += 21;
	}
	ft_strdel(&file);
	return (tetris);
}
