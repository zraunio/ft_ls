/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:52:58 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 18:21:39 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

void	free_list(t_data *lst)
{
	t_data		*temp;
	t_data		*store;

	temp = lst;
	while (temp != NULL)
	{
		store = temp->next;
		if (temp->name)
			free(temp->name);
		free(temp);
		temp = store;
	}
	lst = NULL;
}

int	printerr(char *str, int error)
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
	return (0);
}

