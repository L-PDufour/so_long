/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour </var/spool/mail/ldufour>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:01:24 by ldufour           #+#    #+#             */
/*   Updated: 2023/09/26 12:01:24 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 512

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init(WIDTH, HEIGHT, "Hello", false);
	mlx_loop(mlx);
}
