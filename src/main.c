/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:02 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/06 10:41:10 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->f.floor_t);
	mlx_delete_texture(game->f.nw_floor_t);
	mlx_delete_texture(game->f.n_floor_t);
	mlx_delete_texture(game->f.ne_floor_t);
	mlx_delete_texture(game->f.w_floor_t);
	mlx_delete_texture(game->f.e_floor_t);
	mlx_delete_texture(game->f.sw_floor_t);
	mlx_delete_texture(game->f.s_floor_t);
	mlx_delete_texture(game->f.se_floor_t);
	mlx_delete_texture(game->w.nw_wall_t);
	mlx_delete_texture(game->w.hw_wall_t);
	mlx_delete_texture(game->w.ne_wall_t);
	mlx_delete_texture(game->w.vw_wall_t);
	mlx_delete_texture(game->w.wall_t);
	mlx_delete_texture(game->w.sw_wall_t);
	mlx_delete_texture(game->w.se_wall_t);
	mlx_delete_texture(game->o.hero_t);
	mlx_delete_texture(game->o.item_t);
	mlx_delete_texture(game->o.exit_t);
}

static void	clean_mlx(t_game *game)
{
	int	i;

	i = 0;
	clean_textures(game);
	while (i < game->nb_collectible)
	{
		if (game->o.item_i[i])
			mlx_delete_image(game->mlx, game->o.item_i[i]);
		i++;
	}
	free(game->o.item_i);
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
			printf("Malloc failure\n");
			exit(EXIT_FAILURE);
		}
		ft_bzero(game, sizeof(*game));
		game->map_array = NULL;
		game->tmp_map = NULL;
		game->tmp = NULL;
		game->movement = 1;
	}
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	game = init_struct();
	file_validation(argv[1], game);
	game->mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
	if (!game->mlx)
		exit_game_at_error("Cant init mlx", game);
	print_maps(game);
	clean_mlx(game);
	mlx_terminate(game->mlx);
	free_game_struct(game);
	return (0);
}
