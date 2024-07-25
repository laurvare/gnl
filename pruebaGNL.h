/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaGNL.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:01:29 by laurvare          #+#    #+#             */
/*   Updated: 2024/07/25 20:05:54 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRUEBAGNL_H
# define PRUEBAGNL_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
# define BUFFER_SIZE 5

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
#endif