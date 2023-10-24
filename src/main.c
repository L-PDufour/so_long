/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:02 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/24 12:31:22 by ldufour          ###   ########.fr       */
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
	mlx_texture_t	*tex_grass;
	mlx_image_t		*img_grass;
	int				x;
	int				y;

	x = 0;
	y = 0;
	// mlx_image_to_window(game->mlx, img_grass, -1, 0);
	mlx_set_window_pos(game->mlx, 0, 0);
	mlx_set_window_size(game->mlx,  game->map_coordinates.x * 32, game->map_coordinates.y * 32);
	tex_grass = mlx_load_png("./assets/floor1.png");
	img_grass = mlx_texture_to_image(game->mlx, tex_grass);
	printf("y %i x %i\n", game->map_coordinates.y, game->map_coordinates.x);
	printf("heigt %i widht %i\n", img_grass->height, img_grass->width);
	while (y < game->map_coordinates.y)
	{
		x = 0;
		while (x < game->map_coordinates.x)
		{
			printf("y %i x %i\n", y, x);
			mlx_image_to_window(game->mlx, img_grass, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, img_grass);
	mlx_delete_texture(tex_grass);
	mlx_terminate(game->mlx);
}

void render_floor_textures(t_game *game)
{
	game->floor.north_west_floor_texture = mlx_load_png("./assets/floor/nwf.png");
	game->floor.north_floor_texture = mlx_load_png("./assets/floor/nf.png");
	game->floor.north_east_floor_texture = mlx_load_png("./assets/floor/nef.png");
	game->floor.west_floor_texture = mlx_load_png("./assets/floor/wf.png");
	game->floor.floor_texture = mlx_load_png("./assets/floor/f.png");
	game->floor.east_floor_texture = mlx_load_png("./assets/floor/ef.png");
	game->floor.south_west_floor_texture = mlx_load_png("./assets/floor/swf.png");
	game->floor.south_floor_texture = mlx_load_png("./assets/floor/sf.png");
	game->floor.north_east_floor_texture = mlx_load_png("./assets/floor/sef.png");	

	game->floor.north_floor =  game->floor.north_west_floor_texture = mlx_load_png("./assets/floor/nwf.png");
	game->floor.north_floor_texture = mlx_load_png("./assets/floor/nf.png");
	game->floor.north_east_floor_texture = mlx_load_png("./assets/floor/nef.png");
	game->floor.west_floor_texture = mlx_load_png("./assets/floor/wf.png");
	game->floor.floor_texture = mlx_load_png("./assets/floor/f.png");
	game->floor.east_floor_texture = mlx_load_png("./assets/floor/ef.png");
	game->floor.south_west_floor_texture = mlx_load_png("./assets/floor/swf.png");
	game->floor.south_floor_texture = mlx_load_png("./assets/floor/sf.png");
	game->floor.north_east_floor_texture = mlx_load_png("./assets/floor/sef.png");
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
