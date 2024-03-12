/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:24:26 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/12 19:48:10 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libft/libft.h"

int	is_valid1(char *str)
{
	static int	north_flag;
	static int	south_flag;
	static int	west_flag;

	if (!ft_strcmp(str, "NO") && north_flag == 0)
	{
		north_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "SO") && south_flag == 0)
	{
		south_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "WE") && west_flag == 0)
	{
		west_flag = 1;
		return (1);
	}
	return (0);
}

int	is_valid2(char *str)
{
	static int	east_flag;
	static int	c_flag;
	static int	f_flag;

	if (!ft_strcmp(str, "EA") && east_flag == 0)
	{
		east_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "C") && c_flag == 0)
	{
		c_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "F") && f_flag == 0)
	{
		f_flag = 1;
		return (1);
	}
	return (0);
}

int	check_and_get(t_game *game, char **regex)
{
	if (is_valid1(regex[0]) || is_valid2(regex[0]))
	{
		if (!ft_strcmp(regex[0], "NO"))
			game->map_data.north = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "SO"))
			game->map_data.south = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "WE"))
			game->map_data.west = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "EA"))
			game->map_data.east = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "C"))
			game->map_data.ceil = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "F"))
			game->map_data.floor = ft_strdup(regex[1]);
	}
	else
		return (0);
	return (1);
}

void	init_all(t_game *game)
{
	init_mlx(game);
	init_map_data(game);
	init_raycasting(game);
	init_draw(game);
	init_key(game);
}
