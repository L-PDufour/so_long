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

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map_array;
	// char	*cmd_path;
	// char	**cmd_args;
	// int		infile;
	// int		outfile;
	// int		fd[2];
	// int		pids1;
	// int		pids2;
	// int		i;
	// int		j;
	// int		*pids_bonus;
}			t_map;

char		**file_validation(const char *argv);

# define WIDTH 512
# define HEIGHT 512
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define START 'P'

#endif
