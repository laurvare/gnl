/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaGNL_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:12:26 by laurvare          #+#    #+#             */
/*   Updated: 2024/07/25 21:01:37 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pruebaGNL.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;
	size_t	total;

	total = (nmemb * size);
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

//SI LO USO
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//NO USAR
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	max_chars;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	max_chars = dstsize - dst_len - 1;
	while (i < src_len && i < max_chars)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

//SI LO USO
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*strconcat;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	strconcat = malloc (total_len + 1);
	if (strconcat == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		strconcat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		strconcat[i] = s2[j];
		i++;
		j++;
	}
	strconcat[i] = '\0';
	return (strconcat);
}

//SI LO USO
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

//ENSEÑO A LIBERAR
static	void	ft_free_strjoin(char **file, char **buffer)
{
	char	*dst;
	size_t	size;
	char	*temp;
	size_t	i;

	size = ft_strlen(*file) + ft_strlen(*buffer) + 1;
	dst = malloc(size);
	i = 0;
	if (!dst)
		return ;
	while ((i + 1) < size && size && (*file)[i])
	{
		dst[i] = ((*file)[i]);
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	ft_strlcat(dst, *buffer, size);
	temp = dst;
	if (!temp)
		return ;
	free(*file);
	*file = temp;
}
