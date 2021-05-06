/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:09:09 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/06 14:00:10 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

t_data	*ft_new_data(char *path)
{
	t_data	*node;

	node = (t_data*)malloc(sizeof(t_data));
	if (!node)
		return (NULL);
	ft_memset(node, 0, sizeof(t_data));
	node->left = NULL;
	node->right = NULL;
	node->path = path;
	return (node);
}

void	save_newarg(t_data **root, t_data *node)
{
	t_data *temp;

	temp = *root;
	if (temp == NULL)
	{
		temp = node;
		*root = temp;
	}
	else if (ft_strcmp(node->path, temp->path) <= 0)
		save_newarg(&(temp->left), node);
	else
		save_newarg(&(temp->right), node);
}

t_data	*save_args(t_data *node, char *path)
{
	if (node == NULL)
	{
		node = ft_new_data(path);
		if (!node)
			treedel_postord(node, path);
	}
	else
		save_newarg(&node, ft_new_data(path));
	return (node);
}

void	create_trees(t_lsarg *args,int ac, char **av)
{
	struct stat	buf;
	size_t	i;

	i = 0;
	args->file = NULL;
	args->dir = NULL;
	while (i + 1 <= (size_t)ac)
	{
		if (lstat(av[i], &buf) != 0)
			ft_printerr(av[i], ERR);
		else if (S_ISDIR(buf.st_mode))
		{
			args->dir = save_args(args->dir, av[i++]);
			if (!args->dir)
				treedel_postord(args->dir, av[i - 1]);
		}
		else if (S_ISLNK(buf.st_mode) || S_ISREG(buf.st_mode))
		{
			args->file = save_args(args->file, av[i++]);
			if (!args->file)
				treedel_postord(args->file, av[i - 1]);
		}
	}
}

t_lsarg	*fill_arg(int ac, char **av)
{
	t_lsarg	*args;
	size_t	i;

	i = 0;
	args = (t_lsarg *)malloc(sizeof(t_lsarg));
	if (!args)
		ft_printerr(av[1], MALLOC_ERR);
	while (av[i][0] == '-')
			args->optns = ls_options(av[i++], args->optns);
	create_trees(args, (ac - i), &av[i]);
	return (args);
}
