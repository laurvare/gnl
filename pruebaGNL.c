#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

/*int	main(void)
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
}*/
int	main(void)
{
	#include <fcntl.h>

	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
/*int	main(void)
{
	#include <fcntl.h>

	int	i;
	int	fd;
	char	*line;

	i = 3;
	fd = open("GNL.txt", O_RDONLY);
	while (i > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
	close(fd);
	return (0);
}*/