/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:55:13 by laurvare          #+#    #+#             */
/*   Updated: 2024/09/25 15:24:04 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		fd;
	char	*line;

	fd = open("GNL.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		if (line)
		{
			free(line);
			line = NULL;
		}
		line = get_next_line(fd);
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