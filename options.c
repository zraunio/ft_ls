/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:41:14 by zraunio           #+#    #+#             */
/*   Updated: 2021/04/01 12:55:57 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

char	*ls_options(char *str)
{
	size_t	i;

	i = 1;
	while (str[i])
	{
		if (!(ft_strchr(OPTIONS, str[i++])))
			return ("USAGE");
	}
	return (str);
}

void	sort_args(char **av)
{
	size_t		i;
	size_t		j;
	char		*temp;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				temp = av[i];
				av[i] = av[j];
				av[j] = temp;
				continue ;
			}
			else
				j++;
		i++;
	}
}
