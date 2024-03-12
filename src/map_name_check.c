/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:22:47 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/12 18:18:09 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	map_name_check(char *file)
{
	char	*str;

	str = ft_substr(file, ft_strlen(file) - 4, ft_strlen(file));
	if (!ft_strcmp(str, ".cub"))
		return (free(str), 1);
	return (free(str), 0);
}

void	free_valid(char **floor, char **ceil, t_game *game)
{
	free_double(floor);
	free_double(ceil);
	free(game->map_data.ceil_val);
	free(game->map_data.floor_val);
	free_all(game);
	ft_exit("error: value must be in RGB range: 0 - 255");
}

void	free_number(char **s1, char **s2, t_game *game)
{
	free_double(s1);
	free_double(s2);
	free_all(game);
	ft_exit("error: value must be have an integer value");
}

void	check_number(char **s1, char **s2, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i][j])
		{
			if (!ft_isdigit(s1[i][j]))
				free_number(s1, s2, game);
			j++;
		}
		++i;
	}
}

void	check_number2(char **s1, char **s2, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s2[i][j])
		{
			if (!ft_isdigit(s2[i][j]))
				free_number(s1, s2, game);
			j++;
		}
		++i;
	}
}
