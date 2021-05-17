/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:07:36 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 13:04:27 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

static t_data	*lst_merge_time(t_data *a, t_data *b)
{
	t_data		*res;

	res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->m_time > b->m_time)
		res = a;
	else if (a->m_time == b->m_time)
	{
		if (ft_strcmp(a->name, b->name) < 0)
			res = a;
		else
			res = b;
	}
	else
		res = b;
	if (res == a)
		res->next = lst_merge_time(a->next, b);
	else
		res->next = lst_merge_time(a, b->next);
	return (res);
}

static t_data	*lst_merge_size(t_data *a, t_data *b)
{
	t_data		*res;

	res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->size > b->size)
		res = a;
	else if (a->size == b->size)
	{
		if (ft_strcmp(a->name, b->name) < 0)
			res = a;
		else
			res = b;
	}
	else
		res = b;
	if (res == a)
		res->next = lst_merge_size(a->next, b);
	else
		res->next = lst_merge_size(a, b->next);
	return (res);
}

void	lst_split(t_data *src, t_data **a, t_data **b)
{
	t_data		*a1;
	t_data		*b1;

	b1 = src;
	a1 = src->next;
	while (a1 != NULL)
	{
		a1 = a1->next;
		if (a1 != NULL)
		{
			b1 = b1->next;
			a1 = a1->next;
		}
	}
	*a = src;
	*b = b1->next;
	b1->next = NULL;
}

t_data	*lst_sort_time(t_data **head)
{
	t_data		*temp;
	t_data		*a;
	t_data		*b;

	temp = *head;
	if ((temp == NULL) || (temp->next == NULL))
		return (*head);
	lst_split(temp, &a, &b);
	lst_sort_time(&a);
	lst_sort_time(&b);
	*head = lst_merge_time(a, b);
	return (*head);
}

t_data	*lst_sort_size(t_data **head)
{
	t_data		*temp;
	t_data		*a;
	t_data		*b;

	temp = *head;
	if ((temp == NULL) || (temp->next == NULL))
		return (*head);
	lst_split(temp, &a, &b);
	lst_sort_size(&a);
	lst_sort_size(&b);
	*head = lst_merge_size(a, b);
	return (*head);
}
