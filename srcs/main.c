/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:52:44 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/23 23:02:59 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_clear(tmap **map)
{
	tmap	**tmp;

	tmp = map;
	while (map && *map)
		free(*map++);
	free(map);
	map = NULL;
}

int			main(int argc, char **argv)
{
	fdf_t	*map_struct;
	int		height;

	if (argc == 2)
	{
		height = check_valid(argv[1]);
		ft_createmap(&map_struct, argv[1]);
		map_struct->mlx_ptr = mlx_init();
		map_struct->window = mlx_new_window(map_struct->mlx_ptr, 1500,
		1500, "FDF");
		init_map(&map_struct);
		draw_map(map_struct);
		mlx_key_hook(map_struct->window, key_press, map_struct);
		mlx_string_put(map_struct->mlx_ptr, map_struct->window, 10, 10,
		0xfff00f, "HELP");
		mlx_string_put(map_struct->mlx_ptr, map_struct->window, 60, 10,
		0xfff000, "(Press 'H' or Click HELP)");
		mlx_mouse_hook(map_struct->window, mouse_press, map_struct);
		mlx_loop(map_struct->mlx_ptr);
		ft_clear(map_struct->map);
		free(map_struct);
	}
	else
		ft_err();
	return (0);
}