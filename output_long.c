/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:59:27 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 18:37:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

char	file_mode(int mode)
{
	if ((mode & S_IFMT) == S_IFREG)
		return ('-');
	else if ((mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((mode & S_IFMT) == S_IFSOCK)
		return ('s');
	else if ((mode & S_IFMT) == S_IFIFO)
		return ('p');
	else
		return ('-');
}

void	print_precision(t_data *lst, int i[7])
{
	char	str[MAX_LNG + 1];

	ft_printf("%c", print_acl(lst->name));
	ft_printf(" %*hu", i[1], lst->nlink);
	ft_printf(" %-*s", i[2], lst->st_uid_pwname);
	ft_printf("  %-*s", i[3], lst->st_gid_grname);
	ft_printf("  %*zu", i[4], lst->size);
	print_time(lst);
	if (file_mode(lst->st_mode) != 'l')
	{
		if (ft_strchr(lst->name, '/'))
			ft_putendl(ft_strrchr(lst->name, '/') + 1);
		else
			ft_printf(lst->name);
	}
	else
	{
		ft_bzero(str, MAX_LNG + 1);
		readlink(lst->name, str, MAX_LNG);
		ft_printf("%s -> %s\n", ft_strrchr(lst->name, '/') + 1, str);
	}
}

void	print_permissions_rest(int mode)
{
	if ((mode & S_IROTH))
		ft_putchar('r');
	else
		ft_putchar('-');
	if ((mode & S_IWOTH))
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((mode & S_IXOTH))
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	print_permissions(int mode)
{
	if ((mode & S_IRUSR))
		ft_putchar('r');
	else
		ft_putchar('-');
	if ((mode & S_IWUSR))
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((mode & S_IXUSR))
		ft_putchar('x');
	else
		ft_putchar('-');
	if ((mode & S_IRGRP))
		ft_putchar('r');
	else
		ft_putchar('-');
	if ((mode & S_IWGRP))
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((mode & S_IXGRP))
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	print_long(t_lsarg *args, t_data *lst)
{
	t_data	*temp;
	int		i[7];

	temp = lst;
	ft_memset((void *)i, 0, sizeof(int) * 7);
	column_width(temp, i);
	if (lst != args->files)
		ft_printf("total %d\n", i[0]);
	while (temp)
	{
		ft_printf("%c", file_mode(temp->st_mode));
		print_permissions(temp->st_mode);
		print_permissions_rest(temp->st_mode);
		print_precision(temp, i);
		temp = temp->next;
	}
}
