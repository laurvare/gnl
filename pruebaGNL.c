/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:07:56 by laurvare          #+#    #+#             */
/*   Updated: 2024/07/25 21:00:38 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pruebaGNL.h"

//SI LO USO
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub1;
	size_t	final_len;
	size_t	i;
	size_t	orig;
	size_t	aux;

	i = 0;
	orig = ft_strlen(s);
	if (start > orig)
		return (ft_calloc (1, 1));
	aux = ft_strlen(s + start);
	final_len = len;
	if (aux < len)
		final_len = aux;
	sub1 = ft_calloc (final_len + 1, 1);
	if (sub1 == NULL)
		return (NULL);
	while (i < final_len)
	{
		sub1[i] = s[start];
		i++;
		start++;
	}
	return (sub1);
}

static char	*read_from_file(int fd, char *str)
{
	int		n_bytes;
	char	*buffer;

	if (fd == -1)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	n_bytes = 1;
	while (n_bytes != 0)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[n_bytes] = 0;
		str = ft_strjoin(str, buffer);
		if (n_bytes == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		if (ft_strchr(str, '\n') != 0)
			break ;
	}
	return (str);
}
char	*delete_line(char *str)
{
	int i;
	char *rest;
	
	i = ft_strchr(str,'\n') - str + 1;
	rest = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	str = rest;
	return(rest);
}

char	*get_line(char *str)
{
	int i;
	char *line;
	
	i = ft_strchr(str,'\n') - str + 1;
	line = ft_substr(str, 0, i);
	return(line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char 		*line;

	if (str == NULL)
		str = malloc(1);
	str = read_from_file(fd, str);
	line = get_line(str);
	str = delete_line(str);
	return (line);
}


int	main(void)
{
	int		fd;
	char	*new_line;

	fd = open("Desktop/GNL.txt", O_RDONLY);
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








// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pruebaGNL.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/07/17 13:07:56 by laurvare          #+#    #+#             */
// /*   Updated: 2024/07/25 18:07:31 by laurvare         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include "pruebaGNL.h"

// void 	read_join(int *n_bytes, int fd, char *buffer, char *str)
// {
// 	*n_bytes = read(fd, buffer, 3);
// 	str = ft_strjoin(str, buffer);
// 	if (*n_bytes == -1)
// 	{
// 		free(buffer);
// 		free(str);
// 		return ;
// 	}
// 	if (ft_strchr(str, '\n') != 0)
// 		return ;
// }

// static char	*read_from_file(int fd, char *s_str)
// {
// 	int		n_bytes;
// 	char	*buffer;
// 	char	*str;

// 	if (fd == -1)
// 		return (NULL);
// 	buffer = calloc((3 + 1), sizeof(char));
// 	if (buffer == NULL)
// 		return (NULL);
// 	str = malloc(1);
// 	n_bytes = 1;
// 	while (n_bytes != 0)
// 	{
// 		read_join(&n_bytes, fd, buffer, str);
// 		if (n_bytes == -1)
// 			return NULL;
// 		if (ft_strchr(str, '\n') != 0)
// 			break ;
// 	}
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*str;
// 	//char 		*line;

// 	str = NULL;
// 	str = read_from_file(fd, str);
// 	return (str);
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*new_line;

// 	fd = open("Desktop/GNL.txt", O_RDONLY);
// 	new_line = "";
// 	new_line = get_next_line(fd);
// 	printf("%s\n", new_line);
// 	new_line = get_next_line(fd);
// 	printf("%s\n", new_line);
// 	free(new_line);
// 	close (fd);
// 	return (0);
// }
