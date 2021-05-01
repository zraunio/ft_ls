/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oradd_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:12:42 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/01 14:41:27 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

size_t	ft_oradd_bit(size_t nb, size_t bit)
{
	size_t	i;

	i = 0;
	nb |= (size_t)bit;
	return (nb);
}
/*
** adds all traits with | operator
** array last value MUST be 0
*/
