/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:50:45 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 17:19:05 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

static t_data	*lst_sort_rev(t_data *lst)
{
	t_data		*prev;
	t_data		*temp;

	if (lst != NULL)
	{
		prev = lst;
		temp = lst->next;
		lst = lst->next;
		prev->next = NULL;
		while (lst != NULL)
		{
			lst = lst->next;
			temp->next = prev;
			prev = temp;
			temp = lst;
		}
		lst = prev;
	}
	return (lst);
}

static t_data	*lst_merge_basic(t_data *a, t_data *b)
{
	t_data		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->name, b->name) < 0)
		result = a;
	else
		result = b;
	if (result == a)
		result->next = lst_merge_basic(a->next, b);
	else
		result->next = lst_merge_basic(a, b->next);
	return (result);
}

t_data	*lst_sort_basic(t_data **lst)
{
	t_data		*head;
	t_data		*a;
	t_data		*b;

	head = *lst;
	if ((head == NULL) || (head->next == NULL))
		return (*lst);
	lst_split(head, &a, &b);
	lst_sort_basic(&a);
	lst_sort_basic(&b);
	*lst = lst_merge_basic(a, b);
	return (*lst);
}

t_data	*sort_base(t_data *lst, size_t flgs)
{
	if ((flgs & TIME) != 0)
		lst_sort_time(&lst);
	if ((flgs & SORT_S) != 0)
		lst_sort_size(&lst);
	if ((flgs & REV) != 0)
		lst = lst_sort_rev(lst);
	return (lst);
}
