/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:43:31 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/23 12:45:18 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_game *game, int x, int y, int *collectible)
{
	if (x < 1 || x > game->map_coordinates.x || y < 1
		|| y > game->map_coordinates.y)
		return ;
	if (game->nb_exit == 0 && collectible == 0)
		return;
	if (game->tmp_map[y][x] == WALL)
		return ;
	if (game->tmp_map[y][x] == COLLECTIBLE)
		(*collectible)--;
	if (game->tmp_map[y][x] == EXIT)
		game->nb_exit--;
	game->tmp_map[y][x] = '1';
	flood_fill(game, x, y - 1, collectible);
	flood_fill(game, x + 1, y, collectible);
	flood_fill(game, x, y + 1, collectible);
	flood_fill(game, x - 1, y, collectible);
}

void	flood_fill_init(t_game *game)
{
	char		**tmp_map;
	int			i;
	static int	collectible;

	i = 0;
	collectible = game->nb_collectible;
	game->tmp_map = ft_split(game->tmp, '\n');
	// printf("%i , %i\n", game->character.x, game->character.y);
	// while (game->tmp_map[i])
	// {
	// 	printf("%s\n", game->tmp_map[i]);
	// 	i++;
	// }
	flood_fill(game, game->character.x, game->character.y, &collectible);
	// printf("exit =%i, collectible B: %i A: %i\n", game->nb_exit,
			// game->nb_collectible, collectible);
	if (game->nb_exit != 0 || collectible != 0)
		exit_game_at_error("Invalid path", game);
	// i = 0;
	// printf("\n");
	// while (game->tmp_map[i])
	// {
	// 	printf("%s\n", game->tmp_map[i]);
	// 	i++;
	// }
}
