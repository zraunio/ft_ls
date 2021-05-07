/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 09:30:04 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/07 15:43:56 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"
#include <stdio.h>

// ft_printf("%-13s", "drwxr-xr-x@");
// ft_printf("%-*d", 2, 3);
// ft_printf("%-*s", 9, "zraunio");
// ft_printf("%-*s", 10, "staff");
// ft_printf("%-*d", 4, 96);
// ft_printf("%-*s", 6, "2 May");
// ft_printf("%-*s", 6, "10:40");
// ft_printf("%-*s", 6, "eval_tests");


//with all other options, you can just print by one factor, start with normal alphabetical print, it's easy
// void	

void 	printtr_inord(t_data *node)
{
	if (node == NULL || node->path == NULL)
		return ;
	printtr_inord(node->left);
	printf("%lu\n", node->m_time);
	printtr_inord(node->right);
}
