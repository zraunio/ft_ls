/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:52:58 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/04 14:04:09 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

int	ft_printerr(char *str, int error)
{
	if (error == USAGE)
		ft_printf("ft_ls: illegal option -- %s\nusage: ft_ls [lsxarhtR] [file...]", str);
	else if (error == ERR || error == MALLOC_ERR)
	{
		ft_printf("ft_ls: %s: ", str);
		ft_putendl(strerror());
	}
	if (error == USAGE || error == MALLOC_ERR)
		exit(EXIT_FAILURE);
	return (0);
}
