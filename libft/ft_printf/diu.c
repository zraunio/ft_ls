/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:45:46 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/15 14:04:10 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static size_t	integer_long(va_list *list, t_flags *flg)
{
	long long int	d;
	size_t			z;

	d = 0;
	z = 0;
	if (flg->z)
	{
		z = va_arg(*list, size_t);
		return (nbr_check_flags(flg, (long long)z, ft_sizetoa(z)));
	}
	else if (flg->ll)
	{
		d = va_arg(*list, long long int);
		return (nbr_check_flags(flg, (long long)d, ft_litoa(d)));
	}
	else
	{
		d = va_arg(*list, long int);
		return (nbr_check_flags(flg, (long long)d, ft_litoa(d)));
	}
}

static size_t	decimal_nbr(va_list *list, t_flags *flg)
{
	int			nb;
	short		s;

	nb = 0;
	s = 0;
	if (flg->h)
	{
		if (flg->hh)
		{
			s = (signed char)va_arg(*list, signed int);
			return (nbr_check_flags(flg, (long long)s, ft_itoa(s)));
		}
		else
		{
			s = (short)va_arg(*list, int);
			return (nbr_check_flags(flg, (long long)s, ft_itoa(s)));
		}
	}
	else if (flg->l)
		return (integer_long(list, flg));
	else
	{
		nb = va_arg(*list, int);
		return (nbr_check_flags(flg, (long long)nb, ft_itoa(nb)));
	}
}

static size_t	unsigned_long(va_list *list, t_flags *flg)
{
	unsigned long long	d;
	unsigned long		i;

	d = 0;
	i = 0;
	if (flg->ll)
	{
		d = va_arg(*list, unsigned long long);
		return (nbr_check_flags(flg, (long long)d, ft_lutoa(d)));
	}
	else
	{
		i = va_arg(*list, unsigned long int);
		return (nbr_check_flags(flg, (long long)i, ft_lutoa(i)));
	}
}

static size_t	unsigned_nbr(va_list *list, t_flags *flg)
{
	unsigned int	nb;
	unsigned short	s;

	nb = 0;
	s = 0;
	if (flg->h)
	{
		s = (unsigned short)va_arg(*list, unsigned int);
		return (nbr_check_flags(flg, (long long)s, ft_utoa(s)));
	}
	else if (flg->hh)
	{
		ft_putchar((unsigned char)va_arg(*list, unsigned int));
		return (1);
	}
	else if (flg->l || flg->z)
		return (unsigned_long(list, flg));
	else
	{
		nb = va_arg(*list, unsigned int);
		return (nbr_check_flags(flg, (long long)nb, ft_utoa(nb)));
	}
}

size_t	convert_diu(char *str, va_list *list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 'd')
		return (decimal_nbr(list, flg));
	else if (str[ft_strlen(str) - 1] == 'i')
		return (decimal_nbr(list, flg));
	else if (str[ft_strlen(str) - 1] == 'u')
		return (unsigned_nbr(list, flg));
	return (0);
}
