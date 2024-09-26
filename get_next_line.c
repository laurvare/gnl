/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:07:56 by laurvare          #+#    #+#             */
/*   Updated: 2024/09/26 19:11:30 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_line(char *str)
{
	int		i;
	char	*rest;

	if (!str || !ft_strchr(str, '\n'))
		return (free(str), NULL);
	i = (ft_strchr(str, '\n') - (char *)str) + 1;
	rest = ft_substr(str, i, (ft_strlen(str) - i));
	if (!rest)
		return (free(str), NULL);
	free(str);
	str = rest;
	return (str);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while ((str)[i])
		if ((str)[(i)++] == '\n')
			break ;
	if (i > 0)
	{
		line = ft_substr(str, 0, i);
		if (!line)
			return (NULL);
	}
	else
		return (NULL);
	return (line);
}

char	*read_from_file(int fd, char *str)
{
	int		n_bytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (free(str), NULL);
	n_bytes = 1;
	while (n_bytes > 0 && !ft_strchr(str, '\n'))
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes < 0)
			return (free(buffer), free(str), NULL);
		buffer[n_bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	free(buffer);
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
		return (free(str), (str = NULL), NULL);
	str = delete_line(str);
	return (line);
}
