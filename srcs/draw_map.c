/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:13:18 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/23 22:12:10 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		iso(int *x, int *y, int z, double alpha)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(alpha);
	*y = -z + (previous_x + previous_y) * sin(alpha);
}

static void		draw_pix(coord xyz, fdf_t *map)
{
	int			delta_x_y[2];
	int			sign_x_y[2];
	int			error1_2[2];

	delta_x_y[0] = abs(xyz.x2 - xyz.x1);
	delta_x_y[1] = abs(xyz.y2 - xyz.y1);
	sign_x_y[0] = xyz.x1 < xyz.x2 ? 1 : -1;
	sign_x_y[1] = xyz.y1 < xyz.y2 ? 1 : -1;
	error1_2[0] = delta_x_y[0] - delta_x_y[1];
	mlx_pixel_put(map->mlx_ptr, map->window, xyz.x2, xyz.y2, map->color);
	while ((xyz.x1 - xyz.x2) || (xyz.y1 - xyz.y2))
	{
		mlx_pixel_put(map->mlx_ptr, map->window, xyz.x1, xyz.y1, map->color);
		error1_2[1] = error1_2[0] * 2;
		if (error1_2[1] > -delta_x_y[1])
		{
			error1_2[0] -= delta_x_y[1];
			xyz.x1 += sign_x_y[0];
		}
		if (error1_2[1] < delta_x_y[0])
		{
			error1_2[0] += delta_x_y[0];
			xyz.y1 += sign_x_y[1];
		}
	}
}

void			transformation(coord xyz, fdf_t *map_struct)
{
	xyz.x1 *= map_struct->zoom;
	xyz.y1 *= map_struct->zoom;
	xyz.x2 *= map_struct->zoom;
	xyz.y2 *= map_struct->zoom;
	xyz.x1 -= (map_struct->width * map_struct->zoom) / 2;
	xyz.x2 -= (map_struct->width * map_struct->zoom) / 2;
	xyz.y1 -= (map_struct->height * map_struct->zoom) / 2;
	xyz.y2 -= (map_struct->height * map_struct->zoom) / 2;
	rotate_x(&xyz.y1, &xyz.z1, map_struct->rotate_x, map_struct->alpha);
	rotate_x(&xyz.y2, &xyz.z2, map_struct->rotate_x, map_struct->alpha);
	rotate_y(&xyz.x1, &xyz.z1, map_struct->rotate_y, map_struct->alpha);
	rotate_y(&xyz.x2, &xyz.z2, map_struct->rotate_y, map_struct->alpha);
	rotate_z(&xyz.x1, &xyz.y1, map_struct->rotate_z, map_struct->alpha);
	rotate_z(&xyz.x2, &xyz.y2, map_struct->rotate_z, map_struct->alpha);
	if (map_struct->alpha == 0.523599 || map_struct->alpha == 0)
	{
		iso(&xyz.x1, &xyz.y1, xyz.z1, map_struct->alpha);
		iso(&xyz.x2, &xyz.y2, xyz.z2, map_struct->alpha);
	}
	xyz.x1 += map_struct->move_x;
	xyz.y1 += map_struct->move_y;
	xyz.x2 += map_struct->move_x;
	xyz.y2 += map_struct->move_y;
	draw_pix(xyz, map_struct);
}

void			draw_line(coord xyz, fdf_t *map_struct)
{
	int			z1;
	int			z2;
	int			max;
	int			palette[4];
	int			palette1[4];

	palette[0] = 0x2196f3;
	palette[1] = 0xf44336;
	palette[2] = 0xFF5F6D;
	palette[3] = 0xFFC371;
	palette1[0] = 0xCB3066;
	palette1[1] = 0xEECDA3;
	palette1[2] = 0xEF629F;
	palette1[3] = 0x66ff00;
	xyz.z1 = map_struct->map[xyz.y1][xyz.x1].list.z * map_struct->zoom;
	xyz.z2 = map_struct->map[xyz.y2][xyz.x2].list.z * map_struct->zoom;
	map_struct->color = (xyz.z1 || xyz.z2) ?
	palette[map_struct->change_color] : palette1[map_struct->change_color];
	if (map_struct->map[xyz.y1][xyz.x1].list.color > 0 ||
	map_struct->map[xyz.y2][xyz.x2].list.color > 0)
		map_struct->color = map_struct->map[xyz.y1][xyz.x1].list.color;
	transformation(xyz, map_struct);
}

void			draw_map(fdf_t *map_struct)
{
	int			i_j[2];
	coord		xyz;

	i_j[1] = -1;
	while (++i_j[1] < map_struct->height)
	{
		i_j[0] = -1;
		while (++i_j[0] < map_struct->width)
		{
			xyz.x1 = i_j[0];
			xyz.y1 = i_j[1];
			if (i_j[0] < map_struct->width - 1)
			{
				xyz.x2 = i_j[0] + 1;
				xyz.y2 = i_j[1];
				draw_line(xyz, map_struct);
			}
			if (i_j[1] < map_struct->height - 1)
			{
				xyz.x2 = i_j[0];
				xyz.y2 = i_j[1] + 1;
				draw_line(xyz, map_struct);
			}
		}
	}
}
