/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:43:31 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/17 08:31:12 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill(t_game *game, int x, int y, int *collectible)
{
	if (x < 1 || x > game->map_pos.x || y < 1 || y > game->map_pos.y)
		return ;
	if (game->nb_exit == 0 && collectible == 0)
		return ;
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
	static int	collectible;

	collectible = game->nb_collectible;
	game->tmp_map = ft_split(game->tmp, '\n');
	flood_fill(game, game->character.x, game->character.y, &collectible);
	if (game->nb_exit != 0 || collectible != 0)
		exit_game_at_error("Invalid path", game);
}
