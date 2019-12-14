/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:13:18 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/14 19:18:10 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_point current, t_point start, t_point end, t_point delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}*/

static void		iso(int *x, int *y, int z, double alpha)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(alpha);
	*y = -z + (previous_x + previous_y) * sin(alpha);
}

static void		rotate_x(int *y, int *z, int multi, double alpha)
{
	int			previous_y;
	int			previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(multi * alpha) + previous_z * sin(multi * alpha);
	*z = -previous_y * sin(multi * alpha) + previous_z * cos(multi * alpha);
}

static void		rotate_y(int *x, int *z, int multi, double alpha)
{
	int			previous_x;
	int			previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(multi * alpha) + previous_z * sin(multi * alpha);
	*z = -previous_x * sin(multi * alpha) + previous_z * cos(multi * alpha);
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
	int			color1;
	int			color2;

	z1 = map_struct->map[y1][x1].list.z * map_struct->zoom;
	z2 = map_struct->map[y2][x2].list.z * map_struct->zoom;
	map_struct->color = (z1 || z2) ? 0x800080 : 0xffffff;
	if (map_struct->map[y1][x1].list.color > 0 || map_struct->map[y2][x2].list.color > 0)
		map_struct->color = map_struct->map[y1][x1].list.color;
	x1 *= map_struct->zoom;
	y1 *= map_struct->zoom;
	x2 *= map_struct->zoom;
	y2 *= map_struct->zoom;
	rotate_x(&y1, &z1, map_struct->rotate_x, map_struct->alpha);
	rotate_x(&y2, &z2, map_struct->rotate_x, map_struct->alpha);
	rotate_y(&x1, &z1, map_struct->rotate_y, map_struct->alpha);
	rotate_y(&x2, &z2, map_struct->rotate_y, map_struct->alpha);
	if (map_struct->alpha == 0.523599 || map_struct->alpha == 0)
	{
		iso(&x1, &y1, z1, map_struct->alpha);
		iso(&x2, &y2, z2, map_struct->alpha);
	}
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
				draw_line(i, j, i + 1, j, map_struct);
			if (j < map_struct->height - 1)
				draw_line(i, j,	i, j + 1, map_struct);
			i++;
		}
		j++;
	}
}
