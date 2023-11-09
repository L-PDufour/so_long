/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:52:44 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/06 13:52:44 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	do_enemy_move(t_game *game, char pos, int updated_y, int updated_x)
{
	int	enemy_y;
	int	enemy_x;
	int	map_y;
	int	map_x;

	enemy_y = game->o.enemy_i->instances->y + updated_y;
	enemy_x = game->o.enemy_i->instances->x + updated_x;
	map_y = (game->map_pos.y - 1) * PIXEL;
	map_x = (game->map_pos.x - 2) * PIXEL;
	if (enemy_y > map_y || enemy_y < PIXEL || enemy_x > map_x
		|| enemy_x < PIXEL)
		return ;
	else if (game->map_array[(enemy_y / PIXEL)][(enemy_x / PIXEL)] == WALL)
		return ;
	if (pos == 'y')
		game->o.enemy_i->instances->y += updated_y;
	if (pos == 'x')
		game->o.enemy_i->instances->x += updated_x;
}

void	pathfinding(t_game *game, int player_y, int player_x)
{
	int	enemy_y;
	int	enemy_x;
	int	map_y;
	int	map_x;

	map_y = (game->map_pos.y - 1) * PIXEL;
	map_x = (game->map_pos.x - 2) * PIXEL;
	enemy_y = game->o.enemy_i->instances->y;
	enemy_x = game->o.enemy_i->instances->x;
	if (enemy_y > map_y || enemy_y < PIXEL || enemy_x > map_x
		|| enemy_x < PIXEL)
		return ;
	if ((abs((enemy_x - 1) - player_x) < abs(enemy_x - player_x))
		&& game->map_array[enemy_y / PIXEL][(enemy_x - 1) / PIXEL] != WALL)
		do_enemy_move(game, 'x', 0, -64);
	else if ((abs((enemy_x + 1) - player_x) < abs(enemy_x - player_x))
		&& game->map_array[enemy_y / PIXEL][(enemy_x + 1) / PIXEL] != WALL)
		do_enemy_move(game, 'x', 0, 64);
	else if ((abs((enemy_y - 1) - player_y) < abs(enemy_y - player_y))
		&& game->map_array[(enemy_y - 1) / PIXEL][enemy_x / PIXEL] != WALL)
		game->o.enemy_i->instances->y -= 64;
	else if ((abs((enemy_y + 1) - player_y) < abs(enemy_y - player_y))
		&& game->map_array[(enemy_y + 1) / PIXEL][enemy_x / PIXEL] != WALL)
		do_enemy_move(game, 'y', 64, 0);
}

void	flood_fill(t_game *game, int x, int y, int *collectible)
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
	char		**tmp_map;
	int			i;
	static int	collectible;

	i = 0;
	collectible = game->nb_collectible;
	game->tmp_map = ft_split(game->tmp, '\n');
	flood_fill(game, game->character.x, game->character.y, &collectible);
	if (game->nb_exit != 0 || collectible != 0)
		exit_game_at_error("Invalid path", game);
}
