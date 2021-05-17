/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:14:18 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/17 17:44:28 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/incl/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/dir.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <time.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>

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
# define SORT_S 0x200
//0x400 0x800 0x1000 0x2000 etc.

# define MAX_LNG 257
# define OPTIONS "lSarhtR"

typedef struct		s_data
{
	char			*path;
	char			*name;
	size_t			st_ino;
	int				st_mode;
	int				nlink;
	unsigned int	*st_uid;
	unsigned int	*st_gid;
	unsigned int	st_uid_nbr;
	unsigned int	st_gid_nbr;
	char			st_gid_grname[MAX_LNG];
	char			st_uid_pwname[MAX_LNG];
	long			m_time;
	size_t			size;
	size_t			blksize;
	int				blocks;
	struct group	grp;
	struct passwd	pwd;
	size_t			dev_t;
	struct s_data	*next;
}					t_data;

typedef struct	s_lsarg
{
	t_data		*files;
	t_data		*dirs;
	size_t		flg;
}				t_lsarg;

size_t		ls_options(char *str, size_t flgs);
int			printerr(char *str, int error);
void		free_list(t_data *lst);
void		free_in_list(t_data *lst);
void		column_width(t_data *lst, int w[7]);
void		sort_args(size_t ac, char **av);
void		create_lists(t_lsarg *ls, char **av);
void		lst_split(t_data *src, t_data **a, t_data **b);
void		get_data(t_data *lst);
void		output_base(t_lsarg	*lst);
void		print_simple(t_data *data);
void		print_long(t_lsarg *args, t_data *lst);
void		recursive(t_lsarg *arg, t_data *dir, size_t flgs);
char		print_acl(char *path);
void		print_time(t_data *lst);
void		read_dir(t_lsarg *arg,t_data *lst, size_t flgs);
void		read_rec(t_lsarg *arg, char *str, size_t flgs);
char		*create_path(const char *dir, const char *name);
t_data		*new_node(char *str);
t_data		*sort_base(t_data *lst, size_t flgs);
t_data		*lst_sort_time(t_data **head);
t_data		*lst_sort_size(t_data **head);
t_data		*lst_sort_basic(t_data **lst);
#endif
