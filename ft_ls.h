#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include "libft/libft.h"

int		check_dot(char *str);
int		read_in_dir(char *dir);
void		stats_file(char *file);

#endif
