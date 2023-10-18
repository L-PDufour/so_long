/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:08:32 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/18 08:08:32 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

void	free_map_struct(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_array[i] != NULL)
	{
		while (map->map_array[i] != NULL)
		{
			free(map->map_array[i]);
			i++;
		}
		free(map->map_array);
	}
	free(map);
}

void	exit_map_at_error(char *str, t_map *map)
{
	printf("Error\n");
	if (str)
		printf("%s\n", str);
	free_map_struct(map);
	exit(EXIT_FAILURE);
}
