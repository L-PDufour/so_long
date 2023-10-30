/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:43:38 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/25 17:08:56 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_for_characters(t_game *game, int i, int j,
		int newline_counter)
{
	if (game->tmp[i] == PLAYER)
	{
		game->character.x = j;
		game->character.y = newline_counter;
		game->nb_character++;
	}
	else if (game->tmp[i] == COLLECTIBLE)
		game->nb_collectible++;
	else if (game->tmp[i] == EXIT)
		game->nb_exit++;
	else if (game->tmp[i] != '\n' && game->tmp[i] != WALL
		&& game->tmp[i] != FLOOR)
		exit_game_at_error("Invalid characters", game);
}

static void	check_for_rectangularity(t_game *game, int *i, int *j)
{
	if (game->tmp[*i] == '\n' || game->tmp[*i] == '\0')
	{
		if (*j != game->map_pos.x)
			exit_game_at_error("Map is not rectangular", game);
		if (game->tmp[*i] == '\n' && game->tmp[*i + 1] != '\0')
			(*i)++;
		*j = 0;
	}
}

static void	check_for_wall(t_game *game, int i, int *newline_counter)
{
	int	error_has_occured;

	error_has_occured = 0;
	if (game->tmp[i] == '\n')
	{
		if (game->tmp[i - 1] != WALL && game->tmp[i + 1] != WALL)
			error_has_occured = 1;
	}
	else if ((*newline_counter == 0 || *newline_counter == game->map_pos.y)
		&& (game->tmp[i] != WALL && game->tmp[i] != '\n'))
		error_has_occured = 1;
	if (error_has_occured)
		exit_game_at_error("Map is not walled", game);
}

void	parsing_characters(t_game *game)
{
	int			i;
	int			j;
	static int	newline_counter;

	i = 0;
	j = 0;
	newline_counter = 0;
	while (game->tmp[i] != '\0')
	{
		if (game->tmp[i] == '\n')
			newline_counter++;
		check_for_wall(game, i, &newline_counter);
		check_for_characters(game, i, j, newline_counter);
		check_for_rectangularity(game, &i, &j);
		j++;
		i++;
	}
	if (game->nb_character != 1 || game->nb_exit != 1)
		exit_game_at_error("Need one exit and one players", game);
	if (game->map_pos.x > 41 || game->map_pos.y > 21)
		exit_game_at_error("Map too big, need to be 20x40", game);
}
