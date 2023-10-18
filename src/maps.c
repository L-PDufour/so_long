/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:20 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/18 15:12:51 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_path_check(char *argv)
{
	int	len;
	int	map_path;

	len = ft_strlen(argv);
	if (len > 4 && (ft_strncmp(argv + len - 4, ".ber", 4)) != 0)
		printf("invalid filename\n");
	map_path = open(argv, O_RDONLY);
	ft_puterror(map_path, "");
	return (map_path);
}

static void	map_valid_character(t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	*map_character;

	map_character = "10CPE\n";
	j = -1;
	while (map->map_array[++j])
	{
		i = 0;
		while (map->map_array[j][i] != '\0')
		{
			k = 0;
			while (map_character[k] != '\0' && (map->map_array[j][i] != '\n'
					|| map->map_array[j][i] != '\0'))
			{
				if (map->map_array[j][i] != map_character[k])
					k++;
				else if (map->map_array[j][i] == map_character[k])
					break ;
			}
			if (map_character[k] == '\0')
				exit_map_at_error("Invalid characters found", map);
			i++;
		}
	}
}

static void	map_is_rectangle(t_map *map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(map->map_array[j]) - 1;
	// printf("%d\n", len);
	// printf("%s\n", map->map_array[j]);
	while (map->map_array[j] != NULL)
	{
		i = 0;
		while (map->map_array[j][i] != '\n' && map->map_array[j][i] != '\0')
			i++;
		if (i != len)
			exit_map_at_error("Invalid map is not rectangular", map);
		j++;
	}
}

static int	map_is_walled(t_map *map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = 1 - ft_strlen(map->map_array[j]);
	while (map->map_array[j])
	{
		i = 0;
		while (map->map_array[j][i] != '\0' || map->map_array[j][i] != '\n')
		{
			if (j == 0 && map->map_array[j][i] != '1')
				return (-1);
			else if (i == len && map->map_array[j][i] != '1')
				return (-1);
			else if (i == 0 && map->map_array[j][i] != '1')
				return (-1);
			else if (map->map_array[j + 1] == NULL
				&& map->map_array[j][i] != '1')
				exit_map_at_error("Invalid map not enough wall", map);
			i++;
		}
		j++;
	}
	return (0);
}

// static int	map_have_character(t_map *map)
// {
// 	int	i;
// 	int	j;
//
// 	while (map->map_array[j])
// 	{
// 		i = 0;
// 		while (map->map_array[j][i] != '\0' && map->map_array[j][i] != '\n')
// 		{
// 			if (map->map_array[j][i] == PLAYER && map->character == 0)
// 				map->character = 1;
// 			else
// 				printf("too many players");
// 			if (map->map_array[j][i] == EXIT && map->character == 0)
// 				map->character = 1;
// 			else
// 				printf("too many players");
// 			// f(expression)
// 			{
// 			}
// 		}
// 		j++;
// 	}
// }

void	file_validation(char *argv, t_map *map)
{
	char	*line;
	int		i;
	int		map_fd;

	map_fd = map_path_check(argv);
	i = 0;
	map->map_array = NULL;
	map->map_array = (char **)malloc(sizeof(char *)); // dois-je sizer pour
	if (!map->map_array)
		exit(EXIT_FAILURE);
	line = NULL;
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		map->map_array[i] = ft_strdup(line);
		if(map->map_array[i] == NULL)
			exit_map_at_error("malloc failure", map);
		free(line);
		i++;
	}
	// free(line);
	// map_valid_character(map);
	// map_is_rectangle(map);
	// map_is_walled(map);
	i = 0;
	while (map->map_array[i] != NULL)
	{
		
	}

}
