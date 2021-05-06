/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:14:18 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/06 12:15:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/incl/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define MALLOC_ERR 1
# define OPTION_ERR 2
# define USAGE 3
# define ERR 4

# define ALL 0x1
# define TIME 0x2
# define LONG 0x4
# define RECUR 0x8
# define REV 0x10
# define HELP 0x20
# define SIZE 0x40
# define HUMAN 0x80
# define LINES 0x100
//0x200 0x400 0x800 0x1000 0x2000 etc.

# define DIR 16877
# define REG 33188
# define OPTIONS "lsxarhtR"

typedef struct		s_data
{
	char			*path;
	int				st_mode;
	int				nlink;
	unsigned int	*st_uid;
	unsigned int	*st_gid;
	long			m_time;
	int				blocks;
	struct group	grp;
	struct passwd	pwd;

	struct s_data	*left;
	struct s_data	*right;
}					t_data;

typedef struct		s_lsarg
{
	t_data			*file;
	t_data			*dir;
	size_t			optns;
}					t_lsarg;

size_t	ls_options(char *str, size_t flgs);
void	sort_args(char **av);
int		ft_printerr(char *str, int error);
void	treedel_postord(t_data *node, char *str);
t_lsarg	*fill_arg(int ac, char **av);
void 	printtr_inord(t_data *node);
#endif
