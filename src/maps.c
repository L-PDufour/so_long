/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:44:20 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/06 08:44:20 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	file_validation(const char *argv)
{
	int		map;
	int		len;
	char	*line;

	len = ft_strlen(argv);
	if (len > 4 && (ft_strncmp(argv + len - 4, ".ber", 4)) != 0)
		printf("invalid filename\n");
	map = open(argv, O_RDONLY);
	ft_puterror(map);
	line = NULL;
	while (1)
	{
		line = get_next_line(map);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(map);
}
