/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:52:44 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/10 21:05:10 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// gcc -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit main.c libft/libft.a
// gcc -I minilibx_macos minilibx_macos/libmlx.a -framework OpenGL -framework Appkit main.c libft/libft.a

int			main(int argc, char **argv)
{
	fdf_t	*map_struct;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		color;

	if (argc == 2)
	{
		check_valid(argv[1]);
		ft_createmap(&map_struct, argv[1]);
		map_struct->mlx_ptr = mlx_init();
		map_struct->window = mlx_new_window(map_struct->mlx_ptr, 1000, 1000, "FDF");
		map_struct->move_y = 200;
		map_struct->move_x = 200;
		map_struct->zoom = 1;
		draw_map(map_struct);
		mlx_key_hook(map_struct->window, key_press, map_struct);
		mlx_string_put(map_struct->mlx_ptr, map_struct->window, 10, 10, 0xfff00f, "HELP");
		mlx_string_put(map_struct->mlx_ptr, map_struct->window, 60, 10, 0xfff000, "(Press 'H')");
	//	printf("width = %d\n", map_struct->width);
	//	printf("height = %d", map_struct->height);
		//	mlx_string_put(map_struct->mlx_ptr, map_struct->window1, 10, 10, 0xfff00f, "HELP");
		//	mlx_mouse_hook(map_struct->window, mouse_press, map_struct);
		//	mlx_key_hook(map_struct->window1, key_press1, map_struct);
		//	mlx_string_put(map_struct->mlx_ptr, map_struct->window1, 10, 10, 0xfff00f, "HELP");
		mlx_loop(map_struct->mlx_ptr);
	}
	else
		ft_err();
	return (0);
}