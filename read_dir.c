/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:30:06 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 18:12:07 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

static t_data	*get_data_dir(t_data *dir, char *path)
{
	t_data		*temp;

	if (!dir)
	{
		temp = new_node(path);
		dir = temp;
	}
	else
	{
		temp = dir;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node(path);
	}
	return (dir);
}

t_data	*data_dir(t_data *dir, struct dirent *ent, char *str, size_t flgs)
{
	char *path;

	path = create_path(str, ent->d_name);
	if (!(flgs & ALL) && !ft_strncmp(ft_strrchr(path, '/') + 1, ".", 1))
		free(path);
	if ((flgs & ALL) != 0)
		dir = get_data_dir(dir, path);
	else if (ent->d_name[0] != '.')
		dir = get_data_dir(dir, path);
	return (dir);
}

static void	output_dir(t_lsarg *arg, t_data *dir, t_data *node, size_t flgs)
{
	get_data(dir);
	dir = lst_sort_basic(&dir);
	dir = sort_base(dir, flgs);
	if (node->next)
		ft_printf("%s:\n", node->name);
	else if (node->next == NULL && ft_strcmp(node->name, "."))
		ft_printf("%s:\n", node->name);
	if ((flgs & LONG) == LONG)
		print_long(arg, dir);
	else
		print_simple(dir);
	if ((flgs & RECUR) == RECUR)
		recursive(arg, dir, flgs);
	free(dir);
}

void	read_rec(t_lsarg *arg, char *str, size_t flgs)
{
	t_data			*rec;
	DIR				*dr;
	struct dirent	*ent;

	rec = NULL;
	dr = opendir(str);
	if (dr == NULL)
		printerr(str, 0);
	while (dr == NULL)
	{
		printerr(str, ERR);
		return ;
	}
	while ((ent = readdir(dr)) != NULL)
		rec = data_dir(rec, ent, str, flgs);
	closedir(dr);
	get_data(rec);
	rec = lst_sort_basic(&rec);
	rec = sort_base(rec, flgs);
	if ((flgs & LONG) == LONG)
		print_long(arg, rec);
	else
		print_simple(rec);
	recursive(arg, rec, flgs);
	free(rec);
}

void	read_dir(t_lsarg *arg, t_data *lst, size_t flgs)
{
	t_data			*temp;
	t_data			*dir;
	DIR				*d;
	struct dirent	*ent;

	dir = NULL;
	temp = lst;
	d = opendir(temp->name);
	if (d == NULL)
		printerr(temp->name, 0);
	while (d != NULL)
	{
		ent = readdir(d);
		if (ent == NULL)
			break ;
		dir = data_dir(dir, ent, temp->name, flgs);
	}
	closedir(d);
	output_dir(arg, dir, temp, flgs);
}
