/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:31:50 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/19 20:53:41 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_others
{
	mlx_texture_t	*hero_t;
	mlx_texture_t	*item_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*enemy_t;
	mlx_image_t		*hero_i;
	mlx_image_t		*exit_i;
	mlx_image_t		**item_i;
	mlx_image_t		*enemy_i;
}					t_others;

typedef struct s_floor
{
	mlx_texture_t	*nw_floor_t;
	mlx_texture_t	*n_floor_t;
	mlx_texture_t	*ne_floor_t;
	mlx_texture_t	*w_floor_t;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*e_floor_t;
	mlx_texture_t	*sw_floor_t;
	mlx_texture_t	*s_floor_t;
	mlx_texture_t	*se_floor_t;
	mlx_image_t		*nw_floor;
	mlx_image_t		*n_floor;
	mlx_image_t		*ne_floor;
	mlx_image_t		*w_floor;
	mlx_image_t		*floor;
	mlx_image_t		*e_floor;
	mlx_image_t		*sw_floor;
	mlx_image_t		*so_floor;
	mlx_image_t		*se_floor;
}					t_floor;
typedef struct s_wall
{
	mlx_texture_t	*nw_wall_t;
	mlx_texture_t	*hw_wall_t;
	mlx_texture_t	*ne_wall_t;
	mlx_texture_t	*vw_wall_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*sw_wall_t;
	mlx_texture_t	*se_wall_t;
	mlx_image_t		*nw_wall;
	mlx_image_t		*hw_wall;
	mlx_image_t		*ne_wall;
	mlx_image_t		*vw_wall;
	mlx_image_t		*wall_tree;
	mlx_image_t		*sw_wall;
	mlx_image_t		*se_wall;
}					t_wall;

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_game
{
	char			**map_array;
	char			**tmp_map;
	char			*tmp;
	int				nb_character;
	int				nb_collectible;
	int				nb_exit;
	int				movement;
	t_position		map_pos;
	t_position		character;
	mlx_t			*mlx;
	mlx_image_t		*move_display;
	t_floor			f;
	t_wall			w;
	t_others		o;
	int				i;
	int				j;
	int				k;
	int				item_count;
}					t_game;

void				file_validation(char *argv, t_game *game);
void				free_game_struct(t_game *game);
void				exit_game_at_error(char *str, t_game *game);
void				parsing_characters(t_game *game);
void				flood_fill_init(t_game *game);
void				rendering_textures_to_images(t_game *game);
void				render_images(t_game *game, int x, int y);
void				render_others(t_game *game, int x, int y);
void				render_floor_img(t_game *game, int x, int y);
void				print_maps(t_game *game);
void	flood_fill_enemy(t_game *game);
# define WIDTH 256
# define HEIGHT 256
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define PIXEL 64

#endif
