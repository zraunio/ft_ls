/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:30:41 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 18:25:58 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

void	print_simple(t_data *data)
{
	t_data	*temp;

	temp = data;
	while (temp)
	{
		if (ft_strchr(temp->name, '/'))
			ft_putendl(ft_strrchr(temp->name, '/') + 1);
		else
			ft_putendl(temp->name);
		temp = temp->next;
	}
}

static void	include_a(t_data *dir)
{
	if (ft_strrchr(dir->name, '/') != 0)
	{
		if (ft_strequ(dir->name, ".") || ft_strequ(dir->name, ".."))
		{
			dir = dir->next;
			return ;
		}
	}
	else if (ft_strequ(ft_strrchr(dir->name, '/') + 1, ".") ||
	ft_strequ(ft_strrchr(dir->name, '/') + 1, ".."))
	{
		dir = dir->next;
		return ;
	}
}

void	recursive(t_lsarg *arg, t_data *dir, size_t flgs)
{
	t_data	*current;

	current = dir;
	while (dir)
	{
		if ((flgs & ALL) == ALL)
			include_a(dir);
		if (S_ISDIR(dir->st_mode) && dir != NULL &&
		(!(ft_strequ(ft_strrchr(dir->name, '/') + 1, ".") ||
		(ft_strequ(ft_strrchr(dir->name, '/') + 1, "..")))))
		{
			ft_printf("\n");
			ft_printf("%s:\n", dir->name);
			read_rec(arg, dir->name, flgs);
		}
		dir = dir->next;
	}
}

void	output_base(t_lsarg	*lst)
{
	t_data	*temp;

	temp = NULL;
	lst->files = sort_base(lst->files, lst->flg);
	if (lst->files)
	{
		if ((lst->flg & LONG) == LONG)
			print_long(lst, lst->files);
		else
			print_simple(lst->files);
		free_list(lst->files);
	}
	if (lst->files && lst->dirs)
		ft_putchar('\n');
	if (lst->dirs)
	{
		lst->dirs = sort_base(lst->dirs, lst->flg);
		temp = lst->dirs;
		while (temp)
		{
			read_dir(lst, temp, lst->flg);
			if (temp->next != NULL)
				ft_putchar('\n');
			temp = temp->next;
		}
	}
}
