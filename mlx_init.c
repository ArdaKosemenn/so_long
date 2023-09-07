/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:22:18 by mkosemen          #+#    #+#             */
/*   Updated: 2023/06/18 15:22:18 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_init_start(t_long *map)
{
	map->p_move_count = 0;
	map->mlx_init = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx_init, 64 * map->x_size,
			64 * map->line_size, "SO_LONG");
	mlx_get_image(map);
}

void	mlx_get_image(t_long *map)
{
	map->w_img = mlx_xpm_file_to_image(map->mlx_init,
			"./img/wall.xpm", &map->width, &map->height);
	map->e_img = mlx_xpm_file_to_image(map->mlx_init,
			"./img/finish.xpm", &map->width, &map->height);
	map->p_img = mlx_xpm_file_to_image(map->mlx_init,
			"./img/mario.xpm", &map->width, &map->height);
	map->c_img = mlx_xpm_file_to_image(map->mlx_init,
			"./img/coin.xpm", &map->width, &map->height);
	map->b_img = mlx_xpm_file_to_image(map->mlx_init,
			"./img/emptywall.xpm", &map->width, &map->height);
	if (!map->w_img || !map->e_img || !map->p_img || !map->c_img || !map->b_img)
	{
		ft_putstr_fd("MLX_ERROR\n", 2);
		exit(0);
	}
}

void	mlx_put_img(t_long *map)
{
	int		i;
	int		k;

	k = 0;
	while (map->map_line[k])
	{
		i = 0;
		while (map->map_line[k][i])
		{
			if (map->map_line[k][i] == '\n')
				break ;
			if (map->map_line[k][i] == 'P')
				ft_img(map, map->p_img, map->p_x_loca, map->p_y_loca);
			if (map->map_line[k][i] == '0')
				ft_img(map, map->b_img, i * 64, k * 64);
			if (map->map_line[k][i] == '1')
				ft_img(map, map->w_img, i * 64, k * 64);
			if (map->map_line[k][i] == 'C')
				ft_img(map, map->c_img, i * 64, k * 64);
			if (map->map_line[k][i] == 'E')
				ft_img(map, map->e_img, map->e_x_loca, map->e_y_loca);
			i++;
		}
		k++;
	}
}

void	ft_img(t_long *map, void *img, int i, int k)
{
	mlx_put_image_to_window(map->mlx_init, map->mlx_win, img, i, k);
}

void	refresh_map(t_long *map)
{
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->move = ft_itoa(map->p_move_count);
	mlx_put_img(map);
	mlx_string_put(map->mlx_init, map->mlx_win,
		15, 15, 0xffffff, map->move);
	free(map->move);
}
