/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:14:18 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/15 13:37:05 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>

# define ALL 0x1
# define TIME 0x2
# define LONG 0x4
# define RECUR 0x8
# define REV 0x16
# define HELP 0x32
# define LINK 0x64
//0x128 0x256 0x512 0x1024 0x2048 0x4096 0x8192

#endif
