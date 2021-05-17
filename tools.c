/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:50:41 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 18:14:01 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

void	column_width(t_data *lst, int w[7])
{
	int		i;
	int		blks;
	t_data	*temp;

	temp = lst;
	w[5] = 3;
	w[6] = 3;
	i = 0;
	blks = 0;
	while (temp)
	{
		w[1] = ft_max((int)ft_count_digit(temp->nlink), w[1]);
		w[2] = ft_max((int)ft_strilen(temp->st_uid_pwname), w[2]);
		w[3] = ft_max((int)ft_strilen(temp->st_gid_grname), w[3]);
		i = (int)ft_count_digit(temp->size);
		w[4] = ft_max(i, w[4]);
		w[0] = blks += temp->blocks;
		temp = temp->next;
	}
	w[5] = ft_max(w[4] - w[6] - 1, w[5]);
}

char	*create_path(const char *dir, const char *name)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*p;

	i = ft_strlen(dir);
	j = ft_strlen(name);
	size = i + j + 2;
	p = (char *)malloc(sizeof(char) * size);
	if (p != NULL)
	{
		ft_memcpy(p, dir, i);
		if (i > 0 && dir[i - 1] != '/')
			p[i++] = '/';
		ft_memcpy(p + i, name, j + 1);
	}
	return (p);
}
