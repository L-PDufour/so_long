/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:08:32 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/30 13:40:41 by ldufour          ###   ########.fr       */
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
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

void	free_game_struct(t_game *game)
{
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
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_game_struct(game);
	exit(EXIT_FAILURE);
}
