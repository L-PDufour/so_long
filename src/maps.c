/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:20 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/06 14:10:48 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_path_check(const char *argv)
{
	int	len;
	int	map_path;

	len = ft_strlen(argv);
	if (len > 4 && (ft_strncmp(argv + len - 4, ".ber", 4)) != 0)
		printf("invalid filename\n");
	map_path = open(argv, O_RDONLY);
	ft_puterror(map_path);
	close(map_path);
	return (map_path);
}

char	**file_validation(const char *argv)
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
	return (printable_map);
}
