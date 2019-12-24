/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 22:03:04 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/24 19:11:35 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_makestruct(fdf_t **map_struct, int width, int height)
{
	*map_struct = (fdf_t*)malloc(sizeof(fdf_t));
	(*map_struct)->height = height;
	(*map_struct)->width = width;
}

static void		*ft_arrdel(void **res)
{
	void		**tmp;

	tmp = res;
	while (res && *res)
		free(*res++);
	free(tmp);
	tmp = NULL;
	return (tmp);
}

static void		ft_copy(fdf_t **map_struct, int fd)
{
	char		*line;
	char		**tmp;
	int			i[3];

	i[0] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		i[1] = -1;
		while (tmp[++i[1]])
		{
			i[2] = -1;
			(*map_struct)->map[i[0]][i[1]].list.z = ft_atoi(tmp[i[1]]);
			while (tmp[i[1]][++i[2]])
			{
				if (tmp[i[1]][i[2]] == ',')
					(*map_struct)->map[i[0]][i[1]].list.color =
					atoi_hex(&tmp[i[1]][i[2]++]);
			}
		}
		ft_arrdel((void**)tmp);
		i[0]++;
		free(line);
	}
}

void			init_map(fdf_t **map_struct)
{
	(*map_struct)->alpha = 0.523599;
	(*map_struct)->move_y = 100;
	(*map_struct)->move_x = 100;
	(*map_struct)->rotate_x = 0;
	(*map_struct)->rotate_y = 0;
	(*map_struct)->rotate_z = 0;
	(*map_struct)->change_color = 0;
	(*map_struct)->zoom = 1;
}

void			ft_createmap(fdf_t **map_struct, char *file)
{
	int			height;
	int			width;
	int			fd;
	char		*line;
	int			j;

	height = check_valid(file);
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	width = count_size(line);
	free(line);
	close(fd);
	ft_makestruct(map_struct, width, height);
	(*map_struct)->map = (tmap**)malloc(sizeof(tmap*) * height);
	j = 0;
	while (j < (*map_struct)->height)
		(*map_struct)->map[j++] = (tmap*)malloc(sizeof(tmap) * width);
	fd = open(file, O_RDONLY);
	ft_copy(map_struct, fd);
	close(fd);
}
