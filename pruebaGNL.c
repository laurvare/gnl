/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:07:56 by laurvare          #+#    #+#             */
/*   Updated: 2024/07/17 14:50:01 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd) // Devuelve una linea de caracteres incluido con '\n' ó '\0' si estamos en la última línea.
{
	char	*buffer;
	char 	*almacen_de_caracteres;
	int		n_bytes;

	if (fd == -1)
		return (NULL);
	n_bytes = read(fd, buffer, 50);
	if (n_bytes == -1)
		return (NULL);
	almacen_de_caracteres = malloc(n_bytes + 1);
	
	
	
	
	
	
	
	
	almacen_de_caracteres [n_bytes] = '\0';
	printf("esto es fd: %d\n", fd);
	printf("hemos leido: %s\n", buffer);
	printf("num Bytes: %d\n", n_bytes);
/*
	n_bytes = read (fd, buffer, 50);
	if (n_bytes == -1)
		return (NULL);
	buffer = malloc(n_bytes + 1);
	buffer [n_bytes] = '\0';
	printf("esto es fd: %d\n", fd);
	printf("hemos leido: %s\n", buffer);
	printf("num Bytes: %d\n", n_bytes);*/
 	return (NULL);
}

int main()
{
	int fd;
    fd = open("Desktop/GNL.txt", O_RDONLY);

	get_next_line(fd);
	
	close (fd);
	return (0);
}
