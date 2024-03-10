/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:22:47 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/10 15:33:42 by ealbayra         ###   ########.fr       */
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
