/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:00:58 by ldufour           #+#    #+#             */
/*   Updated: 2023/10/05 11:00:58 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puterror(int function)
{
	if (function == -1)
		fprintf(stderr, "Error: %s\n", strerror(errno));
}
