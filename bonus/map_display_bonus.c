/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:35:21 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/06 12:35:21 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->o.hero_i->instances->y == game->o.enemy_i->instances->y
		&& game->o.hero_i->instances->x == game->o.enemy_i->instances->x)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		do_move(game, 'y', -PIXEL, 0);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		do_move(game, 'y', PIXEL, 0);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		do_move(game, 'x', 0, -PIXEL);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		do_move(game, 'x', 0, PIXEL);
}

static void	display_image(t_game *game)
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
			if (game->map_array[game->j][game->i] == 'e')
				mlx_image_to_window(game->mlx, game->o.enemy_i, game->i * PIXEL,
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
}
