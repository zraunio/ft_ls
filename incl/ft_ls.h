/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:14:18 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/24 13:58:36 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/incl/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define ALL 0x1
# define TIME 0x2
# define LONG 0x4
# define RECUR 0x8
# define REV 0x10
# define HELP 0x20
# define LINK 0x40
# define HUMAN 0x80
//0x100 0x200 0x400 0x800 0x1000 0x2000 etc.

# define DIR 16877
# define REG 33188
#endif
