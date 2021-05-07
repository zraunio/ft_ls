/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:40:49 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/07 18:23:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

int	cmp_item(t_data *root, long item_ref, long long (*cmpf)(long long, long long))
{
	if (root)
	{
		if (root->left)
			return (cmp_item(root->left, root->m_time, cmpf));
		if ((*cmpf)(root->m_time, item_ref) == 0)
			return (item_ref);
		if (root->right)
			return (cmp_item(root->right, root->m_time, cmpf));
	}
	return (0);
}

void	sort_data(t_data *root)
{
	if (cmp_item(root, 0, ft_llmax) != 0)
		ft_printf("");
	printtr_inord(root);
}
