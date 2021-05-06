/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:52:58 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/06 12:31:46 by zraunio          ###   ########.fr       */
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
		ft_putendl(strerror(errno));
	}
	if (error == USAGE || error == MALLOC_ERR)
		exit(EXIT_FAILURE);
		//malloc error deserves a some freeing action or else we're in trouble?
	exit(EXIT_FAILURE);
	return (0);
}

void	treedel_postord(t_data *node, char *str)
{
	if (node == NULL)
		return ;
	treedel_postord(node->left, str);
	treedel_postord(node->right, str);
	free(node);
	node = NULL;
	ft_printerr(str, MALLOC_ERR);
}
