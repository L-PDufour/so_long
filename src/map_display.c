/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:58:17 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/30 13:58:17 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	delete_collectible(t_game *game, int player_y, int player_x)
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
			}
		}
		game->i++;
	}
}

void	check_move(t_game *game, char pos, int updated_y, int updated_x)
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
	if (game->map_array[(player_y / PIXEL)][(player_x / PIXEL)] == COLLECTIBLE)
	{
		delete_collectible(game, player_y, player_x);
	}
	if (pos == 'y')
		game->o.hero_i->instances->y += updated_y;
	if (pos == 'x')
		game->o.hero_i->instances->x += updated_x;
	game->movement++;
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		check_move(game, 'y', -PIXEL, 0);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		check_move(game, 'y', PIXEL, 0);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		check_move(game, 'x', 0, -PIXEL);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		check_move(game, 'x', 0, PIXEL);
	printf("movement = %i\n", game->movement);
}

void	display_image(t_game *game)
{
	game->j = -1;
	while (++game->j <= game->map_pos.y)
	{
		game->i = -1;
		while (++game->i < game->map_pos.x)
		{
			render_images(game, game->i, game->j);
		}
	}
	game->j = -1;
	while (++game->j <= game->map_pos.y)
	{
		game->i = -1;
		while (++game->i < game->map_pos.x)
		{
			if (game->map_array[game->j][game->i] == PLAYER)
				mlx_image_to_window(game->mlx, game->o.hero_i, game->i * PIXEL,
					game->j * PIXEL);
		}
	}
}

void	print_maps(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_set_window_pos(game->mlx, 0, 0);
	mlx_set_window_size(game->mlx, game->map_pos.x * PIXEL, (game->map_pos.y
			+ 1) * PIXEL);
	rendering_textures_to_images(game);
	display_image(game);
	mlx_key_hook(game->mlx, (void *)ft_hook, (void *)game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
