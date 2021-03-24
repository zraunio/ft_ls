#include "incl/ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	// size_t i;

	// size_t	arr[] = {ALL, TIME, LONG, LINK, 0};
	// size_t	add[] = {REV, RECUR, HELP, HUMAN, 0};

	// i = ft_orfill_bit(i, arr);
	// ft_print_bits(i, 64);
	// ft_putchar('\n');
	// i = ft_oradd_bit(i, add);
	// ft_print_bits(i, 64);
	struct stat		buf;
	struct passwd	*pass;
	struct group	*gr;
	int			i = 0;
//	int			j;

	if (argc)
	{
	}
	if (stat(argv[1], &buf) == -1)
	{
		ft_putstr("ls: ");
		ft_putstr(argv[1]);
		ft_putendl(": No such file or directory");
		return (0);
	}
	ft_printf("%hu\n", buf.st_mode);
	ft_printf("%d\n", buf.st_dev);
	ft_printf("%llu\n", buf.st_ino);
	ft_printf("links %hu\n", buf.st_nlink);
	ft_printf("%u\n", buf.st_uid);
	ft_printf("%u\n", buf.st_gid);
	ft_printf("%u\n", buf.st_uid);
	ft_printf("%d\n", buf.st_rdev);
	ft_printf("%u\n", buf.st_flags);
	ft_printf("%u\n", buf.st_gen);
	if (!(pass = getpwuid(buf.st_uid)))
	{
		free(pass);
		return (0);
	}
	ft_printf("%s\n", pass->pw_dir);
	ft_printf("%s\n", pass->pw_gecos);
	ft_printf("%ld\n", pass->pw_expire);
	ft_printf("%s\n", pass->pw_shell);
	ft_printf("%ld\n", pass->pw_change);
	ft_printf("%u\n", pass->pw_gid);
	ft_printf("%s\n", pass->pw_name);
	ft_printf("%s\n", pass->pw_passwd);
	ft_memset(pass, 0, 0);
	if (!(gr = getgrgid(buf.st_gid)))
	{
		free(gr);
		return (0);
	}
	ft_printf("%u\n", gr->gr_gid);
	while (gr->gr_mem[i])
		ft_printf("member %s\n", gr->gr_mem[i++]);
	ft_printf("%s\n", gr->gr_name);
	ft_printf("%s\n", gr->gr_passwd);
	ft_memset(gr, 0, 0);
	return (0);
}
