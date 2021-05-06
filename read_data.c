/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:51:51 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/06 14:32:21 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

static void		input_rest(struct stat buf, t_data *node)
{
	struct group	*grp;
	struct passwd	*pwd;

	pwd = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);
	if (pwd != NULL)
	{
		ft_memmove(node->st_uid_pwname, pwd->pw_name,
		ft_strlen(pwd->pw_name));
		node->st_uid_nbr = pwd->pw_uid;
		node->pwd = *pwd;
	}
	if (grp != NULL)
	{
		ft_memmove(node->st_gid_grname, grp->gr_name,
		ft_strlen(grp->gr_name));
		node->st_gid = &(getgrgid(buf.st_gid)->gr_gid);
		node->grp = *getgrgid(buf.st_gid);
	}
}

static void		input(t_data *node)
{
	struct stat	buf;

	if (lstat(node->path, &buf) != 0)
	{
		ft_printerr(node->path, ERR);
		return ;
	}
	input_rest(buf, node);
	node->st_ino = buf.st_ino;
	node->st_mode = buf.st_mode;
	node->nlink = buf.st_nlink;
	node->st_uid = &buf.st_uid;
	node->st_gid = &buf.st_gid;
	node->size = buf.st_size;
	node->blksize = buf.st_blksize;
	node->blocks = buf.st_blocks;
	node->m_time = buf.st_mtime;
	node->dev_t = buf.st_rdev;
}

void	read_inord(t_data *node)
{
	if (node == NULL || node->path == NULL)
		return ;
	read_inord(node->left);
	input(node);
	read_inord(node->right);
}

void	read_trees(t_lsarg *args)
{
	read_inord(args->file);
	read_dir(args->dir);
}
