/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_hight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:41:10 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/16 11:10:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int		ft_tree_height(t_bitree *root)
{
	int i;
	
	i = root ? 1 + ft_llmax(ft_tree_height(root->left), \
	ft_tree_height(root->right)) : 0;
	return (i);
}
