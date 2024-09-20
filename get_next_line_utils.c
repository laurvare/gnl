/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:12:26 by laurvare          #+#    #+#             */
/*   Updated: 2024/09/20 20:52:38 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*strconcat;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if(!s1 || !s2)
		return (NULL);
	strconcat = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (strconcat == NULL)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i] != '\0')
		strconcat[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		strconcat[i++] = s2[j];
	strconcat[i] = '\0';
	free(s1);
	return (strconcat);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub1;
	size_t	final_len;
	size_t	i;
	size_t	orig;
	size_t	aux;

	i = 0;
	if (!s)
		return (NULL);
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
		sub1[i++] = s[start++];
	return (sub1);
}
