/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:20 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/16 15:08:43 by ldufour          ###   ########.fr       */
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

static int	map_valid_character(char **printable_map)
{
	int		i;
	int		j;
	int		k;
	char	*map_character;

	map_character = "10CPE";
	j = -1;
	while (printable_map[++j])
	{
		i = -1;
		while (printable_map[j][++i] != '\0')
		{
			k = 0;
			while (map_character[k] != '\0' && printable_map[j][i] != '\n')
			{
				if (printable_map[j][i] != map_character[k])
					k++;
				else if (printable_map[j][i] == map_character[k])
					break ;
			}
			if (map_character[k] == '\0')
				return (-1);
		}
	}
	return (0);
}

static int	map_is_rectangle(char **printable_map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(printable_map[j]);
	while (printable_map[j])
	{
		i = 0;
		while (printable_map[j][i] != '\0')
			i++;
		if (i != len)
		{
			printf("i = %i len = %i\n", i, len);
			return (-1);
		}
		j++;
	}
	return (0);
}

static int	map_is_walled(char **printable_map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(printable_map[j]);
	while (printable_map[j])
	{
		i = 0;
		while (printable_map[j][i] != '\0' && printable_map[j][i] != '\n')
		{
			if (j == 0 && printable_map[j][i] != '1')
				return (-1);
			else if (i == len && printable_map[j][i] != '1')
				return (-1);
			else if (i == 0 && printable_map[j][i] != '1')
				return (-1);
			else if (printable_map[j + 1] == NULL 
				&& printable_map[j][i] != '1')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

static int map_have_character()
{

}

char	**file_validation(char *argv)
{
	char	*line;
	char	**printable_map;
	int		i;
	int		map_fd;

	map_fd = map_path_check(argv);
	i = 0;
	printable_map = (char **)malloc(sizeof(char *));
	line = NULL;
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		if (line)
			printable_map[i] = ft_strdup(line);
		i++;
	}
	ft_puterror(map_valid_character(printable_map), "Invalid characters");
	ft_puterror(map_is_rectangle(printable_map), "Map is not rectangular");
	ft_puterror(map_is_walled(printable_map), "Map is not walled");
	return (printable_map);
}
