#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int		check_dot(char *str)
{
	if (str[0] == '.')
		return (1);
	if ((str[0] == '.') && (str[1] == '.'))
		return (1);
	else
		return (0);
}

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
				printf("%s\n", file->d_name);
		}
		closedir(rep);	
	}
	return (1);

}

int main (int argc, char **argv)
{
	read_in_dir(argv[1]);
	return (1);
}