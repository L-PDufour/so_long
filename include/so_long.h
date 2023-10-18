/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:31:50 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/04 08:47:25 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map_array;
	int		character;
	int		collectible;
	int		exit;
}			t_map;

void		file_validation(char *argv, t_map *map);
void		free_map_struct(t_map *map);
void		exit_map_at_error(char *str, t_map *map);

# define WIDTH 512
# define HEIGHT 512
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

#endif
