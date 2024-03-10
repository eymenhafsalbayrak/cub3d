/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:45:26 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/10 15:33:15 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	get_addresses(t_game *game)
{
	int	i;

	game->tex->no->addr
		= (int *)mlx_get_data_addr(game->tex->no->img, &i, &i, &i);
	game->tex->so->addr
		= (int *)mlx_get_data_addr(game->tex->so->img, &i, &i, &i);
	game->tex->ea->addr
		= (int *)mlx_get_data_addr(game->tex->ea->img, &i, &i, &i);
	game->tex->we->addr
		= (int *)mlx_get_data_addr(game->tex->we->img, &i, &i, &i);
}

unsigned int	get_color(int *array)
{
	unsigned int	ret;

	ret = (array[0] * 256 * 256)
		+ (array[1] * 256) + (array[2]);
	return (ret);
}

void	init_texture(t_game *game)
{
	game->tex = malloc(sizeof(t_texture));
	if (!game->tex)
		exit(1);
	game->tex->no = malloc(sizeof(t_data));
	if (!game->tex->no)
		exit(1);
	game->tex->so = malloc(sizeof(t_data));
	if (!game->tex->so)
		exit(1);
	game->tex->ea = malloc(sizeof(t_data));
	if (!game->tex->ea)
		exit(1);
	game->tex->we = malloc(sizeof(t_data));
	if (!game->tex->we)
		exit(1);
}

void	convert_xpm(t_game *game)
{
	int	idle;

	init_texture(game);
	game->tex->floorc = get_color(game->map_data.floor_val);
	game->tex->ceilingc = get_color(game->map_data.ceil_val);
	game->tex->no->img = mlx_xpm_file_to_image(game,
			game->map_data.north, &idle, &idle);
	game->tex->so->img = mlx_xpm_file_to_image(game,
			game->map_data.south, &idle, &idle);
	game->tex->ea->img = mlx_xpm_file_to_image(game,
			game->map_data.east, &idle, &idle);
	game->tex->we->img = mlx_xpm_file_to_image(game,
			game->map_data.west, &idle, &idle);
	get_addresses(game);
}

void	player_check(t_game *game, char way)
{
	if (way == 'N')
	{
		game->player->dir_y = -1.00;
		game->player->plane_x = 0.66;
	}
	if (way == 'S')
	{
		game->player->dir_y = 1.00;
		game->player->plane_x = -0.66;
	}
	if (way == 'E')
	{
		game->player->dir_y = 1.00;
		game->player->plane_x = 0.66;
	}
	if (way == 'W')
	{
		game->player->dir_y = -1.00;
		game->player->plane_x = -0.66;
	}
}
