/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:50 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/25 16:13:24 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_others_textures(t_game *game)
{
	game->o.hero_t = mlx_load_png("./assets/other/player.png");
	game->o.item_t = mlx_load_png("./assets/other/item.png");
	game->o.exit_t = mlx_load_png("./assets/other/exit.png");
	game->o.hero_i = mlx_texture_to_image(game->mlx, game->o.hero_t);
	game->o.item_i = mlx_texture_to_image(game->mlx, game->o.item_t);
	game->o.exit_i = mlx_texture_to_image(game->mlx, game->o.exit_t);
}

static void	render_wall_textures(t_game *game)
{
	game->w.nw_wall_t = mlx_load_png("./assets/wall/nww.png");
	game->w.hw_wall_t = mlx_load_png("./assets/wall/hw.png");
	game->w.ne_wall_t = mlx_load_png("./assets/wall/new.png");
	game->w.vw_wall_t = mlx_load_png("./assets/wall/vw.png");
	game->w.wall_t = mlx_load_png("./assets/wall/tree.png");
	game->w.sw_wall_t = mlx_load_png("./assets/wall/sww.png");
	game->w.se_wall_t = mlx_load_png("./assets/wall/sew.png");
	game->w.nw_wall = mlx_texture_to_image(game->mlx, game->w.nw_wall_t);
	game->w.hw_wall = mlx_texture_to_image(game->mlx, game->w.hw_wall_t);
	game->w.ne_wall = mlx_texture_to_image(game->mlx, game->w.ne_wall_t);
	game->w.vw_wall = mlx_texture_to_image(game->mlx, game->w.vw_wall_t);
	game->w.wall_tree = mlx_texture_to_image(game->mlx, game->w.wall_t);
	game->w.sw_wall = mlx_texture_to_image(game->mlx, game->w.sw_wall_t);
	game->w.se_wall = mlx_texture_to_image(game->mlx, game->w.se_wall_t);
}

static void	render_floor_textures(t_game *game)
{
	game->f.nw_floor_t = mlx_load_png("./assets/floor/nwf.png");
	game->f.n_floor_t = mlx_load_png("./assets/floor/nf.png");
	game->f.ne_floor_t = mlx_load_png("./assets/floor/nef.png");
	game->f.w_floor_t = mlx_load_png("./assets/floor/wf.png");
	game->f.floor_t = mlx_load_png("./assets/floor/f.png");
	game->f.e_floor_t = mlx_load_png("./assets/floor/ef.png");
	game->f.sw_floor_t = mlx_load_png("./assets/floor/swf.png");
	game->f.s_floor_t = mlx_load_png("./assets/floor/sf.png");
	game->f.se_floor_t = mlx_load_png("./assets/floor/sef.png");
	game->f.nw_floor = mlx_texture_to_image(game->mlx, game->f.nw_floor_t);
	game->f.n_floor = mlx_texture_to_image(game->mlx, game->f.n_floor_t);
	game->f.ne_floor = mlx_texture_to_image(game->mlx, game->f.ne_floor_t);
	game->f.w_floor = mlx_texture_to_image(game->mlx, game->f.w_floor_t);
	game->f.floor = mlx_texture_to_image(game->mlx, game->f.floor_t);
	game->f.e_floor = mlx_texture_to_image(game->mlx, game->f.e_floor_t);
	game->f.sw_floor = mlx_texture_to_image(game->mlx, game->f.sw_floor_t);
	game->f.so_floor = mlx_texture_to_image(game->mlx, game->f.s_floor_t);
	game->f.se_floor = mlx_texture_to_image(game->mlx, game->f.se_floor_t);
}

void	rendering_textures_to_images(t_game *game)
{
	render_floor_textures(game);
	render_wall_textures(game);
	render_others_textures(game);
}
