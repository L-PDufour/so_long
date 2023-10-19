/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:20 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/19 12:38:18 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

if (game->map_array[j][i] == EXIT )
	game->exit++;
if (game->map_array[j][i] == COLLECTIBLE )
	game->collectible++;
if (game->map_array[j][i] == PLAYER )
	game->player++;
else if (game->map_array[j][i] != WALL || game->map_array[j][i] != FLOOR )
	game->invalid_characters++;

static void	map_valid_character(t_game *game)
{
	int		i;
	int		j;
	int		k;
	char	*map_character;

	map_character = "10CPE\n";
	j = -1;
	game->map_coordinates.x = ft_strlen(game->map_array[0]) ;
	printf("len = %i\n", game->map_coordinates.x);
	while (game->map_array[++j])
	{
		i = 0;
		while (game->map_array[j][i] != '\0')
		{
			k = 0;
			while (map_character[k] != '\0' && (game->map_array[j][i] != '\n'
					|| game->map_array[j][i] != '\0'))
			{
				if (game->map_array[j][i] != map_character[k])
					k++;
				else if (game->map_array[j][i] == map_character[k])
					break ;
			}
			if (map_character[k] == '\0')
				exit_game_at_error("Invalid characters found", game);
			i++;
		}
		printf("len = %d and i = %d\n", game->map_coordinates.x, i);
		if (i != game->map_coordinates.x)
			exit_game_at_error("Map not rectangular", game);
	}
}

// static void	map_is_rectangle(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	len;
//
// 	j = 0;
// 	len = ft_strlen(game->map_array[j]);
// 	// printf("%d\n", len);
// 	// printf("%s\n", game->map_array[j]);
// 	while (game->map_array[j] != NULL)
// 	{
// 		printf("%s", game->map_array[j]);
// 		i = 0;
// 		while (game->map_array[j][i] != '\n' || game->map_array[j][i] != '\0')
// 			i++;
// 		if (i != len)
// 			exit_game_at_error("Invalid map is not rectangular", game);
// 		j++;
// 	}
// }
//
// static int	map_is_walled(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	len;
//
// 	j = 0;
// 	len = 1 - ft_strlen(game->map_array[j]);
// 	while (game->map_array[j])
// 	{
// 		i = 0;
// 		while (game->map_array[j][i] != '\0' || game->map_array[j][i] != '\n')
// 		{
// 			if (j == 0 && game->map_array[j][i] != '1')
// 				return (-1);
// 			else if (i == len && game->map_array[j][i] != '1')
// 				return (-1);
// 			else if (i == 0 && game->map_array[j][i] != '1')
// 				return (-1);
// 			else if (game->map_array[j + 1] == NULL
// 				&& game->map_array[j][i] != '1')
// 				exit_game_at_error("Invalid map not enough wall", game);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (0);
// }

// static int	map_have_character(t_game *game)
// {
// 	int	i;
// 	int	j;
//
// 	while (game->map_array[j])
// 	{
// 		i = 0;
// 		while (game->map_array[j][i] != '\0' && game->map_array[j][i] != '\n')
// 		{
// 			if (game->map_array[j][i] == PLAYER && game->character == 0)
// 				game->character = 1;
// 			else
// 				printf("too many players");
// 			if (game->map_array[j][i] == EXIT && game->character == 0)
// 				game->character = 1;
// 			else
// 				printf("too many players");
// 			// f(expression)
// 			{
// 			}
// 		}
// 		j++;
// 	}
// }
//
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
	int		map_fd;

	// int		i;
	map_fd = map_path_check(argv, game);
	// if (read(map_fd, game->tmp, BUFFER_SIZE) == 0)
	// {
	// 	close(map_fd);
	// 	exit_game_at_error("File is empty", game);
	// }
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		game->tmp = ft_strjoin(game->tmp, line);
		game->map_coordinates.y++;
		free(line);
	}
	game->map_array = ft_split(game->tmp, '\n');
	if (!game->map_array)
		exit_game_at_error("Empty file", game);
	// i = 0;
	// while (game->map_array[i] != NULL)
	// {
	// 	printf("%s", game->map_array[i]);
	// 	i++;
	// }
	map_valid_character(game);
	// map_is_rectangle(game);
	// map_is_walled(game);
	close(map_fd);
}
