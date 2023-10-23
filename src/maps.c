/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:20 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/22 18:15:50 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_path_check(char *filename, t_game *game)
{
	int	len;
	int	map_path;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0
		|| !ft_isalnum(filename[len - 5]))
	{
		exit_game_at_error("Invalide filename", game);
	}
	map_path = open(filename, O_RDONLY);
	if (map_path < 0)
	{
		close(map_path);
		exit_game_at_error("Can't open file", game);
	}
	return (map_path);
}


void	file_validation(char *argv, t_game *game)
{
	char	*line;
	char *tmp;
	int		map_fd;

	tmp = NULL;
	map_fd = map_path_check(argv, game);
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		game->tmp = ft_strjoin(game->tmp, line);
		if (game->map_coordinates.x == 0)
		{
			game->map_coordinates.x = ft_strlen(game->tmp) - 1;
		}
		game->map_coordinates.y++;
		free(line);
	}
	game->map_coordinates.y--;
	if (!game->tmp)
		exit_game_at_error("Empty file", game);
	parsing_characters(game);
	tmp = ft_strdup(game->tmp);
	game->map_array = ft_split(tmp, '\n');
	free(tmp);
	flood_fill_init(game);
	close(map_fd);
}
