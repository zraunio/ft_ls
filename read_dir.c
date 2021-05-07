/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:31:33 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/07 14:09:26 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"
#include <stdio.h>


void	init_dir(t_lsarg *args2, char *path)
{
	args2->file = save_args(args2->file, path);
}

void	read_dir(t_data *dir)
{
	t_lsarg	*args2;
	DIR	*d;
	struct dirent	*ent;

	if (dir == NULL || dir->path == NULL)
		return ;
	read_dir(dir->left);
	args2 = (t_lsarg *)malloc(sizeof(t_lsarg));
	if (!args2)
		ft_printerr(dir->path, MALLOC_ERR);
	ft_memset(args2, 0, sizeof(t_lsarg));
	d = opendir(dir->path);
	while (d != NULL)
	{
		ent = readdir(d);
		if (ent == NULL)
			break ;
		init_dir(args2, ent->d_name);
	}
	printtr_inord(args2->file);
	closedir(d);
	free_args(args2);
	read_dir(dir->right);
}
