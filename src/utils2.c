/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:56:03 by ezcakir           #+#    #+#             */
/*   Updated: 2024/03/12 18:58:25 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libft/libft.h"

void	parse_map_utils(t_game *game, int j, int i, char **regex)
{
	while (regex[i])
	{
		game->map[j] = ft_strdup(regex[i]);
		++i;
		++j;
	}
	game->map[j] = NULL;
}
