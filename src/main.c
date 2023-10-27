/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:02 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/27 14:06:17 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_move(t_game *game, char pos, int updated_y, int updated_x)
{
	int	player_y;
	int	player_x;
	int	map_y;
	int	map_x;
	int	y;
	int	x;

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
		printf("Collectible\n");
		mlx_image_to_window(game->mlx, game->f.floor, player_x, player_y);
		// game->map_array[(player_y / PIXEL)][(player_x / PIXEL)] = '0';
		// printf("instance = %i", game->o.hero_i->instances->z);
// creer une fonction qui update le jeu
		mlx_image_to_window(game->mlx, game->o.hero_i, game->o.hero_i->instances->x, game->o.hero_i->instances->y);
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
	// printf("delta%f\n",game->mlx->delta_time);
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

t_game	*init_struct(void)
{
	static t_game	*game;

	game = NULL;
	if (!game)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		if (!game)
		{
			fprintf(stderr, "Malloc failure\n");
			exit(EXIT_FAILURE);
		}
		ft_bzero(game, sizeof(*game));
		game->map_array = NULL;
		game->tmp_map = NULL;
		game->tmp = NULL;
	}
	return (game);
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
	while (y <= game->map_pos.y)
	{
		x = 0;
		while (x < game->map_pos.x)
		{
			render_images(game, x, y);
			x++;
		}
		y++;
	}
	y = 0;
	while (y <= game->map_pos.y)
	{
		x = 0;
		while (x < game->map_pos.x)
		{
			if (game->map_array[y][x] == PLAYER)
				mlx_image_to_window(game->mlx, game->o.hero_i, x * PIXEL, y
						* PIXEL);
			x++;
		}
		y++;
	}
	mlx_key_hook(game->mlx, (void *)ft_hook, (void *)game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = init_struct();
	if (argc != 2)
		printf("Invalid arguments\n");
	game->mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
	if (!game->mlx)
		exit_game_at_error("Cant init mlx", game);
	file_validation(argv[1], game);
	print_maps(game);
	free_game_struct(game);
	return (0);
}
