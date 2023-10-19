/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:08:32 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/19 10:49:27 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

void	free_game_struct(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_array)
	{
		while (game->map_array[i] != NULL)
		{
			free(game->map_array[i]);
			i++;
		}
	}
	free(game->map_array);
	if(game->tmp != NULL)
		free(game->tmp);
	free(game);
}

void	exit_game_at_error(char *str, t_game *game)
{
	printf("Error\n");
	if (str)
		printf("%s\n", str);
	free_game_struct(game);
	exit(EXIT_FAILURE);
}
