/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:38:42 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/10 15:33:51 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <math.h>

void	w_and_k(t_game *game)
{
	if (game->key.wk)
	{
		if (game->map[(int)game->player->pos_y][(int)(game->player->pos_x
			+ game->player->dir_x * game->player->speed)] != 49)
			game->player->pos_x += game->player->dir_x * game->player->speed;
		if (game->map[(int)(game->player->pos_y
				+ game->player->dir_y
				* game->player->speed)][(int)game->player->pos_x] != 49)
			game->player->pos_y += game->player->dir_y * game->player->speed;
	}
	if (game->key.sk)
	{
		if (game->map[(int)game->player->pos_y][(int)(game->player->pos_x
			- game->player->dir_x * game->player->speed)] != 49)
			game->player->pos_x -= game->player->dir_x * game->player->speed;
		if (game->map[(int)(game->player->pos_y
				- game->player->dir_y
				* game->player->speed)][(int)(game->player->pos_x)] != 49)
			game->player->pos_y -= game->player->dir_y * game->player->speed;
	}
}

void	rotate_camera(t_game *game)
{
	int		factor;
	double	old_dirx;
	double	old_planex;

	factor = -1;
	if (game->key.rk)
		factor = 1;
	if (game->key.rk || game->key.lk)
	{
		old_dirx = game->player->dir_x;
		game->player->dir_x = game->player->dir_x
			* cos(game->player->rot_speed * factor)
			- game->player->dir_y * sin(game->player->rot_speed * factor);
		game->player->dir_y = old_dirx * sin(game->player->rot_speed * factor)
			+ game->player->dir_y * cos(game->player->rot_speed * factor);
		old_planex = game->player->plane_x;
		game->player->plane_x = game->player->plane_x
			* cos(game->player->rot_speed * factor)
			- game->player->plane_y * sin(game->player->rot_speed * factor);
		game->player->plane_y = old_planex
			* sin(game->player->rot_speed * factor)
			+ game->player->plane_y * cos(game->player->rot_speed * factor);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(game);
	if (keycode == 13)
		game->key.wk = true;
	if (keycode == 1)
		game->key.sk = true;
	if (keycode == 0)
		game->key.ak = true;
	if (keycode == 2)
		game->key.dk = true;
	if (keycode == 123)
		game->key.lk = true;
	if (keycode == 124)
		game->key.rk = true;
	return (0);
}

int	key_relase(int keycode, t_game *game)
{
	if (keycode == 13)
		game->key.wk = false;
	if (keycode == 1)
		game->key.sk = false;
	if (keycode == 0)
		game->key.ak = false;
	if (keycode == 2)
		game->key.dk = false;
	if (keycode == 123)
		game->key.lk = false;
	if (keycode == 124)
		game->key.rk = false;
	return (0);
}

void	movements(t_game *game)
{
	rotate_camera(game);
	if (game->key.ak)
	{
		if (game->map[(int)(game->player->pos_y)][(int)(game->player->pos_x
			- game->player->plane_x * game->player->speed)] != 49)
			game->player->pos_x -= game->player->plane_x * game->player->speed;
		if (game->map[(int)(game->player->pos_y - game->player->plane_y
				* game->player->speed)][(int)game->player->pos_x] != 49)
			game->player->pos_y -= game->player->plane_y * game->player->speed;
	}
	if (game->key.dk)
	{
		if (game->map[(int)(game->player->pos_y)][(int)(game->player->pos_x
			+ game->player->plane_x * game->player->speed)] != 49)
			game->player->pos_x += game->player->plane_x * game->player->speed;
		if (game->map[(int)(game->player->pos_y
				+ game->player->plane_y
				* game->player->speed)][(int)(game->player->pos_x)] != 49)
			game->player->pos_y += game->player->plane_y * game->player->speed;
	}
	w_and_k(game);
}
