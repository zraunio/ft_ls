/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dig_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:58:51 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/15 13:47:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_count_digit(long int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	nb = ft_abs(nb);
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}
