/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_surrounded.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:16:55 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/10 15:33:46 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	horizontal(char **map, int i, int j, int flag)
{
	char	*tmp;

	while (map[++i])
	{
		j = -1;
		flag = 0;
		tmp = ft_strtrim(map[i], " ");
		if (tmp[ft_strlen(tmp) - 1] != '1')
			return (free(tmp), 0);
		free(tmp);
		while (map[i][++j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
			{
				if (map[i][j - 1] && ft_strchr("0NSEW", map[i][j - 1]))
					return (0);
				flag ^= 1;
			}
		}
	}
	return (1);
}

int	vertical(char **map, int i, int j, int flag)
{
	while (map[0][++j])
	{
		flag = 0;
		i = 0;
		while (map[i] && map[i][j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
			{
				if (map[i - 1] && map[i - 1][j]
						&& ft_strchr("0NSEW", map[i - 1][j]))
					return (0);
				flag ^= 1;
			}
			if (!map[i + 1] && ft_strchr("NSEW0", map[i][j]))
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_map_surrounded(t_game *game)
{
	if (!vertical(game->map, -1, -1, 0)
		|| !horizontal(game->map, -1, -1, 0))
	{
		free_all(game);
		ft_exit("error: map is not surrounded by the wall");
	}
	return (1);
}
