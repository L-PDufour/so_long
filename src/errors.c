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

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_game_struct(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_array)
		free_array(game->map_array);
	if (game->tmp_map)
		free_array(game->tmp_map);
	if (game->tmp != NULL)
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
