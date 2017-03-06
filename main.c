#include "ft_ls.h"

/*
--	Checks if there are a hidden file
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
				ft_putstr(file->d_name);
		}
		closedir(rep);	
	}
	return (1);
}

/*
**	Give stats of a file
*/

int		stats_file(char *file)
{
	struct stat fileStat;

	if (file == NULL)
		printf("no file");
	if (stat(file, &fileStat) < 0)
		return (0);
	ft_putstr("Taille du fichier : ");
	ft_putnbr(fileStat.st_size);
}

int main (int argc, char **argv)
{
	//read_in_dir(argv[1]);

	stats_file(argv[1]);
	return (1);
}