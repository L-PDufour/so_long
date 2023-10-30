/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:17:36 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/30 10:06:24 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <limits.h>

void	render_others(t_game *game, int x, int y)
{

	if (game->map_array[y][x] == EXIT)
		mlx_image_to_window(game->mlx, game->o.exit_i, (x * PIXEL) + 11, y
			* PIXEL);
	else if (game->map_array[y][x] == COLLECTIBLE)
	{
		mlx_image_to_window(game->mlx, game->o.item_i[game->i], x * PIXEL, y * PIXEL);
		printf("%i\n", game->i);
		game->i++;
	}
}

static void	render_wall_img(t_game *game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_image_to_window(game->mlx, game->w.nw_wall, x * PIXEL, y * PIXEL);
	else if (x == game->map_pos.x - 1 && y == 0)
		mlx_image_to_window(game->mlx, game->w.ne_wall, x * PIXEL, y * PIXEL);
	else if (y == 0)
		mlx_image_to_window(game->mlx, game->w.hw_wall, x * PIXEL, y * PIXEL);
	else if (x == 0 && y == game->map_pos.y)
		mlx_image_to_window(game->mlx, game->w.sw_wall, x * PIXEL, y * PIXEL);
	else if (x == game->map_pos.x - 1 && y == game->map_pos.y)
		mlx_image_to_window(game->mlx, game->w.se_wall, x * PIXEL, y * PIXEL);
	else if (x == game->map_pos.x - 1 || x == 0)
		mlx_image_to_window(game->mlx, game->w.vw_wall, x * PIXEL, y * PIXEL);
	else if (y == game->map_pos.y)
		mlx_image_to_window(game->mlx, game->w.hw_wall, x * PIXEL, y * PIXEL);
	else
		mlx_image_to_window(game->mlx, game->w.wall_tree, x * PIXEL, y * PIXEL);
}

void	render_floor_img(t_game *game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_image_to_window(game->mlx, game->f.nw_floor, x * PIXEL, y * PIXEL);
	else if (x == game->map_pos.x - 1 && y == 0)
		mlx_image_to_window(game->mlx, game->f.ne_floor, x * PIXEL, y * PIXEL);
	else if (y == 0 && x < game->map_pos.x)
		mlx_image_to_window(game->mlx, game->f.n_floor, x * PIXEL, y * PIXEL);
	else if (x == 0 && y == game->map_pos.y)
		mlx_image_to_window(game->mlx, game->f.sw_floor, x * PIXEL, y * PIXEL);
	else if (x == game->map_pos.x - 1 && y == game->map_pos.y)
		mlx_image_to_window(game->mlx, game->f.se_floor, x * PIXEL, y * PIXEL);
	else if (y == game->map_pos.y && x < game->map_pos.x)
		mlx_image_to_window(game->mlx, game->f.so_floor, x * PIXEL, y * PIXEL);
	else if (x == game->map_pos.x - 1)
		mlx_image_to_window(game->mlx, game->f.e_floor, x * PIXEL, y * PIXEL);
	else if (x == 0)
		mlx_image_to_window(game->mlx, game->f.w_floor, x * PIXEL, y * PIXEL);
	else
		mlx_image_to_window(game->mlx, game->f.floor, x * PIXEL, y * PIXEL);
}

void	render_images(t_game *game, int x, int y)
{
	static int i;

	render_floor_img(game, x, y);
	if (game->map_array[y][x] == WALL)
		render_wall_img(game, x, y);
	render_others(game, x, y);
}
