/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:02 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/23 15:01:23 by ldufour          ###   ########.fr       */
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
int	main(int argc, char *argv[])
{
	t_game			*game;
	mlx_texture_t	*tex_grass;
	mlx_image_t		*img_grass;

	game = init_struct();
	if (argc != 2)
		printf("Invalid arguments\n");
	game->mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
	if (!game->mlx)
		exit_game_at_error("Cant init mlx", game);
	file_validation(argv[1], game);
	tex_grass = mlx_load_png("./assets/SproutLands/Tilesets/Grass.png");
	img_grass = mlx_texture_to_image(game->mlx, tex_grass);
	mlx_image_to_window(game->mlx, img_grass, 0, 0);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, img_grass);
	mlx_delete_texture(tex_grass);
	mlx_terminate(game->mlx);
	free_game_struct(game);
	return (0);
}
