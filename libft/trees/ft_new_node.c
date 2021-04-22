/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:03:07 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/26 13:19:55 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

/*
** allocate a new binary tree element
** in itiate size_t to given item and all else to NULL
*/

t_bitree	*ft_new_node(char *item)
{
	t_bitree	*node;

	node = (t_bitree *)malloc(sizeof(t_bitree));
	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}
