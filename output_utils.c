/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:24:28 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 18:38:58 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"
#include <stdio.h>

void		print_time(t_data *lst)
{
	time_t		today;

	today = time(NULL);
	if (today == ((time_t)-1))
	{
		ft_putendl("Failure to obtain the lst time.");
		exit(EXIT_FAILURE);
	}
	if ((today - lst->m_time) <= 15778800)
		ft_printf(" %.12s ", ctime(&lst->m_time) + 4);
	else
	{
		ft_printf(" %.7s ", ctime(&lst->m_time));
		ft_printf("%.*s ", 4, (ctime(&lst->m_time) + 4) + 16);
	}
}

char	print_acl(char *path)
{
	acl_t	tmp;
	char	buf[256];

	if (listxattr(path, buf, 256, XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}
