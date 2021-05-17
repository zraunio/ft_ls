/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:41:58 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 12:44:31 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

t_data	*new_node(char *str)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		printerr(str, MALLOC_ERR);
	ft_memset(new, 0, sizeof(t_data));
	new->name = str;
	new->next = NULL;
	return (new);
	
}

void	fill_list(t_lsarg *ls, char *str, size_t i)
{
	t_data	*temp;

	if ((!ls->dirs && i == 0) || (!ls->files && i == 1))
	{
		temp = new_node(str);
		if (i == 0)
			ls->dirs = temp;
		else
			ls->files = temp;
	}
	else
	{
		if (i == 0)
			temp = ls->dirs;
		else
			temp = ls->files;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node(str);
	}
}

void	create_lists(t_lsarg *ls, char **av)
{
	struct stat	buf;
	size_t		i;
	size_t		flg;

	flg = 0;
	i = 0;
	while (av[i] != NULL)
	{
		if (stat(av[i++], &buf) != 0)
		{
			printerr(av[i - 1], ERR);
			flg = 1;
		}
		else if (S_ISDIR(buf.st_mode))
			fill_list(ls, av[i - 1], 0);
		else
			fill_list(ls, av[i - 1], 1);
	}
	if (!ls->dirs && !ls->files && flg == 0)
		fill_list(ls, ".", 0);
	if (ls->dirs)
		get_data(ls->dirs);
	if (ls->files)
		get_data(ls->files);
}
