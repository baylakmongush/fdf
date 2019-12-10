/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_mouse_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:33:42 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/10 16:55:45 by baylak           ###   ########.fr       */
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
	if (key_code == 125 || key_code == 1)
		map->move_y += 10;
	if (key_code == 126 || key_code == 13)
		map->move_y -= 10;
	if (key_code == 123 || key_code == 0)
		map->move_x -= 10;
	if (key_code == 124 || key_code == 2)
		map->move_x += 10;
	if (key_code == 53)
		exit(0);
	if (key_code == 4)
		second_win(map);
	draw_map(map);
	mlx_clear_window(map->mlx_ptr, map->window);
	mlx_string_put(map->mlx_ptr, map->window, 10, 10, 0xfff000, "HELP");
	mlx_string_put(map->mlx_ptr, map->window, 60, 10, 0xfff000, "(Press 'H')");
	return (0);
}

int		mouse_press(int button, int x, int y, fdf_t *map)
{
	if (button == 1 && x > 10 && x < 30 && y > 10 && y < 30)
		map->window1 = mlx_new_window(map->mlx_ptr, 500, 500, "FDF");
	return (0);
}
