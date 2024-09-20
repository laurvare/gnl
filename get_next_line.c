/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:07:56 by laurvare          #+#    #+#             */
/*   Updated: 2024/09/20 21:04:13 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_line(char *str)
{
	int		i;
	char	*rest;

	i = (ft_strchr(str, '\n') - (char *)str) + 1;
	rest = ft_substr(str, i, (ft_strlen(str) - i));
	free(str);
	if (!rest)
		return (NULL);
	str = rest;
	return (str);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = (ft_strchr(str, '\n') - str) + 1;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_from_file(int fd, char *str)
{
	int		n_bytes;
	char	*buffer;

	if (fd == -1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	n_bytes = 1;
	while (n_bytes != 0 && !ft_strchr(str, '\n'))
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[n_bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (n_bytes == -1 || n_bytes == 0)
			return (free(str), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_from_file(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	if (!line)
		return (free(str), NULL);
	str = delete_line(str);
	if (!str)
		return (free(line), NULL);
	return (line);
}

/*int	main(void)
{
	#include <fcntl.h>
	#include <stdio.h>

	int		fd;
	char	*line;

	fd = open("GNL.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("--------%s", line);
	free(line);
	line = get_next_line(fd);
	printf("--------%s", line);
	free(line);
	line = get_next_line(fd);
	printf("--------%s", line);
	free(line);

	close (fd);
	return (0);
}*/

