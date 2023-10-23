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

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_game
{
	char		**map_array;
	char		**tmp_map;
	char		*tmp;
	int			nb_character;
	int			nb_collectible;
	int			nb_exit;
	t_position	map_coordinates;
	t_position	character;
	mlx_t		*mlx;
}				t_game;

void			file_validation(char *argv, t_game *game);
void			free_game_struct(t_game *game);
void			exit_game_at_error(char *str, t_game *game);
void			parsing_characters(t_game *game);
void			flood_fill_init(t_game *game);

# define WIDTH 512
# define HEIGHT 512
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

#endif
