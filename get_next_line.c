/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:07:56 by laurvare          #+#    #+#             */
/*   Updated: 2024/09/20 17:06:05 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd, char *str)
{
	int		n_bytes;
	char	*buffer;

	if (fd == -1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	n_bytes = 1;
	while (n_bytes != 0)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == -1)
			return (free(buffer), free(str), NULL);
		buffer[n_bytes] = 0;
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
		if (ft_strchr(str, '\n') != 0)
			break ;
	}
	free(buffer);
	return (str);
}

char	*delete_line(char *str)
{
	int		i;
	char	*rest;

	i = ft_strchr(str, '\n') - str + 1;
	rest = ft_substr(str, i, ft_strlen(str) - i);
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

	i = ft_strchr(str, '\n') - str + 1;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == NULL)
		str = malloc(1);
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
