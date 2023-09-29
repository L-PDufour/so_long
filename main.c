/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour </var/spool/mail/ldufour>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:01:24 by ldufour           #+#    #+#             */
/*   Updated: 2023/09/29 09:42:38 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <MLX42/MLX42.h>
#define BPP sizeof(int32_t)

typedef struct s_textures {
	mlx_texture_t *floor;
	mlx_texture_t *hero;

} t_textures;

typedef struct s_images {
	mlx_image_t *floor;
	mlx_image_t *hero;

} t_images;

typedef struct s_game
{
	mlx_t *mlx;
	struct s_textures *textu;
	struct s_images *imag;
}			t_game;

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		game->imag->hero->instances->y += 32;
		mlx_delete_image(game->mlx, game->imag->hero);
		mlx_image_to_window(game->mlx, game->imag->hero, game->imag->hero->instances->x, game->imag->hero->instances->y);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
}

void game_loop(t_game *game){
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_image_to_window(game->mlx, game->imag->hero,  game->imag->hero->instances->x, game->imag->hero->instances->y);
	mlx_terminate(game->mlx);
	free(game->textu);
	free(game->imag);
}

int32_t	main(void)
{
	t_game game;
	t_textures textures;
	t_images images;
	mlx_image_t img;
	game.mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	textures.hero = mlx_load_png("./assets/free/dog.png");	
	// textures.floor = mlx_load_png("./assets/free/grasstile.png");	
	images.hero = mlx_texture_to_image(game.mlx, textures.hero);
	// images.floor = mlx_texture_to_image(game.mlx, textures.floor);
	mlx_image_to_window(game.mlx, images.hero, 50, 50);
	// mlx_image_to_window(game.mlx, images.floor, 0, 0);
	// mlx_set_instance_depth(images.floor->instances, 1);
	// mlx_set_instance_depth(images.hero->instances, 2);
	game_loop(&game);
	// mlx_loop(game.mlx);
	// mlx_terminate(game.mlx);
	ft_error();
	return (EXIT_SUCCESS);
}
