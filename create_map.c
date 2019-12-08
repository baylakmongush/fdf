/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:32:48 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/08 20:57:27 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		add_color_to_list(int size, char *line, int i, int z)
{
	char	color_hex[size];
	int		n;

	n = 0;
	while (n < size)
	{
		color_hex[n] = line[i];
		n++;
		i++;
	}
	//color_hex[n] = '\0';
/*	n = 2;
	while (n < size)
	{
		printf("%c ", color_hex[n]);
		n++;
	}
	printf("\n");*/
	return (i);
}

void		ft_makestruct(fdf_t **map_struct, int **map, int width, int height)
{
	*map_struct = (fdf_t*)malloc(sizeof(fdf_t));
	(*map_struct)->height = height;
	(*map_struct)->map = map;
	(*map_struct)->width = width;
}

static int	*ft_splitstring(char *line, int min_count)
{
	int		*str_int;
	int		i;
	int		j;
	int		count;
	char	*color_hex;
	int		n;

	str_int = (int*)malloc(sizeof(int) * min_count);
	i = -1;
	j = -1;
	while (line[++i] && j < min_count)
	{
		if (line[i] != 32)
		{
			if ((line[i - 1] >= '0' && line[i - 1] <= '9') ||
(line[i - 1] >= 'a' && line[i - 1] <= 'z') ||
(line[i - 1] >= 'A' && line[i - 1] <= 'Z') || (line[i - 1] == ','))
			{
				//	head->z = str_int[j];
			//	i++;
				count = 0;
				while (line[i] != 32)
				{
					i++;
					count++;
				}
				i = i - count;
				//	ft_getcurr(str_int[j], color_hex, archive);*/
				i = add_color_to_list(count, line, i, str_int[j]);
			//	i++;
			//	printf("%d", i);
			}
				else
					str_int[++j] = ft_atoi(&line[i]);
		}
	}
	return (str_int);
}

static int	ft_count_hex(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (line[i] == ',')
			{
				while (line[i] != ' ')
				{
					i++;
					count++;
				}
			}
		}
		i++;
	}
	return (count);
}

static int	ft_count_space(char *line)
{
	int		space;
	int		i;

	i = 0;
	space = 0;
	while (line[i])
	{
		if (line[i] == 32)
			space++;
		i++;
	}
	return (space);
}

static int	ft_found_min(int str_min_count_fd[3])
{
	if (str_min_count_fd[0] == 1)
		str_min_count_fd[1] = str_min_count_fd[2];
	if (str_min_count_fd[2] < str_min_count_fd[1])
		str_min_count_fd[1] = str_min_count_fd[2];
	return (str_min_count_fd[1]);
}

void		ft_createmap(fdf_t **map_struct, char *file)
{
	int		**map;
	char	*line;
	int		str_min_count_fd[4];
	int		count_hex;

	str_min_count_fd[0] = 0;
	str_min_count_fd[3] = open(file, O_RDONLY);
	while (get_next_line(str_min_count_fd[3], &line) > 0)
	{
	//	count_hex = ft_count_hex(line);
	//	printf("count hex = %d\n", count_hex);
	//	str_min_count_fd[2] = ft_strlen(line) - ft_count_space(line);
		str_min_count_fd[0]++;
	//	str_min_count_fd[1] = ft_found_min(str_min_count_fd);
	//	printf("min = %d ", str_min_count_fd[1]);
		free(line);
	}
	close(str_min_count_fd[3]);
	str_min_count_fd[1] = 500;
	map = (int**)malloc(sizeof(int*) * str_min_count_fd[0]);
	str_min_count_fd[3] = open(file, O_RDONLY);
	str_min_count_fd[2] = 0;
	while (get_next_line(str_min_count_fd[3], &line) > 0)
	{
		map[str_min_count_fd[2]++] = ft_splitstring(line, str_min_count_fd[1]);
		free(line);
	}
	close(str_min_count_fd[3]);
	ft_makestruct(map_struct, map, str_min_count_fd[1], str_min_count_fd[0]);
}
