/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:13:38 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/10 21:20:16 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		ft_makestruct(fdf_t **map_struct, int width, int height)
{
	*map_struct = (fdf_t*)malloc(sizeof(fdf_t));
	(*map_struct)->height = height;
	(*map_struct)->width = width;
}

int				count_height(fd)
{
	char 		*line;
	int			height;

	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	return (height);
}

void			ft_copy(fdf_t **map_struct, char *file)
{
	char		*line;
	int			i;
	int			j;
	int			n;
	int			fd;
	int			count;
	char		**tmp;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		j = 0;
		while (tmp[j])
		{
			n = 0;
			count = 0;
			(*map_struct)->map[i][j].list.z = ft_atoi(tmp[j]);
			while (tmp[j][n])
			{
				if (tmp[j][n] == ',')
				{
					n++;
					(*map_struct)->map[i][j].list.color = atoi_hex(&tmp[j][n]);
					count++;
				}
				n++;
			}
			if (count == 0)
				(*map_struct)->map[i][j].list.color = (*map_struct)->map[i][j].list.z ? 0x00ff00 : 0xffffff;
			j++;
		}
		i++;
	//	free(tmp);
		free(line);
	}
	close(fd);
}

void			ft_createmap(fdf_t **map_struct, char *file)
{
	int			height;
	int			width;
	int			fd;
	char		*line;
	tmap		**map;
	int			j;

	fd = open(file, O_RDONLY);
	height = count_height(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	width = count_size(line);
	close(fd);
	ft_makestruct(map_struct, width, height);
	map = (tmap**)malloc(sizeof(tmap*) * height);
	(*map_struct)->map = map;
	j = 0;
	while (j < (*map_struct)->width)
		(*map_struct)->map[j++] = (tmap*)malloc(sizeof(tmap) * width);
	ft_copy(map_struct, file);
}