/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_mouse_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:13:28 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/17 15:56:34 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	second_win(fdf_t *map)
{
	map->window1 = mlx_new_window(map->mlx_ptr, 800, 200, "HELP");
	mlx_string_put(map->mlx_ptr, map->window1, 0, 0, 0xccffff,
	"1. PRESS buttons 'UP', 'LEFT',");
	mlx_string_put(map->mlx_ptr, map->window1, 310, 0, 0xccccff,
	"'RIGHT', 'DOWN', if you want to move map,");
	mlx_string_put(map->mlx_ptr, map->window1, 0, 40, 0xcc99ff,
	"or 'W', 'A', 'D', 'S'.");
	mlx_string_put(map->mlx_ptr, map->window1, 0, 80, 0xcc66ff,
	"2. PRESS buttons '+', '-', ");
	mlx_string_put(map->mlx_ptr, map->window1, 270, 80, 0xcc33ff,
	"if you want to zoom up or down map.");
	mlx_string_put(map->mlx_ptr, map->window1, 0, 120, 0xcc00ff,
	"3. PRESS 'ESC', ");
	mlx_string_put(map->mlx_ptr, map->window1, 160, 120, 0x9933cc,
	"if you want to exit.");
}

int		key_press(int key_code, fdf_t *map)
{
	if (key_code == 8)
	{
		if (map->change_color == 3)
			map->change_color = 0;
		map->change_color += 1;
	}
	if (key_code == 6)
		map->rotate_z += 1;
	if (key_code == 16)
		map->rotate_y += 1;
	if (key_code == 7)
		map->rotate_x += 1;
	if (key_code == 125 || key_code == 1)
		map->move_y += 20;
	if (key_code == 126 || key_code == 13)
		map->move_y -= 20;
	if (key_code == 123 || key_code == 0)
		map->move_x -= 20;
	if (key_code == 124 || key_code == 2)
		map->move_x += 20;
	if (key_code == 53)
		exit(0);
	if (key_code == 69)
		map->zoom += 5;
	if (key_code == 78 && map->zoom > 0)
		map->zoom -= 5;
	if (key_code == 4)
		second_win(map);
	if (key_code == 83)
	{
		map->alpha = 0;
		map->rotate_x = 0;
		map->rotate_y = 0;
		map->rotate_z = 0;
	}
	if (key_code == 84)
	{
		map->rotate_x = 0;
		map->rotate_y = 0;
		map->alpha = 0.523599;
	}
	if (key_code == 85)
	{
		map->rotate_x = 0;
		map->rotate_y = 0;
		map->alpha = 7;	
	}
	mlx_clear_window(map->mlx_ptr, map->window);
	draw_map(map);
	mlx_string_put(map->mlx_ptr, map->window, 10, 10, 0xfff000, "HELP");
	mlx_string_put(map->mlx_ptr, map->window, 60, 10, 0xfff000, "(Press 'H')");
	return (0);
}

int		mouse_press(int button, int x, int y, fdf_t *map)
{
	if (button == 1 && x > 10 && x < 30 && y > 10 && y < 30)
		second_win(map);
	if (button == 4 && x > 0 && x < 1000 && y > 0 && y < 1000)
		map->zoom += 10;
	if (button == 5)
		map->zoom -= 10;
	return (0);
}
