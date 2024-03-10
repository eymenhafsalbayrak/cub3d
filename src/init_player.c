/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:05:54 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/10 15:33:29 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <stdlib.h>

void	find_positon(t_player *player, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				player->pos_x += j;
				player->pos_y += i;
				player->way = game->map[i][j];
				break ;
			}
			++j;
		}
		j = 0;
		++i;
	}
}

void	check_positon(t_game *game)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
				++a;
			++j;
		}
		j = 0;
		++i;
	}
	if (a > 1)
	{
		free_all(game);
		ft_exit("error: there is more than one player");
	}
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		exit(1);
	game->player->pos_x = 0.5;
	game->player->pos_y = 0.5;
	game->player->dir_x = 0;
	game->player->dir_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0;
	game->player->rot_speed = 0.04;
	game->player->speed = 0.03;
	find_positon(game->player, game);
	check_positon(game);
}
