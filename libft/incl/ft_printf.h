/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:44:34 by zraunio           #+#    #+#             */
/*   Updated: 2021/04/22 16:36:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>

typedef struct s_print
{
	char		**vars;
	char		*info_str;
	va_list		*arg;
	int			size;
}				t_print;

/*
** vars - variables given in format; preci(sion) in char form
** info_str - the content of "format" if % is present
** arg: list of arguments using stdarg lib
** size - data used for return value for ft_printf
*/

typedef struct s_flags
{
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		lng_f;
	int		left;
	int		zero;
	int		sign;
	int		spc;
	int		hash;
	int		z;
	char	padd_c;
	char	cnvrsn;
	size_t	decimal;
	size_t	min_wi;
}				t_flags;

size_t			ft_convert(char *str, va_list *list, t_flags *flg);
size_t			parse(char *str, va_list *list);
size_t			padd_nbr(char *str, t_flags *flg);
size_t			convert_oxx(char *str, va_list *list, t_flags *flg);
size_t			precision_base(char *out, t_flags *flgs);
size_t			convert_diu(char *str, va_list *list, t_flags *flg);
size_t			convert_spc(char *str, va_list *list, t_flags *flg);
size_t			nbr_check_flags(t_flags *flgs, long long nb, char *str);
size_t			float_nbr(va_list *list, t_flags *flg);
size_t			ft_print(t_print *print);
int				ft_printf(const char *format, ...);

#endif
