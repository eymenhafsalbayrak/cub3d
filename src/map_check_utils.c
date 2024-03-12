/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:22:37 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/12 20:17:32 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	get_int(char **floor, char **ceil, int i, int flag)
{
	int	tmp;

	tmp = 0;
	if (flag == 0 && floor[i])
		tmp = ft_atoi(floor[i]);
	else if (flag == 1 && ceil[i])
		tmp = ft_atoi(ceil[i]);
	return (tmp);
}

void	is_number(char **s1, char **s2, t_game *game)
{
	check_number(s1, s2, game);
	check_number(s2, s1, game);
}

void	cf_valid_extern(t_game *game, char **floor, char **ceil, int i)
{
	int	tmp;
	int	flag;

	tmp = -1;
	flag = 0;
	while (1)
	{
		tmp = get_int(floor, ceil, i, flag);
		if ((tmp < 0 || tmp > 255) || i > 3)
			free_valid(floor, ceil, game);
		if (flag == 0)
			game->map_data.floor_val[i] = tmp;
		if (flag == 1)
			game->map_data.ceil_val[i] = tmp;
		if (floor[i] == NULL && flag == 0)
		{
			flag = 1;
			i = -1;
		}
		if (i != -1 && ceil[i] == NULL)
			break ;
		++i;
	}
}

void	cf_valid(t_game *game, char **floor, char **ceil)
{
	is_number(floor, ceil, game);
	game->map_data.ceil_val = malloc(sizeof(int) * 3);
	if (!game->map_data.ceil_val)
	{
		free_double(floor);
		free_double(ceil);
		free_all(game);
	}
	game->map_data.floor_val = malloc(sizeof(int) * 3);
	if (!game->map_data.floor_val)
	{
		free(game->map_data.ceil_val);
		free_double(floor);
		free_double(ceil);
		free_all(game);
	}
	cf_valid_extern(game, floor, ceil, 0);
}
