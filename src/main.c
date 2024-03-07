/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:48:44 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/07 19:49:38 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		printf("Error: this program accept only 2 arguments\n");
	else if (map_name_check(av[1]))
	{
		init_map(&game, av[1]);
		mlx_hook(game.window, 2, 1L << 0, key_press, &game);
		mlx_hook(game.window, 3, 1L << 1, key_relase, &game);
		mlx_hook(game.window, 17, 0, exit_game, &game);
		mlx_do_sync(game.mlx);
		mlx_loop_hook(game.mlx, ray_casting, &game);
		mlx_loop(game.mlx);
	}
	else
		printf("Error: wrong file extension name\n");
	return (0);
}
