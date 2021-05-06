/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 09:30:04 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/06 12:37:04 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

// ft_printf("%-13s", "drwxr-xr-x@");
// ft_printf("%-*d", 2, 3);
// ft_printf("%-*s", 9, "zraunio");
// ft_printf("%-*s", 10, "staff");
// ft_printf("%-*d", 4, 96);
// ft_printf("%-*s", 6, "2 May");
// ft_printf("%-*s", 6, "10:40");
// ft_printf("%-*s", 6, "eval_tests");


//with all other options, you can just print by one factor, start with normal alphabetical print, it's easy

// void	print_base(t_lsarg *ls)
// {
	
// }
void 	printtr_inord(t_data *node)
{
	if (node == NULL || node->path == NULL)
		return ;
	printtr_inord(node->left);
	ft_printf("%s\n", node->path);
	printtr_inord(node->right);
}
