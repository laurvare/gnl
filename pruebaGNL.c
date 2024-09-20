#include <stdio.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*new_line;

	fd = open("GNL.txt", O_RDONLY);
	new_line = get_next_line(fd);
	printf("--------%s", new_line);
	free(new_line);
	new_line = get_next_line(fd);
	printf("--------%s", new_line);
	free(new_line);
	new_line = get_next_line(fd);
	printf("--------%s", new_line);
	free(new_line);

	close (fd);
	return (0);
}

