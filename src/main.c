/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour </var/spool/mail/ldufour>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:01:24 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/05 09:37:16 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

static mlx_image_t		*image;
static mlx_texture_t	*texture;

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int32_t	main(int32_t argc, const char *argv[])
{
	mlx_t	*mlx;
	int		fd;
	char	*line;

	if (argc != 2)
		printf("Invalid arguments\n");
	file_validation(argv[1]);
	// fd = open("test.txt", O_RDONLY);
	// printf("wtf");
	// if (fd < 0)
	// {
	// 	perror("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("Line: %s\n", line);
	// 	free(line); // Free the memory allocated by get_next_line
	// }
	// close(fd);
	return (0);
}
