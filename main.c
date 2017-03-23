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
		rep = opendir(dir);
	if (rep == NULL)
	{
		perror("");
		return (0);
	}
	else
	{
		while ((file = readdir(rep)) != NULL)
		{
			if (check_dot(file->d_name) != 1)
			{
				ft_putstr(file->d_name);
				ft_putchar('\n');
			}
		}
		closedir(rep);	
	}
	return (1);
}

/*
**	Give stats of a file
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

int		stats_file(char *file)
{
	struct stat fileStat;

	if (file == NULL)
		printf("no file");
	if (stat(file, &fileStat) < 0)
		return (0);
	print_permissions(file, fileStat);
	ft_putchar('\t');
	ft_putnbr(fileStat.st_nlink);
	ft_putchar(' ');
	//ft_putstr(getpwuid());

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



int main (int argc, char **argv)
{
	int i;

	i = 0;

	//read_in_dir(argv[1]);


	stats_file(argv[1]);
	return (0);
}