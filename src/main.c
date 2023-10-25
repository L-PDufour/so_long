/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:02 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/25 17:09:57 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
