/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:02 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/17 08:12:26 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*init_struct(void)
{
	static t_map	*map;

	map = NULL;
	if (!map)
	{
		map = (t_map *)ft_calloc(1, sizeof(t_map));
		if (!map)
		{
			fprintf(stderr, "Malloc failure\n");
			exit(EXIT_FAILURE);
		}
		ft_bzero(map, sizeof(*map));
		map->map_array = NULL;
	}
	return (map);
}
int	main(int argc, char *argv[])
{
	t_map	*map;

	map = init_struct();
	if (argc != 2)
		printf("Invalid arguments\n");
	file_validation(argv[1], map);
	free_map_struct(map);
	return (0);
}
