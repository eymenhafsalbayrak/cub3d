/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:54:30 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/12 19:48:14 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	parse_map(t_game *game, char *map, int len)
{
	int		i;
	int		j;
	char	**regex;

	regex = ft_split(map, '\n');
	i = pair_map(game, regex);
	j = i;
	while (regex[j])
	{
		++len;
		++j;
	}
	game->map = malloc(sizeof(char *) * (len + 1));
	if (!game->map)
	{
		free_double(regex);
		free_all(game);
		return ;
	}
	j = 0;
	parse_map_utils(game, j, i, regex);
	free_double(regex);
}

char	*read_map(char *file, char *map)
{
	int		fd;
	int		status;
	int		i;
	char	*res;

	i = 0;
	status = 1;
	res = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		(free(map), exit(printf("incorrect map\n")));
	while (status != 0)
	{
		status = read(fd, map, 1);
		map[1] = '\0';
		if (i == 0)
			res = ft_strdup(map);
		else
			res = ft_straddchar(res, map);
		++i;
	}
	close(fd);
	return (res);
}

void	map_check(t_game *game)
{
	if (!check_pairs(game))
		exit_game(game);
	init_player(game);
	check_map_surrounded(game);
	check_map_valid(game);
}

void	init_map(t_game *game, char *file)
{
	char	*map;
	char	*data;
	int		len;

	len = 0;
	data = malloc(sizeof(char) * 2);
	if (!data)
		free_all(game);
	map = read_map(file, data);
	free(data);
	init_all(game);
	parse_map(game, map, len);
	map_check(game);
	convert_xpm(game);
	player_check(game, game->player->way);
	free(map);
}
