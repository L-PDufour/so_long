/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:08:28 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/09 11:08:31 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	movement_display(t_game *game)
{
	char	*str;

	mlx_delete_image(game->mlx, game->move_display);
	str = ft_itoa(game->movement++);
	game->move_display = mlx_put_string(game->mlx, str, 0, 0);
	free(str);
}

static void	delete_collectible(t_game *game, int player_y, int player_x)
{
	game->i = 0;
	while (game->i < game->nb_collectible)
	{
		if (game->o.item_i[game->i] != NULL)
		{
			if (game->o.item_i[game->i]->instances != NULL
				&& game->o.item_i[game->i]->instances->y == player_y
				&& game->o.item_i[game->i]->instances->x == player_x)
			{
				mlx_delete_image(game->mlx, game->o.item_i[game->i]);
				game->o.item_i[game->i] = NULL;
				game->item_count++;
			}
		}
		game->i++;
	}
}

static void	check_move(t_game *game, int player_y, int player_x)
{
	int	map_y;
	int	map_x;

	map_y = (game->map_pos.y - 1) * PIXEL;
	map_x = (game->map_pos.x - 2) * PIXEL;
	if (player_y > map_y || player_y < PIXEL || player_x > map_x
		|| player_x < PIXEL)
		return ;
	else if (game->map_array[(player_y / PIXEL)][(player_x / PIXEL)] == WALL)
		return ;
	if (game->map_array[(player_y / PIXEL)][(player_x / PIXEL)] == COLLECTIBLE)
		delete_collectible(game, player_y, player_x);
	else if (game->map_array[(player_y / PIXEL)][(player_x / PIXEL)] == EXIT
			&& game->nb_collectible == game->item_count)
		mlx_close_window(game->mlx);
}

void	do_move(t_game *game, char pos, int updated_y, int updated_x)
{
	int	player_y;
	int	player_x;
	int	map_y;
	int	map_x;

	player_y = game->o.hero_i->instances->y + updated_y;
	player_x = game->o.hero_i->instances->x + updated_x;
	map_y = (game->map_pos.y - 1) * PIXEL;
	map_x = (game->map_pos.x - 2) * PIXEL;
	if (player_y > map_y || player_y < PIXEL || player_x > map_x
		|| player_x < PIXEL)
		return ;
	else if (game->map_array[(player_y / PIXEL)][(player_x / PIXEL)] == WALL)
		return ;
	check_move(game, player_y, player_x);
	if (pos == 'y')
		game->o.hero_i->instances->y += updated_y;
	if (pos == 'x')
		game->o.hero_i->instances->x += updated_x;
	pathfinding(game, player_y, player_x);
	movement_display(game);
}
