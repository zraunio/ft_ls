#include "incl/ft_ls.h"
#include <stdio.h>


// int		test_new(int ac, char **arr)
// {
// 	struct stat		buf;
// 	struct passwd	*pass;
// 	struct group	*gr;
// 	int			i = 0;
// 	int			j = 1;

// 	while (j < ac)
// 	{
// 		if (arr[j][0] == '-')
// 		{
// 			if (!(ft_strcmp(ls_options(arr[j]), arr[j]) == 0))
// 				ft_putendl("USAGE");
// 			j++;
// 		}
// 		if (lstat(arr[j], &buf) == -1)
// 		{
// 			ft_putstr("ls: ");
// 			ft_putstr(arr[1]);
// 			ft_putendl(": No such file or directory");
// 			return (0);
// 		}
// 		ft_printf("%hu\n", buf.st_mode);
// 		ft_printf("%d\n", buf.st_dev);
// 		ft_printf("%llu\n", buf.st_ino);
// 		ft_printf("links %hu\n", buf.st_nlink);
// 		ft_printf("%u\n", buf.st_uid);
// 		ft_printf("%u\n", buf.st_gid);
// 		ft_printf("%u\n", buf.st_uid);
// 		ft_printf("%d\n", buf.st_rdev);
// 		ft_printf("%u\n", buf.st_flags);
// 		ft_printf("%u\n", buf.st_gen);
// 		if (S_ISDIR(buf.st_mode))
// 			ft_putendl("a directory!");
// 		if (S_ISLNK(buf.st_mode))
// 			ft_putendl("a link!");
// 		if (!(pass = getpwuid(buf.st_uid)))
// 		{
// 			free(pass);
// 			return (0);
// 		}
// 		ft_printf("%s\n", pass->pw_dir);
// 		ft_printf("%s\n", pass->pw_gecos);
// 		ft_printf("%ld\n", pass->pw_expire);
// 		ft_printf("%s\n", pass->pw_shell);
// 		ft_printf("%ld\n", pass->pw_change);
// 		ft_printf("%u\n", pass->pw_gid);
// 		ft_printf("%s\n", pass->pw_name);
// 		ft_printf("%s\n", pass->pw_passwd);
// 		ft_memset(pass, 0, 0);
// 		if (!(gr = getgrgid(buf.st_gid)))
// 		{
// 			free(gr);
// 			return (0);
// 		}
// 		ft_printf("%u\n", gr->gr_gid);
// 		while (gr->gr_mem[i])
// 			ft_printf("member %s\n", gr->gr_mem[i++]);
// 		ft_printf("%s\n", gr->gr_name);
// 		ft_printf("%s\n", gr->gr_passwd);
// 		ft_memset(gr, 0, 0);
// 		j++;
// 	}
// 	return (0);
// }

// void	ft_treedel_postord(t_bitree *node)
// {
// 	if (node == NULL)
// 		return ;
// 	ft_treedel_postord(node->left);
// 	ft_treedel_postord(node->right);
// 	free(node);
// 	node = NULL;
// }

// void	arrelem_free(char **arr)
// {
// 	size_t	i;

// 	i = 0;
// 	if (arr == NULL)
// 		return ;
// 	while (arr[i] != NULL)
// 	{
// 		if (arr[i] != NULL)
// 			free(arr[i]);
// 		i++;
// 	}
// }

// int binary_stuff()
// {
// 	char		*arr[7];
// 	// size_t		i = 1;
// 	t_bitree	*root;

// 	if (!(arr[0] = ft_strdup("twenty")))
// 	{	
// 		ft_memdel((void**)arr);
// 		return (-1);
// 	}
// 	if (!(arr[1] = ft_strdup("second")))
// 	{	
// 		ft_memdel((void**)arr);
// 		return (-1);
// 	}	
// 	if (!(arr[2] = ft_strdup("JOHN")))
// 	{	
// 		ft_memdel((void**)arr);
// 		return (-1);
// 	}
// 	if (!(arr[3] = ft_strdup("march")))
// 	{	
// 		ft_memdel((void**)arr);
// 		return (-1);
// 	}
// 	if (!(arr[4] = ft_strdup("двадесет")))
// 	{	
// 		ft_memdel((void**)arr);
// 		return (-1);
// 	}
// 	if (!(arr[5] = ft_strdup("samodiva")))
// 	{	
// 		ft_memdel((void**)arr);
// 		return (-1);
// 	}
// 	arr[6] = NULL;
// 	if (!(root = ft_new_node(arr[0])))
// 	{
// 		ft_arr_free(arr);	
// 		ft_memdel((void*)&root);
// 		return (-1);
// 	}
// 	ft_add_node(&root, ft_new_node(arr[1]));
// 	ft_add_node(&root, ft_new_node(arr[2]));
// 	ft_add_node(&root, ft_new_node(arr[3]));
// 	ft_add_node(&root, ft_new_node(arr[4]));
// 	ft_add_node(&root, ft_new_node(arr[5]));
// 	ft_printtr_inord(root);
// 	ft_treedel_postord(root);
// 	arrelem_free(arr);
// 	return (0);
// }

void	free_args(t_lsarg *args)
{
	treedel_postord(args->file, "");
	treedel_postord(args->dir, "");
	ft_memdel((void *)&args);
}

int		main(int argc, char **argv)
{
	t_lsarg	*args;

	sort_args(&argv[1]);
	args = fill_arg((argc - 1), &argv[1]);
	read_trees(args);
	printtr_inord(args->file);
	printtr_inord(args->dir);
	free_args(args);
	return (0);
}

//gcc -Wall -Wextra -Werror -I./incl -L./libft -lft main.c options.c -o ft_ls
