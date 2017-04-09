#include "ft_ls.h"

/*
**	Checks if there are a hidden file
*/

int		check_dot(char *str)
{
	if (str[0] == '.')
		return (1);
	if ((str[0] == '.') && (str[1] == '.'))
		return (1);
	else
		return (0);
}

/*
**	Reads in a dir but avoid hidden files
*/

int		read_in_dir(char *dir)
{
	DIR *rep;
	struct dirent* file = NULL;
	
	if (dir == NULL)
		rep = opendir(".");
	else
	{
		if (rep == NULL)
		{
			perror("");
			return (0);
		}
		rep = opendir(dir);
	}
	else
	{
		while ((file = readdir(rep)) != NULL)
		{
			if (check_dot(file->d_name) != 1)
				stats_file(file->d_name);
		}
		closedir(rep);	
	}
	return (1);
}

// int open_actual_dir()
// {
// 	DIR *rep;
// 	char cwd[1024];
// 	struct dirent* file = NULL;
	

//     rep = opendir(".");
//     //SORT
//     while ((file = readdir(rep)) != NULL)
// 	{
// 		if (check_dot(file->d_name) != 1)
// 			stats_file(file->d_name);
// 	}
//     closedir(rep);
// 	return (1);
// }

/*
**	Give permissions of a file
*/

void 	print_permissions(char *file, struct stat fileStat) 
{
	ft_putstr( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    ft_putstr( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
}

void	stats_file(char *file)
{
	struct stat fileStat;
	struct group *grp;
	struct passwd *pwd;

	if (file == NULL)
		printf("no file");
	stat(file, &fileStat);
	print_permissions(file, fileStat);
	ft_putstr("  ");
	ft_putnbr(fileStat.st_nlink);
	ft_putchar(' ');


	pwd = getpwuid(fileStat.st_uid);
	ft_putstr(pwd->pw_name);
	ft_putstr("  ");
	grp = getgrgid(fileStat.st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr("    ");
	ft_putnbr(fileStat.st_size);
	ft_putstr("    ");
	ft_putstr(file);
	ft_putchar('\n');
}

/*struct stat
{
dev_t st_dev;  Périphérique
ino_t st_ino; Numéro i-noeud 
mode_t st_mode;  Protection 
nlink_t st_nlink; /Nb liens matériels 
uid_t st_uid; UID propriétaire 
gid_t st_gid; / GID propriétaire 
dev_t st_rdev; / Type périphérique *
off_t st_size; /Taille totale en octets *
unsigned long st_blksize; /Taille de bloc pour E/S *
unsigned long st_blocks; /Nombre de blocs alloués *
time_t st_atime; / Heure dernier accès *
time_t st_mtime; / Heure dernière modification *
time_t st_ctime; / Heure dernier changement 
*/

int opt_occur(char contender, char *sion)
{
	int i;

	i = 0;
	while (sion[i])
	{
		if (sion[i] == contender)
			return (1);
	}
	return (0);
}

t_star analyzer(char **opt, t_star all)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (opt[i][j] == '-')
	{
		j++;
		while (ft_isalpha(opt[i][j]))
		{	
			if ((opt_occur(opt[i][j]) == 0))
			{
				sion[k] = opt[i][j];
				k++;
			}
			j++;
		}	
	}
	// else
	// {
	// 	file_parser()
	// }
	return (all);
}

t_star init_star(t_star all)
{
	if (!(all = (t_star)malloc(sizeof(all))))
		return (NULL);
	if (!(all.file) = (char **)malloc(sizeof(char **)))
		return (NULL);
	return (all);
}

int main (int argc, char **argv)
{
	t_star all;

	if ((all = init_star(all)) == NULL)
		return (NULL);
	all = analyzer(argv, all);
	//read_in_dir(argv[1]);
	//read_in_dir(argv[1]);
	//stats_file(argv[1]);
	return (0);
}