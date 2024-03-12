/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:29:20 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/12 18:46:40 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

int	pair_map(t_game *game, char **regex)
{
	int		i;
	char	**tmp;

	i = 0;
	while (i < 6 && regex[i])
	{
		tmp = ft_split(regex[i], ' ');
		if (!check_and_get(game, tmp))
		{
			free_double(tmp);
			free_double(regex);
			free_all(game);
			ft_exit("error: invalid map format");
		}
		if (tmp)
			free_double(tmp);
		++i;
	}
	return (i);
}

void	check_c_and_f(t_game *game)
{
	char	**floor;
	char	**ceil;

	floor = ft_split(game->map_data.floor, ',');
	ceil = ft_split(game->map_data.ceil, ',');
	if (!floor || !ceil)
	{
		free_double(ceil);
		free_double(floor);
		free_all(game);
		ft_exit("error: invalid floor or ceil value");
	}
	cf_valid(game, floor, ceil);
	free_double(floor);
	free_double(ceil);
}

bool	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E' || c == ' ')
		return (true);
	return (false);
}

int	check_pairs(t_game *game)
{
	int	fd_north;
	int	fd_south;
	int	fd_east;
	int	fd_west;

	fd_north = open(game->map_data.north, O_RDONLY);
	fd_south = open(game->map_data.south, O_RDONLY);
	fd_east = open(game->map_data.east, O_RDONLY);
	fd_west = open(game->map_data.west, O_RDONLY);
	if (fd_north == -1 || fd_south == -1 || fd_east == -1 || fd_west == -1)
	{
		free_all(game);
		ft_exit("error: texture file cannot found");
	}
	check_c_and_f(game);
	return (close(fd_north), close(fd_south),
		close(fd_east), close(fd_west), 1);
}

void	check_map_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (!is_valid_char(game->map[i][j]))
			{
				free_all(game);
				ft_exit("error: invalid character in map");
			}
			++j;
		}
		j = 0;
		++i;
	}
}
