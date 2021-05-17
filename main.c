/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:40:40 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 18:26:03 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ft_ls.h"

int	main(int argc, char **argv)
{
	size_t	i;
	t_lsarg	*lst;

	i = 1;
	lst = (t_lsarg *)malloc(sizeof(t_lsarg));
	if (!lst)
		return (-1);
	ft_memset(lst, 0, sizeof(t_lsarg));
	if (argv[i])
		sort_args((size_t)argc - 1, &argv[i]);
	while (argv[i] != NULL && argv[i][0] == '-')
		lst->flg = ls_options(argv[i++], lst->flg);
	create_lists(lst, &argv[i]);
	output_base(lst);
	free(lst);
	return (0);
}
//gcc -Wall -Wextra -Werror -I./incl -L./libft -lft *.c -o ft_ls
