/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:10:56 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 13:00:23 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

static void	read_id(t_data *lst)
{
	struct stat		buf;
	struct group	*gr;
	struct passwd	*pwd;

	lstat(lst->name, &buf);
	gr = getgrgid(buf.st_gid);
	pwd = getpwuid(buf.st_uid);
	if (pwd != NULL)
	{
		ft_memmove(lst->st_uid_pwname, pwd->pw_name,
		ft_strlen(pwd->pw_name));
		lst->st_uid_nbr = pwd->pw_uid;
		lst->pwd = *pwd;
	}
	if (gr != NULL)
	{
		ft_memmove(lst->st_gid_grname, gr->gr_name,
		ft_strlen(gr->gr_name));
		lst->st_gid_nbr = (getgrgid(buf.st_gid)->gr_gid);
		lst->grp = *getgrgid(buf.st_gid);
	}
}

static void	read_data(t_data *lst)
{
	struct stat	buf;

	if (lstat(lst->name, &buf) != 0)
	{
		printerr(lst->name, ERR);
		return ;
	}
	read_id(lst);
	lst->st_ino = buf.st_ino;
	lst->st_mode = buf.st_mode;
	lst->nlink = buf.st_nlink;
	lst->st_uid = &buf.st_uid;
	lst->st_gid = &buf.st_gid;
	lst->size = buf.st_size;
	lst->blksize = buf.st_blksize;
	lst->blocks = buf.st_blocks;
	lst->m_time = buf.st_mtime;
	lst->dev_t = buf.st_rdev;
}

void	get_data(t_data *lst)
{
	t_data	*temp;

	temp = lst;
	while (temp)
	{
		read_data(temp);
		temp = temp->next;
	}
}
