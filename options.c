/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:41:14 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/01 14:56:17 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

size_t	add_option(size_t flgs, char c)
{
	flgs = flgs ^ 0x0;
	if (c == 'l')
		flgs = ft_oradd_bit(flgs, (size_t)LONG);
	else if (c == 'a')
		flgs = ft_oradd_bit(flgs, (size_t)ALL);
	else if (c == 'r')
		flgs = ft_oradd_bit(flgs, (size_t)REV);
	else if (c == 'h')
		flgs = ft_oradd_bit(flgs, (size_t)HUMAN);
	else if (c == 't')
		flgs = ft_oradd_bit(flgs, (size_t)TIME);
	else if (c == 's')
		flgs = ft_oradd_bit(flgs, (size_t)SIZE);
	else if (c == 'R')
		flgs = ft_oradd_bit(flgs, (size_t)RECUR);
	else if (c == 'x')
		flgs = ft_oradd_bit(flgs, (size_t)LINES);
	else if (c == '1')
		flgs = ft_oradd_bit(flgs, (size_t)HELP);
	return (flgs);
}

void	ls_options(char *str)
{
	size_t	i;
	size_t	flgs;

	i = 1;
	flgs = 0;
	if (ft_strcmp(str, "--help") == 0)
	{
		flgs = add_option(flgs, '1');
		return ;
	}
	while (str[i])
	{
		if (!(ft_strchr(OPTIONS, str[i])))
			ft_putstr("USAGE\n");
		else
			flgs = add_option(flgs, str[i++]);
	}
	ft_print_bits(flgs, 64);
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
