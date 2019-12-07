/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:30:52 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/02 19:15:57 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.5);
	*y = -z + (previous_x + previous_y) * sin(0.5);
}

static void		draw_pix(int x1, int y1, int x2, int y2, fdf_t *map)
{
	int			delta_x_y[2];
	int			sign_x_y[2];
	int			error1_2[2];

	delta_x_y[0] = abs(x2 - x1);
	delta_x_y[1] = abs(y2 - y1);
	sign_x_y[0] = x1 < x2 ? 1 : -1;
	sign_x_y[1] = y1 < y2 ? 1 : -1;
	error1_2[0] = delta_x_y[0] - delta_x_y[1];
	mlx_pixel_put(map->mlx_ptr, map->window, x2, y2, map->color);
	while ((x1 - x2) || (y1 - y2))
	{
		mlx_pixel_put(map->mlx_ptr, map->window, x1, y1, map->color);
		error1_2[1] = error1_2[0] * 2;
		if (error1_2[1] > -delta_x_y[1])
		{
			error1_2[0] -= delta_x_y[1];
			x1 += sign_x_y[0];
		}
		if (error1_2[1] < delta_x_y[0])
		{
			error1_2[0] += delta_x_y[0];
			y1 += sign_x_y[1];
		}
	}
}

void			draw_line(int x1, int y1, int x2, int y2, fdf_t *map_struct)
{
	int			z1;
	int			z2;
	int			max;

	z1 = (map_struct->map[y1 / map_struct->zoom]
	[x1 / map_struct->zoom]) * map_struct->zoom;
	z2 = map_struct->map[y2 / map_struct->zoom]
	[x2 / map_struct->zoom] * map_struct->zoom;
	map_struct->color = (z1 || z2) ? 0x800080 : 0xffffff;
	iso(&x1, &y1, z1);
	iso(&x2, &y2, z2);
	x1 += map_struct->move_x;
	y1 += map_struct->move_y;
	x2 += map_struct->move_x;
	y2 += map_struct->move_y;
	draw_pix(x1, y1, x2, y2, map_struct);
}

void			draw_map(fdf_t *map_struct)
{
	int			i;
	int			j;
	int			z1;
	int			z2;

	j = 0;
	while (j < map_struct->height)
	{
		i = 0;
		while (i < map_struct->width)
		{
			if (i < map_struct->width - 1)
				draw_line(i * map_struct->zoom, j * map_struct->zoom,
				(i + 1) * map_struct->zoom, j * map_struct->zoom, map_struct);
			if (j < map_struct->height - 1)
				draw_line(i * map_struct->zoom, j * map_struct->zoom,
				i * map_struct->zoom, (j + 1) * map_struct->zoom, map_struct);
			i++;
		}
		j++;
	}
}
